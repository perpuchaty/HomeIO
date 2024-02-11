/*
 * system.h
 *
 *  Created on: 28 gru 2023
 *      Author: Sowa
 */

#ifndef SRC_SYSTEM_H_
#define SRC_SYSTEM_H_

#include <lwip/inet.h>
#include <lwip/tcp.h>
#include <lwip/netif.h>
#include <lwip/init.h>
#include <lwip/timeouts.h>
#include <lwip/ip_addr.h>
#include <netif/etharp.h>
#include "lwip/apps/mqtt.h"
#include "lwip/apps/mqtt_priv.h"
#include <mchdrv.h>
#include <enc28j60.h>
#include <console.h>
#include <GatewayComstack.h>
#include "mqtt.h"
#include "qspi.h"
#include "led.h"
#include "flash.h"
#include "settings.h"
#define LED_STATE_ON 1
#define LED_STATE_OFF 0
#define LED_STATE_BLINK 2
#define LED_STATE_TOGGLE 3
#define LED_BLINK_TIM_RATE 500

#define OUTPUT_1 0
#define OUTPUT_2 1
#define OUTPUT_3 2

#define OUTPUT_PWM1 3
#define OUTPUT_PWM2 4
#define OUTPUT_PWM3 5
#define OUTPUT_PWM4 6

#define DEBOUNCE_LENGHT 20

#define NUM_LED 100 //RGB LEDS, only to store data. number of drived leds is determined in current_settings struct

void system_led (uint8_t led, uint8_t state);
void writeShiftRegister (uint8_t data);
void system_drive_output (uint8_t output, uint8_t value);
uint16_t system_read_adc (SPI_HandleTypeDef *spi, uint8_t channel);
void mqtt_pub_finished ();
void system_check_state (mqtt_client_t *client);
void system_apply_settings ();
void system_init();

struct Flags
{
  uint8_t input_change;
  uint8_t mqtt_connected;
  uint8_t send_settings;
};

extern struct Flags flags;
extern uint8_t flag_send_settings;
//LED related registers
extern uint8_t led_register, led_reg_tmp, led_toogle_reg;
extern uint16_t mscounter;

//INPUT related registers
extern uint8_t debounce[3]; //There is hardware debounce on PSU board, but make software debounce too.
#endif /* SRC_SYSTEM_H_ */

//ADC related registers
extern uint16_t adc_raw[3];

//Settings structure
struct Settings
{
  uint8_t version;
  uint8_t ip_add[4];
  uint8_t gateway[4];
  uint8_t netmask[4];
  uint8_t server_address[4];
  uint8_t dhcp_on;
  uint8_t pwm_prescaler;
  uint8_t dimming_lenght;
  uint32_t device_id;
  char device_name[20];
  uint8_t rgb_led_number;

};

struct Register
{
  uint8_t pwm[4];
  uint8_t pwm_tmp[4];
  uint8_t input[3];
  uint8_t output[3];
  uint16_t adc[3];
  uint8_t rgb_brightness;
};
extern struct Register registers;
extern struct Settings default_settings;
extern struct Settings current_settings;
