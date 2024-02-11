//
// SPI Interface for Ethernet Controller
//

#ifndef SPI_ETH_H__
#define SPI_ETH_H__

#include "main.h"

#define SPI_ETH_HANDLE  (&hspi1)

void spiEthInit();

static inline void spiEthAssertCs()
{
  HAL_GPIO_WritePin(ETH_CS_GPIO_Port, ETH_CS_Pin, GPIO_PIN_RESET);
}

static inline void spiEthDeassertCs()
{
  HAL_GPIO_WritePin(ETH_CS_GPIO_Port, ETH_CS_Pin, GPIO_PIN_SET);
}

static inline uint8_t spiEthTransfert(uint8_t txData)
{
  uint8_t rxData;
  HAL_SPI_TransmitReceive(SPI_ETH_HANDLE, &txData, &rxData, 1, HAL_MAX_DELAY);
  return rxData;
}

static inline void spiEthTransmitBuffer(const void *buffer, int len)
{
  HAL_SPI_Transmit(SPI_ETH_HANDLE, (uint8_t *) buffer, len, HAL_MAX_DELAY);
}

static inline void spiEthReceiveBuffer(void *buffer, int len)
{
  HAL_SPI_Receive(SPI_ETH_HANDLE, (uint8_t *) buffer, len, HAL_MAX_DELAY);
}

static inline void spiEthTransmitReceiveBuffer(void *buffer, int len)
{
  HAL_SPI_TransmitReceive(SPI_ETH_HANDLE, (uint8_t *) buffer, (uint8_t *) buffer, len, HAL_MAX_DELAY);
}

#endif // SPI_ETH_H__
