/*
 * mqtt.h
 *
 *  Created on: 22 sty 2024
 *      Author: Sowa
 */

#ifndef SRC_MQTT_H_
#define SRC_MQTT_H_


void mqtt_connection_cb(mqtt_client_t *client, void *arg, mqtt_connection_status_t status);
void mqtt_pub_connection_cb(mqtt_client_t *client, void *arg, mqtt_connection_status_t status);
void mqtt_incoming_publish_cb(void *arg, const char *topic, u32_t tot_len);
void mqtt_incoming_data_cb(void *arg, const u8_t *data, u16_t len, u8_t flags);
void mqtt_pub_finished();
void mqtt_sub_request_cb();
void mqtt_client_do_connect (mqtt_client_t *client, int flag);

extern ip_addr_t mch_myip_addr; /* 192.168.1.2 */
extern ip_addr_t gw_addr;
extern ip_addr_t netmask; /* 192.168.1.1 */
extern ip_addr_t ip_addr;
//static struct netif mchdrv_netif;
//static enc_device_t mchdrv_hw;
extern struct Flags flags;  // Definition of flags
//MQTT START

#define MQTT_SERVER_IP IPADDR_ANY
#define MQTT_SERVER_PORT 1883

#define FLAG_SUB 1
#define FLAG_PUB 2
#define PUB_TOPIC "HELLO"

#endif /* SRC_MQTT_H_ */
