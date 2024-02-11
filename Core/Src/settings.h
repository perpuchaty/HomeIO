/*
 * settings.h
 *
 *  Created on: 8 lut 2024
 *      Author: Sowa
 */

#ifndef SRC_SETTINGS_H_
#define SRC_SETTINGS_H_

void settings_change_ip(const char *ipAddress, uint8_t *octets);
void settings_dhcp(const char *payload, uint8_t *value);
void settings_name (const char *payload, char *name);
void settings_pwm (const char *payload, uint8_t *value);


#endif /* SRC_SETTINGS_H_ */
