#include "main.h"
#include "system.h"

ip_addr_t mch_myip_addr; /* 192.168.1.2 */
ip_addr_t gw_addr;
ip_addr_t netmask; /* 192.168.1.1 */
ip_addr_t ip_addr;
struct Flags flags;  // Definition of flags
uint8_t flag_send_settings;
//MQTT START
#define MQTT_SERVER_IP IPADDR_ANY
#define MQTT_SERVER_PORT 1883

void mqtt_client_do_connect (mqtt_client_t *client, int flag)
{
  struct mqtt_connect_client_info_t ci;
  memset (&ci, 0, sizeof(ci));
  /* Set MQTT client information including client id, username, password, and will message,
   note that client id is required. */
  //struct Settings current_settings;
  char str[20];
  sprintf (str, "STM32_0x%X", (unsigned int) current_settings.device_id);

  ci.client_id = str;
  ci.keep_alive = 10;
  /* Initialize the client's connection to the MQTT server based on IP address determined by IP_ADDR
   and register the SUB or PUB callback functions based on the flag. */
  /* IP_ADDR is used to initialize IP address format in lwIP. */

  if (flag == FLAG_SUB)
    {
      mqtt_client_connect (client, &ip_addr, 1883, mqtt_connection_cb, NULL,
			   &ci);
    }
  else if (flag == FLAG_PUB)
    {
      mqtt_client_connect (client, &ip_addr, 1883, mqtt_pub_connection_cb, NULL,
			   &ci);
    }
}
void mqtt_pub_connection_cb (mqtt_client_t *client, void *arg,
			     mqtt_connection_status_t status)
{
  if (status == MQTT_CONNECT_ACCEPTED)
    {
      Console_WARNING ("mqtt_connection_cb: Successfully connected\\n");
      const char *pub_payload = "hello this is lwIP";
      err_t err;
      u8_t qos = 2;
      u8_t retain = 0;
      mqtt_publish (client, PUB_TOPIC, pub_payload, strlen (pub_payload), qos,
		    retain, NULL, arg);
    }
  else
    {
      Console_WARNING ("mqtt_connection_cb: Disconnected, reason: %d\\n",
		       status);
    }
}
void mqtt_connection_cb (mqtt_client_t *client, void *arg,
			 mqtt_connection_status_t status)
{
  if (status == MQTT_CONNECT_ACCEPTED)
    {
      Console_WARNING ("mqtt_connection_cb: Successfully connected\\n");
      /* Register the callback function for PUB messages */
      mqtt_set_inpub_callback (client, mqtt_incoming_publish_cb,
			       mqtt_incoming_data_cb, arg);
      /* SUB */
      char topic[35];
      sprintf (topic, "%s/COMMAND", current_settings.device_name);
      mqtt_subscribe(client, topic, 1, mqtt_sub_request_cb, arg);
      sprintf (topic, "%s/SETTING", current_settings.device_name);
      mqtt_subscribe(client, topic, 1, mqtt_sub_request_cb, arg);
      system_led (7, LED_STATE_ON);
      flags.mqtt_connected = 1;
    }
  else
    {
      Console_WARNING ("mqtt_connection_cb: Disconnected, reason: %d\\n",
		       status);
      flags.mqtt_connected = 0;
      system_led (7, LED_STATE_BLINK);
      /* Reconnect in case of connection failure */
      struct mqtt_connect_client_info_t ci;
      memset (&ci, 0, sizeof(ci));
      /* Set MQTT client information including client id, username, password, and will message,
       note that client id is required. */
      char str[20];
      sprintf (str, "STM32_0x%X", (unsigned int) current_settings.device_id);
      ci.client_id = str;
      ci.keep_alive = 10;
      mqtt_client_connect (client, &ip_addr, 1883, mqtt_connection_cb, NULL,
			   &ci);
    }
}

static int inpub_id;
void mqtt_incoming_publish_cb (void *arg, const char *topic, u32_t tot_len)
{
  Console_WARNING ("Incoming publish at topic %s with total length %u\\n",
		   topic, (unsigned int) tot_len);
  if (strstr (topic, "COMMAND"))
    {
      /* Handle all topics starting with 'A' in the same way */
      inpub_id = 1;
    }
  else if (strstr (topic, "SETTING"))
    {
      /* Handle all other topics differently */
      inpub_id = 3;
    }
  else
    {
      inpub_id = 2;
    }
}
void mqtt_incoming_data_cb (void *arg, const u8_t *data, u16_t len, u8_t flags)
{
  Console_WARNING ("Incoming publish payload with length %d, flags %u\\n", len,
		   (unsigned int) flags);
  char payload[len]; //Create buffer for payload
  memcpy (payload, (const char*) data, len);
  Console_WARNING ("mqtt payload: %s\\n", payload);
  if (flags & MQTT_DATA_FLAG_LAST)
    {
      /* Handle data based on the reference */
      if (inpub_id == 1) //COMMAND detected
	{
	  if (strstr (payload, "OUT1=")) //todo make this in one if
	    {
	      if (strstr (payload, "=ON"))
		system_drive_output (OUTPUT_1, LED_STATE_ON);
	      else if (strstr (payload, "=OFF"))
		system_drive_output (OUTPUT_1, LED_STATE_OFF);
	      else if (strstr (payload, "=TOGGLE"))
		system_drive_output (OUTPUT_1, LED_STATE_TOGGLE);
	      else
		Console_WARNING ("Unknown payload");
	    }
	  if (strstr (payload, "OUT2="))
	    {
	      if (strstr (payload, "=ON"))
		system_drive_output (OUTPUT_2, LED_STATE_ON);
	      else if (strstr (payload, "=OFF"))
		system_drive_output (OUTPUT_2, LED_STATE_OFF);
	      else if (strstr (payload, "=TOGGLE"))
		system_drive_output (OUTPUT_2, LED_STATE_TOGGLE);
	      else
		Console_WARNING ("Unknown payload");
	    }
	  if (strstr (payload, "OUT3="))
	    {
	      if (strstr (payload, "=ON"))
		system_drive_output (OUTPUT_3, LED_STATE_ON);
	      else if (strstr (payload, "=OFF"))
		system_drive_output (OUTPUT_3, LED_STATE_OFF);
	      else if (strstr (payload, "=TOGGLE"))
		system_drive_output (OUTPUT_3, LED_STATE_TOGGLE);
	      else
		Console_WARNING ("Unknown payload");
	    }
	//}
      if ((!(memcmp (payload, "PWM", 3))) && payload[4] == '=') //payload start with PWM, and other conditions
	{
	  uint8_t pwm_ch = payload[3] - '0' + 2;
	  uint8_t value = 0, index = 0;
	  if (strstr (payload, "=ON"))
	    system_drive_output (pwm_ch, 100);
	  else if (strstr (payload, "=OFF"))
	    system_drive_output (pwm_ch, 0);
	  else
	    {
	      uint8_t value = 0, index = 5;
	      while (payload[index] != '\0')
		{
		  // Check if the character is a digit
		  if (isdigit(payload[index]))
		    {
		      // Convert character to integer and accumulate the resul100
		      value = value * 10 + (payload[index] - '0');
		    }
		  index++;
		}
	      Console_WARNING ("PWM value detected: %d", value);
	      system_drive_output (pwm_ch, value);
	    }
	}
      if (strstr (payload, "RGB")) system_rgb_drive(payload);

	}
      if (inpub_id == 3) //SETTINGS
	{
	  if (strstr (payload, "IP="))
	    settings_change_ip (payload, current_settings.ip_add);
	  if (strstr (payload, "GATEWAY="))
	    settings_change_ip (payload, current_settings.gateway);
	  if (strstr (payload, "NETMASK="))
	    settings_change_ip (payload, current_settings.netmask);
	  if (strstr (payload, "SERVER="))
	    settings_change_ip (payload, current_settings.server_address);
	  if (strstr (payload, "DHCP="))
	    settings_dhcp (payload, &current_settings.dhcp_on);
	  if (strstr (payload, "PWM_PSC="))
	    settings_pwm (payload, &current_settings.pwm_prescaler);
	  if (strstr (payload, "DIMMING="))
	    settings_pwm (payload, &current_settings.dimming_lenght);
	  if (strstr (payload, "NAME="))
	    settings_name (payload, current_settings.device_name);
	  if (strstr (payload, "SAVE"))
	    ProgramSettings (&current_settings); //Program default settings to flash
	  if (strstr (payload, "RESET"))
	    NVIC_SystemReset (); //Program default settings to flash
	  if (strstr (payload, "SHOW"))
	    flag_send_settings=1;

	}
    }
  else
    {
      /* To handle payloads that are too long, save them in a buffer or a file. */
    }
}

void mqtt_sub_request_cb ()
{
  Console_WARNING ("--Sub request done!--");
}
