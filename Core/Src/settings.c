/*
 * settings.c
 *
 *  Created on: 8 lut 2024
 *      Author: Sowa
 */
#include "system.h"
extern int client;

void settings_change_ip (const char *ipAddress, uint8_t *octets)
{
  const char *delimiter = "=";
  char *token;

  // Find the position of '=' in the input string
  char *position = strstr (ipAddress, delimiter);
  if (position == NULL)
    {
      printf ("Invalid input format\n");
      return;
    }

  // Copy the substring after '='
  char ipAddressCopy[strlen (position) + 1];
  strcpy (ipAddressCopy, position + 1);

  // Use strtok to split the string by periods
  token = strtok (ipAddressCopy, ".");
  int i = 0;
  while (token != NULL && i < 4)
    {
      octets[i] = atoi (token);
      token = strtok (NULL, ".");
      i++;
    }
}

void settings_dhcp (const char *payload, uint8_t *value)
{
  if (payload[5] == '1')
    {
      *value = 1;
    }
  else
    {
      *value = 0;
    }
}

void settings_pwm (const char *payload, uint8_t *value)
{
  char *token;
  char pwm_psc_str[strlen (payload) + 1];

  // Make a copy of the payload string
  strcpy (pwm_psc_str, payload);

  // Use strtok to split the string by '='
  token = strtok (pwm_psc_str, "=");

  // Move to the next token which should be the numeric part
  token = strtok (NULL, "=");

  if (token != NULL)
    {
      // Convert the numeric part to an integer
      int pwm_psc = atoi (token);

      // Ensure the converted value is within the valid range
      if (pwm_psc >= 1 && pwm_psc <= 100)
	{
	  *value = (uint8_t) pwm_psc;
	  printf ("PWM_PSC value set to: %d\n", pwm_psc);
	}
      else
	{
	  printf ("Invalid PWM_PSC value: %s\n", token);
	}
    }
  else
    {
      printf ("Invalid input format\n");
    }
}
void settings_name (const char *payload, char *name)
{
  char *token;
  char name_str[strlen (payload) + 1];

  // Make a copy of the payload string
  strcpy (name_str, payload);

  // Use strtok to split the string by '='
  token = strtok (name_str, "=");

  // Move to the next token which should be the name part
  token = strtok (NULL, "=");

  if (token != NULL)
    {
      // Copy the name part to the name array
      strncpy (name, token, 20);
      name[19] = '\0'; // Null-terminate the string to ensure it's properly terminated

      printf ("Name set to: %s\n", name);
    }
  else
    {
      printf ("Invalid input format\n");
    }
}
