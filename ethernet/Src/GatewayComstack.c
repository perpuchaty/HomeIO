/**@file modules/Ethernet/GatewayComstack.cpp
 * @brief Ethernet communication TCP / ICMP / ARP / IPv4

 * @date 09/10/2019
 * @version lwIP 2.1.2 released
 * @site http://savannah.nongnu.org/projects/lwip/
 * @source lwIP - A Lightweight TCP/IP stack
 *

 *   (c) 2019 AAAA / AAAA
 * @endcode
 */

/** @defgroup gatewayComstackEthernet Ethernet Gateway Comstack
 *  @brief Ethernet module using the lwIP library and the ENC424J600 ethernet chip
 *
 * Usage :
 * ----------------
 * - Initialize the Ethernet communication by calling Gateway_Initialize_Ethernet(), it will enable the interruption for Ethernet even if the Ethernet port isn't plug in.
 * - Initialize the lwIP library to format all your packets with : Gateway_Initialize_lwIP() . This function must be called once the combox configuration have been set (EEPROM memory with  CONFIG_MGR_Init() )
 *
 * Once both initialization are done :
 * - call in the main loop program : Gateway_MainFunction()
 */

/** \addtogroup gatewayComstackEthernet
 * @{
 */


// ==================================================
//    INCLUDE
// ==================================================
#include "GatewayComstack.h"

#include "ethernet.h"
#include "lib.h"

#include <string.h>

// lwIP include
#include "lwip/init.h"
#include "lwip/netif.h"
#include "lwip/etharp.h"
#include "lwip/ethip6.h"
#include "lwip/ip_addr.h"
#include "lwip/snmp.h"
#include "lwip/pbuf.h"
#include "lwip/tcp.h"
#include "lwip/timeouts.h"
#include "lwip/ip4_addr.h"
#include "lwip/netif.h"
// ==================================================
//     EXTERN VARIABLES
// ==================================================
unsigned char MyMACAddr[6] = {0xa1,0xb1,0xc1,0xd1,0xe1,0xf1};
unsigned char MyIPAddr[4] = {192,168,178,112};
unsigned char GatewayIPAddr[4] = {192,168,178,1};
unsigned char MaskIPAddr[4] = {255,255,255,0};

// ==================================================
//     STATIC FUNCTION DECLARATION
// ==================================================

static err_t netif_init_	(struct netif *netif) ;
static err_t netif_output_	(struct netif *netif , struct pbuf *p) ;
static void  netif_input_	(u16_t eth_data_count , const void * eth_data);

static err_t tcp_close_	 (struct tcp_pcb *pcb) ; /* close tcp connection */
static err_t tcp_accept_ (void * arg , struct tcp_pcb* newpcb , err_t err); /* create new connection and link callback functions */
static err_t tcp_recv_ 	 (void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err) ; /*received packet -> new data for lowa protocol*/

/* TODO : In the program but for now those functions are not used */
static void  tcp_err_ 	(void *arg, err_t err);
static err_t tcp_poll_  (void *arg, struct tcp_pcb *pcb) ;
static err_t tcp_sent_ 	( void * arg , struct tcp_pcb * tpcb , u16_t len );  /* called when data has been acknowledged by the last ACK */


// ==================================================
//     STATIC VARIABLES
// ==================================================
static struct netif 	my_netif ;
static struct tcp_pcb* 	my_pcb ;

// ==================================================
//     GLOBAL VARIABLES
// ==================================================
unsigned char packetReceived[MAX_FRAMELEN];

// ==================================================
//     FUNCTION
// ==================================================

/**
 * Initialize the ENC424J600 Ethernet chip.
 * In this function , the MAC address global variable (MyMACAddr) will be set
 * with the Ethernet chip hardware MAC address (unique)
 *
 * @param none
 * @return none
 *
 * called in sub_main_InitServices() [sub_main.cpp]
 */
void
Gateway_Initialize_Ethernet(void)
{
	Ethernet_Init(MyMACAddr);
}

/**
 * Initialize the lwIP program, to process the received and transferred packet
 * - Handle timeouts
 * - Initialize the LwIP stack
 * - Convert IP address and set netif (network) with :
 * 		- const ip4_addr_t *ipaddr
 * 		- const ip4_addr_t *netmask
 * 		- const ip4_addr_t *gw
 * - Initialize TCP
 *
 * @param none
 *
 * @return HAL_OK if the initialization is correct
 * @return HAL_ERROR if the initialization is incorrect
 *
 * called in sub_main_InitServices() [sub_main.cpp]
 */
HAL_StatusTypeDef
Gateway_Initialize_lwIP(void){
	/* Handle timeouts for NO_SYS==1 */
	sys_check_timeouts();

	/* Initialize the LwIP stack */
	lwip_init();  /* if NO_SYS == 1 */

	/* Convert IP address into ip4addr */
	char ascii_my_ip[15], ascii_gw_ip[15] , ascii_mask_ip[15] ;
	sprintf(ascii_my_ip,"%d.%d.%d.%d",MyIPAddr[0],MyIPAddr[1],MyIPAddr[2],MyIPAddr[3]);
	sprintf(ascii_gw_ip,"%d.%d.%d.%d",GatewayIPAddr[0],GatewayIPAddr[1],GatewayIPAddr[2],GatewayIPAddr[3]);
	sprintf(ascii_mask_ip,"%d.%d.%d.%d",MaskIPAddr[0],MaskIPAddr[1],MaskIPAddr[2],MaskIPAddr[3]);
	ip4_addr_t myIP , gwIP , maskIP ;
	if ( ip4addr_aton(ascii_my_ip,&myIP) == 0  ) return HAL_ERROR ;
	if ( ip4addr_aton(ascii_gw_ip,&gwIP) == 0  ) return HAL_ERROR ;
	if ( ip4addr_aton(ascii_mask_ip,&maskIP) == 0  ) return HAL_ERROR ;

	/* Add our netif to LwIP (netif_add calls our driver initialization function )  */
	netif_add(&my_netif, &myIP, &maskIP, &gwIP, NULL, netif_init_, netif_input);
	netif_set_default(&my_netif);
	netif_set_link_up(&my_netif);
	netif_set_up(&my_netif);

	/* Initialize tcp */
	if (( my_pcb = tcp_new()) == NULL )
		return HAL_ERROR  ;
	my_pcb->flags |= TF_NODELAY;
	if ( tcp_bind(my_pcb,IP_ADDR_ANY,502) != ERR_OK) /* port = 0 => selects an available port */
		return HAL_ERROR;
	if ( (my_pcb = tcp_listen(my_pcb)) == NULL )
		return HAL_ERROR;
	tcp_accept(my_pcb,tcp_accept_);
	tcp_bind_netif(my_pcb, &my_netif);  /* bind my_pcb to my_netif */

//	#if CONSOLE_ENABLE_DEBUG_ETHERNET == CONSOLE__OPTION__ENABLED
//		CONSOLE("[lwIP] My IP : %s \r\n",ascii_my_ip);
//		CONSOLE("[lwIP] Gateway IP : %s \r\n",ascii_gw_ip);
//		CONSOLE("[lwIP] Mask IP : %s \r\n",ascii_mask_ip);
//		CONSOLE("[lwIP] Netif init done \r\n");
//		CONSOLE("[lwIP] TCP   init done \r\n");
//	#endif

	return HAL_OK ;
}


HAL_StatusTypeDef
Gateway_Initialize_lwIP_mqtt(void){

	/* Handle timeouts for NO_SYS==1 */
	sys_check_timeouts();

	/* Initialize the LwIP stack */
	lwip_init();  /* if NO_SYS == 1 */

	/* Convert IP address into ip4addr */
	char ascii_my_ip[15], ascii_gw_ip[15] , ascii_mask_ip[15] ;
	sprintf(ascii_my_ip,"%d.%d.%d.%d",MyIPAddr[0],MyIPAddr[1],MyIPAddr[2],MyIPAddr[3]);
	sprintf(ascii_gw_ip,"%d.%d.%d.%d",GatewayIPAddr[0],GatewayIPAddr[1],GatewayIPAddr[2],GatewayIPAddr[3]);
	sprintf(ascii_mask_ip,"%d.%d.%d.%d",MaskIPAddr[0],MaskIPAddr[1],MaskIPAddr[2],MaskIPAddr[3]);
	
	ip4_addr_t myIP , gwIP , maskIP ;
	if ( ip4addr_aton(ascii_my_ip,&myIP) == 0  ) return HAL_ERROR ;
	if ( ip4addr_aton(ascii_gw_ip,&gwIP) == 0  ) return HAL_ERROR ;
	if ( ip4addr_aton(ascii_mask_ip,&maskIP) == 0  ) return HAL_ERROR ;
	// ip4_addr_set_zero(&gwIP);
	// ip4_addr_set_zero(&myIP);
	// ip4_addr_set_zero(&maskIP);

	/* Add our netif to LwIP (netif_add calls our driver initialization function )  */
	netif_add(&my_netif, &myIP, &maskIP, &gwIP, NULL, netif_init_, netif_input);
	netif_set_default(&my_netif);
	netif_set_up(&my_netif);

	return HAL_OK;
}
/**
 * This function must be called in the main loop! Received messages through Ethernet will
 * be processed here, to be send to the lwIP library.
 * The system timeout will be called periodically in the loop.
 *
 * @param none
 *
 * @return none
 *
 * called in SUB_MAIN() [sub_main.cpp]
 */
void
Gateway_MainFunction()
{
	sys_check_timeouts();  /* must be called periodically from your main loop */
	int len = ENC28J60_PacketReceive(512, packetReceived);

	if(len > 0)
	{
		#if CONSOLE_ENABLE_DEBUG_ETHERNET == CONSOLE__OPTION__ENABLED
			//CONSOLE("[lwIP] Receive packet %s \r\n",packetReceived);
		#endif
		netif_input_(len, packetReceived); /* process the received packet */
	}
}

/**
 * This function send TCP packet on the network when ever it is called if
 * the connection is established
 *
 * @param arg message to send
 * @param len size of message
 *
 * @return HAL_OK if successful
 * @return HAL_ERROR if the message couldn't be send and TCP close
 *
 * called in LOWA_MGR_Main_Loop() [lowaProtocol.c]
 */
HAL_StatusTypeDef
TCPSend (const void * arg , int len){
	/* tcp_sndbuf returns the number of bytes of space available in the output queue  */
	if ( len > tcp_sndbuf(my_pcb) ) return HAL_ERROR ; /* check if enough space */
	/* write data for sending (but does not send it immediately) */
	// TCP_WRITE_FLAG_COPY: indicates whether the new memory should be allocated for the data to be copied into.
	// TCP_WRITE_FLAG_MORE: indicates that more data follows. (doesn't work)
	if ( tcp_write(my_pcb, arg, len, TCP_WRITE_FLAG_COPY) == ERR_MEM ) goto err ; /* ERR_MEM : application should wait until some of the currently enqueued data has been successfully received */
	if ( tcp_output(my_pcb) != ERR_OK ) goto err ; /* forces all enqueued data to be sent now */
	tcp_sent(my_pcb,tcp_sent_); /* callback function when ACK of data send is received */
//	#if CONSOLE_ENABLE_DEBUG_ETHERNET == CONSOLE__OPTION__ENABLED
//		CONSOLE("[lwIP -> TCP Send ] %s \r\n",arg);
//    #endif
	return HAL_OK;

	err :
		tcp_close_(my_pcb);
		return HAL_ERROR ;
}

// ==================================================
//     STATIC FUNCTIONS
// ==================================================

/**
 * This function initialize the network setup :
 * - maximum transfer unit in bytes : 255
 * - flags : NETIF_FLAG_BROADCAST | NETIF_FLAG_ETHARP | NETIF_FLAG_ETHERNET
 * - set the MAC address
 * - name of network
 *
 * The callback functions are associated to the right declared functions :
 * - linkoutput : netif_output_() (called to send packet on interface => Ethernet chip)
 * - output : etharp_output() (for Ethernet physical layer)
 *
 * @param netif
 *
 * @return ERR_OK if successful
 *
 * called in Gateway_Initialize_lwIP() [GatewayComstack.cpp]
 */
static err_t
netif_init_(struct netif *netif)
{
  netif->name[0]='M';  // TODO
  netif->name[1]='0';  // TODO
  netif->linkoutput = netif_output_;  	/* This function is called by ethernet_output() when it wants to send a packet on the interface. */
  netif->output     = etharp_output; 	/* For ethernet physical layer, this is usually etharp_output() */
  //netif->output_ip6 = NULL ; 			/*This function is called by the IPv6 module when it wants to send a packet on the interface. [ethip6_output;]*/
  netif->mtu        = 255 ; 			/*maximum transfer unit (in bytes)  */
  netif->flags      = NETIF_FLAG_BROADCAST | NETIF_FLAG_ETHARP | NETIF_FLAG_ETHERNET ;
  MIB2_INIT_NETIF(netif, snmp_ifType_ethernet_csmacd, 100000000);
  SMEMCPY(netif->hwaddr, MyMACAddr, sizeof(netif->hwaddr));
  netif->hwaddr_len = sizeof(netif->hwaddr);
  return ERR_OK;
}

/**
 *  This function is called by ethernet_output() in the LwIP library
 *  when it wants to send a packet on the interface using the ENC424J600
 *  Ethernet chip
 *
 * @param netif
 * @param p main packet buffer
 *
 * @return ERR_OK if successful
 * @return ERR_ARG if packet to send too long or incorrect
 *
 * called in the LwIP library by netif
 */
static err_t
netif_output_(struct netif *netif , struct pbuf *p){
	/* Send buffer with Ethernet Chip ENC424  */
	struct pbuf *q;
	for (q = p; q != NULL; q = q->next) {
	    /* Send the data from the pbuf to the interface, one pbuf at a time. The size of the data in each pbuf is kept in the ->len variable. */
		if (q->len > MAX_LEN_TRAME_TO_SEND ) return ERR_ARG  ;
		ENC28J60_PacketSend(q->len, (unsigned char*)q->payload); /* send data */
//		#if CONSOLE_ENABLE_DEBUG_ETHERNET == CONSOLE__OPTION__ENABLED
//	    	CONSOLE("[lwIP]  Sending packet : payload : %s size : %d \r\n",q->payload, q->len);
//        #endif
	}

    /* Update SNMP stats (only if you use SNMP) */
	LINK_STATS_INC(link.recv);
    MIB2_STATS_NETIF_ADD(netif, ifinoctets, p->tot_len);
    if (((u8_t*)p->payload)[0] & 1) {
      MIB2_STATS_NETIF_INC(netif, ifinucastpkts);
    } else {
    	MIB2_STATS_NETIF_INC(netif, ifinnucastpkts);
    }
	return ERR_OK;
}

/**
 * This function process the receive packet using the LwIP library, with
 * the right protocol
 *
 * @param eth_data_count length of data
 * @param eth_data packet received
 *
 * @return none
 *
 * called in Gateway_MainFunction()[GatewayComstack.cpp]
 */
static void
netif_input_(u16_t eth_data_count , const void * eth_data)
{
  /* Allocate pbuf from pool (avoid using heap in interrupts) */
  struct pbuf* p = pbuf_alloc(PBUF_RAW, eth_data_count, PBUF_POOL);

  if(p != NULL) {
	  /* Copy ethernet frame into pbuf */
	  if ( pbuf_take(p, eth_data, eth_data_count)!= ERR_OK ) {
		  /* input packet error */
	  }
	  /* Check for received frames, feed them to lwIP */
	  if( my_netif.input(p,&my_netif) != ERR_OK ){
		  /* input packet error */
		  pbuf_free(p);
	  }
  }
}

/**
 * This function close the TCP connection
 *
 * The reasons for a TCP close :
 * - @code{.c} tcp_output(my_pcb) != ERR_OK @endcode // if the action to force all enqueued data to be sent now failed
 * - @code{.c} tcp_write(my_pcb, arg, len, TCP_WRITE_FLAG_COPY) == ERR_MEM @endcode // ERR_MEM : application should wait until some of the currently enqueued data has been successfully received
 * - @code{.c} if ( my_pcb->state != LISTEN && my_pcb->state != CLOSED && my_pcb->state != ESTABLISHED ) tcp_close_(my_pcb);  @endcode // check if another connection already exist
 * - @code{.c} if ( err == ERR_OK && p == NULL )  tcp_close_(tpcb); } @endcode // Close connection if empty packet and no error
 *
 * @param pcb TCP structure pointer
 *
 * @return ERR_OK if successful
 *
 * called in
 * 	- TCPSend() [GatewayComstack.cpp]
 * 	- tcp_accept_() [GatewayComstack.cpp]
 * 	- tcp_recv_() [GatewayComstack.cpp]
 */
static err_t
tcp_close_	(struct tcp_pcb *pcb) {
	/* close callback functions */
	 tcp_arg(pcb, NULL);
	 tcp_sent(pcb, NULL);
	 tcp_recv(pcb, NULL);
	 tcp_close(pcb);
	 return ERR_OK;
}

/**
 * This function accept the TCP connection. This function
 * is called by the LwIP library when processing the packet received, and
 * need to accept this new TCP connection.
 *
 * The TCP connection has been set to only accept one TCP connection at a time, the older connection will be
 * closed and be replaced by the new one
 *
 * @param arg
 * @param newpcb
 * @param err
 *
 * @return ERR_OK if successful
 *
 * called in
 * 	- TCPSend() [GatewayComstack.cpp]
 * 	- tcp_accept_() [GatewayComstack.cpp]
 * 	- tcp_recv_() [GatewayComstack.cpp]
 */
static err_t
tcp_accept_(void * arg , struct tcp_pcb* newpcb , err_t err){
	/* associate callback functions to new connection */
	LWIP_UNUSED_ARG(arg);
	LWIP_UNUSED_ARG(err);

	/* check if another connection already exist */
	if ( my_pcb->state != LISTEN && my_pcb->state != CLOSED && my_pcb->state != ESTABLISHED ) tcp_close_(my_pcb);

    /* set priority for the newly accepted tcp connection newpcb */
    tcp_setprio(newpcb, TCP_PRIO_MIN);
    /* initialize lwip tcp_arg callback function for newpcb  */
    tcp_arg(newpcb, NULL);
    /* initialize lwip tcp_recv callback function for newpcb  */
    tcp_recv(newpcb, tcp_recv_);
    /* initialize lwip tcp_err callback function for newpcb  */
    tcp_err(newpcb, tcp_err_);
    /* initialize lwip tcp_poll callback function for newpcb */
    tcp_poll(newpcb, tcp_poll_, 1);

    my_pcb = newpcb ; /* associate pcb initialize to my_pcb */
    my_pcb->flags |= TF_NODELAY ;
    return ERR_OK;
}

/**
 * This function process the message received in a TCP packet (does not process packet with ACK)
 * When the callback function is set in the tcp connection the function will be called when new data
 * arrives. The callback function will be passed a NULL pbuf to
 * indicate that the remote host has closed the connection. If the
 * callback function returns ERR_OK or ERR_ABRT it must have
 * freed the pbuf, otherwise it must not have freed it.
 *
 * @param arg
 * @param tcpcb
 * @param p
 * @param err
 *
 * @return ERR_OK
 *
 * called in by the lwIP library (the callback function is set with tcp_recv(newpcb, tcp_recv_) in tcp_accept_()
 */
static err_t
tcp_recv_ 	(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err){
	/* called on reception of data on TCP */
	LWIP_UNUSED_ARG(arg);

	if ( err == ERR_OK && p!= NULL ){
		//LOWA_MGR_Read_Ethernet(p->tot_len,p->payload); /* take received data */
		tcp_recved(tpcb, p->tot_len); /* application has taken the data */
		pbuf_free(p); /* free packet buffer */

//		#if CONSOLE_ENABLE_DEBUG_ETHERNET == CONSOLE__OPTION__ENABLED
//			CONSOLE("[lwIP : TCP Receive] Data : %s Size : %d \r\n",p->payload,p->tot_len);
//		#endif
	}

	// Close connection if empty packet and no error
	if ( err == ERR_OK && p == NULL ){
		tcp_close_(tpcb);
	}
	return ERR_OK;
}

/**
 * If a connection is aborted because of an error, the application is
 * alerted of this event by the err callback. Errors that might abort a
 * connection are when there is a shortage of memory. The callback
 * function to be called is set using the tcp_err() function.
 *
 * @note The corresponding pcb is already freed when this callback is called!
 *
 * @param arg
 * @param err
 *
 * @return none
 *
 * called in by the lwIP library (the callback function is set with tcp_err(newpcb, tcp_err_) ) in tcp_accept_()
 *
 * @todo This function isn't used in the program for now !
 */
static void
tcp_err_ 	(void *arg, err_t err){
}

/**
 * When a connection is idle (i.e., no data is either transmitted or
 * received), lwIP will repeatedly poll the application by calling a
 * specified callback function(this one). This can be used either as a watchdog
 * timer for killing connections that have stayed idle for too long, or
 * as a method of waiting for memory to become available. For instance,
 * if a call to tcp_write() has failed because memory wasn't available,
 * the application may use the polling functionality to call tcp_write()
 * again when the connection has been idle for a while.
 *
 * @param arg
 * @param pcb
 *
 * @return none
 *
 * called in by the lwIP library (the callback function is set with tcp_poll(newpcb, tcp_poll_, 1) ) in tcp_accept_()
 *
 * @todo This function isn't used in the program for now !
 */
static err_t
tcp_poll_  (void *arg, struct tcp_pcb *pcb) {
	return ERR_OK;
}

/**
 * This function is set as a callback function when an ACK packet is received for the data send is received
 *
 * @param arg
 * @param tpcb
 * @param len
 *
 * @return none
 *
 * called in by the lwIP library (the callback function is set with tcp_sent(my_pcb,tcp_sent_) ) in TCPSend()
 *
 * @todo This function isn't used in the program for now !
 */
static err_t
tcp_sent_ ( void * arg , struct tcp_pcb * tpcb , u16_t len ){
	return ERR_OK;
}

/**
  * @brief  Returns the current time in milliseconds
  *         when LWIP_TIMERS == 1 and NO_SYS == 1
  * @param  None
  * @retval Current Time value
  */
u32_t sys_now(void)
{
  return HAL_GetTick();
}


/* END OF FILE */
