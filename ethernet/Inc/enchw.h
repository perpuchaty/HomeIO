#include <stdint.h>

#define ETH_CS_GPIO_Port GPIOB
#define ETH_CS_Pin GPIO_PIN_12

typedef struct
{
} enchw_device_t;

// #define enchw_select(x) HAL_GPIO_WritePin(ETH_CS_GPIO_Port, ETH_CS_Pin, GPIO_PIN_RESET)
// #define enchw_unselect(x) HAL_GPIO_WritePin(ETH_CS_GPIO_Port, ETH_CS_Pin, GPIO_PIN_SET)

void enchw_setup(enchw_device_t *dev);
void enchw_select(enchw_device_t *dev);
void enchw_unselect(enchw_device_t *dev);
uint8_t enchw_exchangebyte(enchw_device_t *dev, uint8_t byte);
void enchw_txbytes(const void *buffer, int len);
void enchw_rxbytes(void *buffer, int len);
void enchw_txrxbytes(void *buffer, int len);
