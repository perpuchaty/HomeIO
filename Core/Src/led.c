/*
 * led.c
 *
 *  Created on: Feb 1, 2024
 *      Author: Sowa
 */
#include "main.h"
#include "system.h"

uint8_t LED_Data[(NUM_LED * 24)+100];

extern SPI_HandleTypeDef hspi3;

#define USE_BRIGHTNESS 1


void setLED (uint8_t led, uint8_t r, uint8_t g, uint8_t b)
{
  #if USE_BRIGHTNESS
  	if (registers.rgb_brightness>100)registers.rgb_brightness = 100;
  	g = g*registers.rgb_brightness/100;
  	r = r*registers.rgb_brightness/100;
  	b = b*registers.rgb_brightness/100;

  #endif
  uint32_t color = g << 16 | r << 8 | b;
  uint8_t indx = 0;
  for (int i = 23; i >= 0; i--)
    {
      if (((color >> i) & 0x01) == 1)
	LED_Data[(led*24)+indx] = 248;  // store 1
      else
	LED_Data[(led*24)+indx] = 192;  // store 0
     indx++;
    }

}
void ws2812_spi ()
{
    for (uint i = 0; i < 100; i++)
    {
	LED_Data[(NUM_LED * 24)+i] = 0;
    }
  HAL_SPI_Transmit_DMA(&hspi3, LED_Data, (NUM_LED * 24)+100);
}
void WS2812_Send (void)
{
  ws2812_spi();
}
