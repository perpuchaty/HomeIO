	/**@file modules/Ethernet/GatewayComstack.h
 * @brief Ethernet communication TCP / ICMP / ARP / IPv4
 * @author 
 * @date 09/10/2019
 * @version lwIP 2.1.2 released
 * @site http://savannah.nongnu.org/projects/lwip/
 * @source lwIP - A Lightweight TCP/IP stack
 *

 *   (c) 2019 AAAA / AAAA
 * @endcode
 */


#ifndef __GATEWAY_COMSTACK_H__
#define __GATEWAY_COMSTACK_H__


// ==================================================
//    INCLUDE
// ==================================================
#include "main.h"

// ==================================================
//     FUNCTION
// ==================================================

void Gateway_Initialize_Ethernet(void);
HAL_StatusTypeDef Gateway_Initialize_lwIP(void);
HAL_StatusTypeDef Gateway_Initialize_lwIP_mqtt(void);
void Gateway_MainFunction();


#ifdef __cplusplus
extern "C" {
#endif
HAL_StatusTypeDef TCPSend (const void * arg , int len);

#ifdef __cplusplus
}
#endif


#endif /*__GATEWAY_COMSTACK_H__*/
