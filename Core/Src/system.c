/*
 * system.c
 *
 *  Created on: 28 gru 2023
 *      Author: Sowa
 */
#include "system.h"

struct Error
{
  uint16_t debounce[3];
  uint16_t server_disconnection;
};
struct Register registers;
struct Register registers_tmp;
struct Error error;

extern SPI_HandleTypeDef hspi2;

// This are default settings!
struct Settings default_settings =
  { .version = 1, .ip_add =
    { 192, 168, 1, 32 }, .gateway =
    { 192, 168, 1, 1 }, .netmask =
    { 255, 255, 255, 0 }, .server_address =
    { 192, 168, 1, 2 }, .dhcp_on = 0, .pwm_prescaler = 0x10,
      .dimming_lenght = 8,
      .device_id = 0xABCD1234,
      .device_name = "STM32",
  .rgb_led_number=20
  };
//          uint8_t ip_add[4];
//          uint8_t gateway[4];
//          uint8_t netmask[4];
//          uint8_t server_address[4];
//          uint8_t dhcp_on;
//          uint16_t pwm_prescaler;
//          uint8_t dimming_lenght;
//          uint32_t device_id;
//          char device_name[20];
struct Settings current_settings;

uint8_t led_register, led_reg_tmp, led_toogle_reg;
uint16_t mscounter;
uint8_t pwm_dimm;
uint8_t debounce[3];
uint16_t adc_raw[3];

void system_init ()
{
  //Startup things here
  //Check if settings are in CPU flash. If not, program default values in flash
  ReadSettingsFromFlash (FLASH_SETTINGS_PAGE_ADDRESS, &current_settings);
  if (current_settings.version == 0xFF)
    {
      ProgramSettings (&default_settings); //Program default settings to flash
      NVIC_SystemReset ();	//Reset
    }
  system_apply_settings (); //Settings are in array, load them to correct places
  //Init RGB

}

void system_apply_settings ()
{
  TIM1->PSC = current_settings.pwm_prescaler;
  TIM2->PSC = current_settings.pwm_prescaler;
  current_settings.device_id = *((uint32_t*) 0x1FFF7590);
}

void system_led_update ()
{
  mscounter++;
  if (mscounter == LED_BLINK_TIM_RATE)
    {
      for (uint8_t i = 0; i < 8; i++)
	{
	  if ((led_toogle_reg >> i) & 1)
	    {
	      led_register ^= 1 << i;
	    }
	}
      mscounter = 0;
    }
  writeShiftRegister (led_register);
  //pwm controll
  if (pwm_dimm >= current_settings.dimming_lenght)
    {
      pwm_dimm = 0;
      if (registers.pwm[0] > TIM2->CCR1)
	{
	  TIM2->CCR1 = TIM2->CCR1 + 1;
	}
      else if (registers.pwm[0] < TIM2->CCR1)
	{
	  TIM2->CCR1 = TIM2->CCR1 - 1;
	}
      //==============
      if (registers.pwm[1] > TIM2->CCR2)
	{
	  TIM2->CCR2 = TIM2->CCR2 + 1;
	}
      else if (registers.pwm[1] < TIM2->CCR2)
	{
	  TIM2->CCR2 = TIM2->CCR2 - 1;
	}
      //==============
      if (registers.pwm[3] > TIM1->CCR4)
	{
	  TIM1->CCR4 = TIM1->CCR4 + 1;
	}
      else if (registers.pwm[3] < TIM1->CCR4)
	{
	  TIM1->CCR4 = TIM1->CCR4 - 1;
	}
    }
  pwm_dimm++;
}

void system_led (uint8_t led, uint8_t state)
{
  if (state == LED_STATE_ON)
    {
      led_register |= state << led;
      led_toogle_reg &= ~(1 << led);
    }
  else if (state == LED_STATE_OFF)
    {
      led_register &= ~(1 << led);
      led_toogle_reg &= ~(1 << led);
    }
  else if (state == LED_STATE_TOGGLE)
    {
      led_register ^= 1 << led;
    }
  else if (state == LED_STATE_BLINK)
    led_toogle_reg |= 1 << led;
//#define LED_STATE_ON 1
//#define LED_STATE_OFF 2
//#define LED_STATE_BLINK 3
//#define LED_STATE_TOGGLE 4
}
void writeShiftRegister (uint8_t data)
{
  HAL_GPIO_WritePin (LED_LATCH_GPIO_Port, LED_LATCH_Pin, RESET);
  for (int i = 0; i < 8; i++)
    {
      HAL_GPIO_WritePin (LED_CLOCK_GPIO_Port, LED_CLOCK_Pin, RESET);
      if (data & (1 << i))
	{ 	//Send data
		// Data pin high
	  HAL_GPIO_WritePin (LED_DATA_GPIO_Port, LED_DATA_Pin, SET);
	}
      else
	{
	  // Data pin low
	  HAL_GPIO_WritePin (LED_DATA_GPIO_Port, LED_DATA_Pin, RESET);
	}
      HAL_GPIO_WritePin (LED_CLOCK_GPIO_Port, LED_CLOCK_Pin, SET);
    }
  HAL_GPIO_WritePin (LED_LATCH_GPIO_Port, LED_LATCH_Pin, SET);
}

void system_drive_output (uint8_t output, uint8_t value)
{
  if (output == OUTPUT_1 || output == OUTPUT_2 || output == OUTPUT_3)
    {
      Console_INFO ("Output change. Output: %d. value: %d", output, value);
      if (value == 0 || value == 1) //On or off
	{
	  system_led (output, value);
	  if (output == OUTPUT_1)
	    HAL_GPIO_WritePin (DOUT1_GPIO_Port, DOUT1_Pin, value);
	  if (output == OUTPUT_2)
	    HAL_GPIO_WritePin (DOUT2_GPIO_Port, DOUT2_Pin, value);
	  if (output == OUTPUT_3)
	    HAL_GPIO_WritePin (DOUT3_GPIO_Port, DOUT3_Pin, value);
	  registers.output[output] = value;
	}
      if (value == 3) //toogle
	{
	  if (output == OUTPUT_1)
	    {
	      HAL_GPIO_TogglePin (DOUT1_GPIO_Port, DOUT1_Pin);
	      registers.output[output] = HAL_GPIO_ReadPin (DOUT1_GPIO_Port,
	      DOUT1_Pin);
	      system_led (output, LED_STATE_TOGGLE);
	    }
	  if (output == OUTPUT_2)
	    {
	      HAL_GPIO_TogglePin (DOUT2_GPIO_Port, DOUT2_Pin);
	      registers.output[output] = HAL_GPIO_ReadPin (DOUT2_GPIO_Port,
	      DOUT2_Pin);
	      system_led (output, LED_STATE_TOGGLE);
	    }
	  if (output == OUTPUT_3)
	    {
	      HAL_GPIO_TogglePin (DOUT3_GPIO_Port, DOUT3_Pin);
	      registers.output[output] = HAL_GPIO_ReadPin (DOUT3_GPIO_Port,
	      DOUT3_Pin);
	      system_led (output, LED_STATE_TOGGLE);
	    }
	}
    }

  if (output == OUTPUT_PWM1 || output == OUTPUT_PWM2 || output == OUTPUT_PWM3
      || output == OUTPUT_PWM4)
    {
      if (value == 0)
	system_led (output, LED_STATE_OFF); //PWM is on, let's blink LED
      else if (value == 100)
	system_led (output, LED_STATE_ON);
      else
	system_led (output, LED_STATE_BLINK);
      registers.pwm[output - 3] = value;
    }
}

void HAL_GPIO_EXTI_Callback (uint16_t GPIO_Pin)
{
  uint8_t out_to_drive;
  if (GPIO_Pin == IN1_Pin)
    out_to_drive = OUTPUT_1;
  if (GPIO_Pin == IN2_Pin)
    out_to_drive = OUTPUT_2;
  if (GPIO_Pin == IN3_Pin)
    out_to_drive = OUTPUT_3;

  if (debounce[out_to_drive] == 0)
    {
      system_drive_output (out_to_drive, LED_STATE_TOGGLE);
      debounce[out_to_drive] = DEBOUNCE_LENGHT;
    }
  else
    {
      error.debounce[out_to_drive]++;
    }
}

void system_debounce ()
{
  for (uint8_t i = 0; i < 3; i++)
    {
      if (debounce[i] > 0)
	{
	  debounce[i]--;
	}
    }
}

void HAL_SPI_RxCpltCallback (SPI_HandleTypeDef *hspi)
{
  //todo i think this can be removed lol system_led(0,LED_STATE_TOGGLE);
}

uint16_t system_read_adc (SPI_HandleTypeDef *spi, uint8_t channel)
{

  // Declare data that we will send
  uint8_t pTxData[3] =
    { 0 };
  pTxData[0] = ((0x01 << 7) |		// start bit
      (1 << 6) |			// SGL
      ((channel & 0x07) << 3)); 	// channel number
  pTxData[1] = 0x00;
  pTxData[2] = 0x00;

  // Data that we will get
  uint8_t pRxData[3] =
    { 0 };

  // CS low, Send and receive, CS high
  HAL_GPIO_WritePin (CS_ADC_GPIO_Port, CS_ADC_Pin, RESET);
  HAL_SPI_TransmitReceive (spi, &pTxData, &pRxData, 3, 10);
  HAL_GPIO_WritePin (CS_ADC_GPIO_Port, CS_ADC_Pin, SET);

  // Compute the ADC
  return 0x3FF
      & ((pRxData[0] & 0x01) << 9 | (pRxData[1] & 0xFF) << 1
	  | (pRxData[2] & 0x80) >> 7);
}

//Check if any IO changed status. If so, public change over mqtt
void system_check_state (mqtt_client_t *client)
{
//  struct Register{
//    uint8_t pwm[4];
//    uint8_t input[3];
//    uint8_t output[3];
//    uint16_t adc[3];
//  }; Register registers, registers_tmp;
//Check ADC

  char topic[64];
  char payload[64];

  //------------------ADC-----------------//
  for (uint8_t i = 0; i < 3; i++)
    {
      registers_tmp.adc[i] = system_read_adc (&hspi2, i);
      if (registers_tmp.adc[i] != registers.adc[i])
	{
	  registers.adc[i] = registers_tmp.adc[i];
	  sprintf (topic, "%s/OUTPUT/ADC%d/", current_settings.device_name,
		   i + 1);
	  sprintf (payload, "%d", registers_tmp.adc[i]);
	  mqtt_publish (client, topic, payload, strlen (payload), 0, 0,
			mqtt_pub_finished, NULL);
	  mch_net_poll ();
	  sys_check_timeouts ();
	}
    }

  //------------------DOUT-----------------//
  for (uint8_t i = 0; i < 3; i++)
    {
      if (registers_tmp.output[i] != registers.output[i])
	{
	  registers_tmp.output[i] = registers.output[i];
	  sprintf (topic, "%s/OUTPUT/DOUT%d/", current_settings.device_name,
		   i + 1);
	  if (registers.output[i] == 1)
	    sprintf (payload, "ON");
	  else
	    sprintf (payload, "OFF");
	  mqtt_publish (client, topic, payload, strlen (payload), 0, 0,
			mqtt_pub_finished, NULL);
	  mch_net_poll ();
	  sys_check_timeouts ();
	}
    }

  //------------------PWM-----------------//
  for (uint8_t i = 0; i < 4; i++)
    {
      if (registers_tmp.pwm[i] != registers.pwm[i])
	{
	  registers_tmp.pwm[i] = registers.pwm[i];
	  sprintf (topic, "%s/OUTPUT/PWM%d/", current_settings.device_name,
		   i + 1);
	  sprintf (payload, "%d", registers.pwm[i]);
	  ;
	  mqtt_publish (client, topic, payload, strlen (payload), 0, 0,
			mqtt_pub_finished, NULL);
	  mch_net_poll ();
	  sys_check_timeouts ();
	}
    }
  //----------------------SETTINGS-------------//
  if (flag_send_settings == 1)
    {
      flag_send_settings = 0;
      sprintf (topic, "%s/SETTINGS/IP/", current_settings.device_name);
      sprintf (payload, "%d.%d.%d.%d", current_settings.ip_add[0],
	       current_settings.ip_add[1], current_settings.ip_add[2],
	       current_settings.ip_add[3]);
      mqtt_publish (client, topic, payload, strlen (payload), 0, 0,
		    mqtt_pub_finished, NULL);
      mch_net_poll ();
      sys_check_timeouts ();

      sprintf (topic, "%s/SETTINGS/GATEWAY/", current_settings.device_name);
      sprintf (payload, "%d.%d.%d.%d", current_settings.gateway[0],
	       current_settings.gateway[1], current_settings.gateway[2],
	       current_settings.gateway[3]);
      mqtt_publish (client, topic, payload, strlen (payload), 0, 0,
		    mqtt_pub_finished, NULL);
      mch_net_poll ();
      sys_check_timeouts ();

      sprintf (topic, "%s/SETTINGS/NETMASK/", current_settings.device_name);
      sprintf (payload, "%d.%d.%d.%d", current_settings.netmask[0],
	       current_settings.netmask[1], current_settings.netmask[2],
	       current_settings.netmask[3]);
      mqtt_publish (client, topic, payload, strlen (payload), 0, 0,
		    mqtt_pub_finished, NULL);
      mch_net_poll ();
      sys_check_timeouts ();

      sprintf (topic, "%s/SETTINGS/SERVER/", current_settings.device_name);
      sprintf (payload, "%d.%d.%d.%d", current_settings.server_address[0],
	       current_settings.server_address[1],
	       current_settings.server_address[2],
	       current_settings.server_address[3]);
      mqtt_publish (client, topic, payload, strlen (payload), 0, 0,
		    mqtt_pub_finished, NULL);
      mch_net_poll ();
      sys_check_timeouts ();

      sprintf (topic, "%s/SETTINGS/DHCP/", current_settings.device_name);
      sprintf (payload, "%d", current_settings.dhcp_on);
      mqtt_publish (client, topic, payload, strlen (payload), 0, 0,
		    mqtt_pub_finished, NULL);
      mch_net_poll ();
      sys_check_timeouts ();

      sprintf (topic, "%s/SETTINGS/PWM_PSC/", current_settings.device_name);
      sprintf (payload, "%d", current_settings.pwm_prescaler);
      mqtt_publish (client, topic, payload, strlen (payload), 0, 0,
		    mqtt_pub_finished, NULL);
      mch_net_poll ();
      sys_check_timeouts ();

      sprintf (topic, "%s/SETTINGS/PWM_DIMM/", current_settings.device_name);
      sprintf (payload, "%d", current_settings.dimming_lenght);
      mqtt_publish (client, topic, payload, strlen (payload), 0, 0,
		    mqtt_pub_finished, NULL);
      mch_net_poll ();
      sys_check_timeouts ();

      sprintf (topic, "%s/SETTINGS/NAME/", current_settings.device_name);
      sprintf (payload, "%s", current_settings.device_name);
      mqtt_publish (client, topic, payload, strlen (payload), 0, 0,
		    mqtt_pub_finished, NULL);
      mch_net_poll ();
      sys_check_timeouts ();

      sprintf (topic, "%s/SETTINGS/MAC/", current_settings.device_name);
      sprintf (payload, "%02X:%02X:%02X:%02X:%02X:%02X", 2, 32,
	       (current_settings.device_id >> 24) & 0xFF,
	       (current_settings.device_id >> 16) & 0xFF,
	       (current_settings.device_id >> 8) & 0xFF,
	       (current_settings.device_id >> 0) & 0xFF);
      mqtt_publish (client, topic, payload, strlen (payload), 0, 0,
		    mqtt_pub_finished, NULL);
      mch_net_poll ();
      sys_check_timeouts ();

    }
}

void mqtt_pub_finished ()
{
  Console_WARNING ("--Published!--");
}

void system_rgb_drive (const char *payload)
{
  if (strstr (payload, "RGB_BRIGHTNESS=")) 	//update brightness
    {
      const char *brightness_str = strstr (payload, "RGB_BRIGHTNESS=");
      if (brightness_str != NULL)
	{
	  // Move the pointer to the character after '='
	  brightness_str += strlen ("RGB_BRIGHTNESS=");

	  // Convert the string to an integer using atoi()
	  int brightness = atoi (brightness_str);

	  // Check if the value is within the range 0-100
	  if (brightness >= 0 && brightness <= 100)
	    {
	      registers.rgb_brightness = brightness;
	    }
	  else
	    {
	      printf ("Error: Brightness value out of range.\n");
	    }
	}
    }
  else if (strstr (payload, "RGB=")) //update all leds
    {
      uint8_t octets[4];
      const char *delimiter = "=";
      char *token;

      // Find the position of '=' in the input string
      char *position = strstr (payload, delimiter);
      if (position == NULL)
	{
	  printf ("Invalid input format\n");
	  return;
	}

      // Copy the substring after '='
      char colors[strlen (position) + 1];
      strcpy (colors, position + 1);

      // Use strtok to split the string by periods
      token = strtok (colors, ",");
      int i = 0;
      while (token != NULL && i < 4)
	{
	  octets[i] = atoi (token);
	  token = strtok (NULL, ",");
	  i++;
	}
      if(octets[0]==0xff) //update all leds
	{
	for (uint8_t i = 0; i < current_settings.rgb_led_number; i++)
	  {
	    setLED (i, octets[1], octets[2], octets[3]);
	  }
	}
      else setLED (octets[0], octets[1], octets[2], octets[3]); //update specific led
    }
  ws2812_spi ();
}
