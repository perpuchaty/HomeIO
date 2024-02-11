/*
 * Copyright (c) 2001-2003 Swedish Institute of Computer Science.
 * All rights reserved. 
 * 
 * Redistribution and use in source and binary forms, with or without modification, 
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission. 
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED 
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT 
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT 
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 * 
 * Author: Simon Goldschmidt
 *
 */
#ifndef LWIP_HDR_LWIPOPTS_H__
#define LWIP_HDR_LWIPOPTS_H__

/* Prevent having to link sys_arch.c (we don't test the API layers in unit tests) */
#define NETIF_DEBUG                     LWIP_DBG_ON
#define LWIP_DEBUG						LWIP_DBG_ON
#define MQTT_DEBUG                      LWIP_DBG_ON
#define ALTCP_MBEDTLS_DEBUG             LWIP_DBG_OFF
#define ALTCP_MBEDTLS_LIB_DEBUG         LWIP_DBG_OFF


#define NO_SYS                          1
#define LWIP_NETCONN                    0
#define LWIP_SOCKET                     0
#define SYS_LIGHTWEIGHT_PROT            0

#define LWIP_IPV6                       0
#define IPV6_FRAG_COPYHEADER            0
#define LWIP_IPV6_DUP_DETECT_ATTEMPTS   0

/* Enable some protocols to test them */
#define LWIP_DHCP                       0
#define LWIP_AUTOIP                     0

#define LWIP_IGMP                       1
#define LWIP_DNS                        0

#define LWIP_ALTCP                      0
#define LWIP_ALTCP_TLS                  0
#define LWIP_ALTCP_TLS_MBEDTLS          0

/* Turn off checksum verification of fuzzed data */
//#define CHECKSUM_CHECK_IP               1
//#define CHECKSUM_CHECK_UDP              0
//#define CHECKSUM_CHECK_TCP              1
//#define CHECKSUM_CHECK_ICMP             1
//#define CHECKSUM_CHECK_ICMP6            0

#define CHECKSUM_BY_HARDWARE

#ifdef CHECKSUM_BY_HARDWARE
  /* CHECKSUM_GEN_IP==0: Generate checksums by hardware for outgoing IP packets.*/
  #define CHECKSUM_GEN_IP                 1
  /* CHECKSUM_GEN_UDP==0: Generate checksums by hardware for outgoing UDP packets.*/
  #define CHECKSUM_GEN_UDP                1
  /* CHECKSUM_GEN_TCP==0: Generate checksums by hardware for outgoing TCP packets.*/
  #define CHECKSUM_GEN_TCP                1
  /* CHECKSUM_CHECK_IP==0: Check checksums by hardware for incoming IP packets.*/
  #define CHECKSUM_CHECK_IP               0
  /* CHECKSUM_CHECK_UDP==0: Check checksums by hardware for incoming UDP packets.*/
  #define CHECKSUM_CHECK_UDP              0
  /* CHECKSUM_CHECK_TCP==0: Check checksums by hardware for incoming TCP packets.*/
  #define CHECKSUM_CHECK_TCP              0
  /* CHECKSUM_GEN_ICMP==1: Check checksums by hardware for outgoing ICMP packets.*/
  /* Hardware TCP/UDP checksum insertion not supported when packet is an IPv4 fragment */
  #define CHECKSUM_GEN_ICMP               1
  /* CHECKSUM_CHECK_ICMP==0: Check checksums by hardware for incoming ICMP packets.*/
  #define CHECKSUM_CHECK_ICMP             0

#else
  /* CHECKSUM_GEN_IP==1: Generate checksums in software for outgoing IP packets.*/
  #define CHECKSUM_GEN_IP                 1
  /* CHECKSUM_GEN_UDP==1: Generate checksums in software for outgoing UDP packets.*/
  #define CHECKSUM_GEN_UDP                1
  /* CHECKSUM_GEN_TCP==1: Generate checksums in software for outgoing TCP packets.*/
  #define CHECKSUM_GEN_TCP                1
  /* CHECKSUM_CHECK_IP==1: Check checksums in software for incoming IP packets.*/
  #define CHECKSUM_CHECK_IP               1
  /* CHECKSUM_CHECK_UDP==1: Check checksums in software for incoming UDP packets.*/
  #define CHECKSUM_CHECK_UDP              1
  /* CHECKSUM_CHECK_TCP==1: Check checksums in software for incoming TCP packets.*/
  #define CHECKSUM_CHECK_TCP              1
  /* CHECKSUM_GEN_ICMP==1: Check checksums by hardware for outgoing ICMP packets.*/
  #define CHECKSUM_GEN_ICMP               1
  /* CHECKSUM_CHECK_ICMP==1: Check checksums by hardware for incoming ICMP packets.*/
  #define CHECKSUM_CHECK_ICMP             1
#endif
/* Minimal changes to opt.h required for tcp unit tests: */
/* ---------- Memory options ---------- */
#define MEM_SIZE                		   (15UL * 1024UL)
/* MEMP_NUM_TCP_PCB: the number of simulatenously active TCP
   connections. */
#define MEM_ALIGNMENT 					   4

/* ---------- Pbuf options ---------- */
/* PBUF_POOL_SIZE: the number of buffers in the pbuf pool. */
#define PBUF_POOL_SIZE         	 		(40)
//#define PBUF_POOL_SIZE                  400 /* pbuf tests need ~200KByte */

/* PBUF_POOL_BUFSIZE: the size of each pbuf in the pbuf pool. */
#define PBUF_POOL_BUFSIZE       		   256
/* MEMP_NUM_TCP_SEG: the number of simultaneously queued TCP
   segments. */
// #define MEMP_NUM_TCP_SEG               TCP_SND_QUEUELEN

/* ---------- TCP options ---------- */
#define LWIP_TCP						      1
// #define TCP_TTL							   255

/* Controls if TCP should queue segments that arrive out of
   order. Define to 0 if your device is low on memory. */
#define TCP_QUEUE_OOSEQ                0
/* TCP Maximum segment size. */
#define TCP_MSS                        1460
/* TCP sender buffer space (bytes) */
#define TCP_SND_BUF            	      ( 4 * TCP_MSS) //(12 * TCP_MSS)
/* TCP receive window. */
#define TCP_WND                        ( 5 * TCP_MSS) //(10 * TCP_MSS)

/* -------- TCP Timer Intervals ------- */
#define TCP_TMR_INTERVAL               10    /* The TCP timer interval in milliseconds. */
#define MEMP_NUM_SYS_TIMEOUT           15

#endif /* LWIP_HDR_LWIPOPTS_H__ */
