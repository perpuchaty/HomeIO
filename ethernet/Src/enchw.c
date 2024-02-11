/* ENC28J60 hardware implementation for EMLIB devices.
 *
 * The enchw_device_t multi-device support is unused so far as it was added to
 * enc28j60.c later */

#include "main.h"
#include "enchw.h"

#define pause() // HAL_Delay(100)
#define SPI_ETH_HANDLE (&hspi1)

void enchw_setup(enchw_device_t __attribute__((unused)) * dev)
{
}

void enchw_select(enchw_device_t __attribute__((unused)) * dev)
{
	/* this migh be relevant for t_{CSD}, especially when sending consecutive commands. */
	pause();
	HAL_GPIO_WritePin(ETH_CS_GPIO_Port, ETH_CS_Pin, GPIO_PIN_RESET);
}

void enchw_unselect(enchw_device_t __attribute__((unused)) * dev)
{
	/* if this pause is not observed, T_{CSH} will not be obeyed and writes
	 * to MIREGADR will fail */
	pause();
	HAL_GPIO_WritePin(ETH_CS_GPIO_Port, ETH_CS_Pin, GPIO_PIN_SET);
}

uint8_t enchw_exchangebyte(enchw_device_t __attribute__((unused)) * dev, uint8_t byte)
{
	uint8_t rxData;
	HAL_SPI_TransmitReceive(SPI_ETH_HANDLE, &byte, &rxData, 1, HAL_MAX_DELAY);
	return rxData;
}

void enchw_txbytes(const void *buffer, int len)
{
	HAL_SPI_Transmit(SPI_ETH_HANDLE, (uint8_t *)buffer, len, HAL_MAX_DELAY);
}

void enchw_rxbytes(void *buffer, int len)
{
	HAL_SPI_Receive(SPI_ETH_HANDLE, (uint8_t *)buffer, len, HAL_MAX_DELAY);
}

void enchw_txrxbytes(void *buffer, int len)
{
	HAL_SPI_TransmitReceive(SPI_ETH_HANDLE, (uint8_t *)buffer, (uint8_t *)buffer, len, HAL_MAX_DELAY);
}
