/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
  //extern UART_HandleTypeDef huart2;
  extern SPI_HandleTypeDef hspi1;

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_DATA_Pin GPIO_PIN_13
#define LED_DATA_GPIO_Port GPIOC
#define LED_CLOCK_Pin GPIO_PIN_14
#define LED_CLOCK_GPIO_Port GPIOC
#define LED_LATCH_Pin GPIO_PIN_15
#define LED_LATCH_GPIO_Port GPIOC
#define DOUT1_Pin GPIO_PIN_0
#define DOUT1_GPIO_Port GPIOH
#define DOUT2_Pin GPIO_PIN_1
#define DOUT2_GPIO_Port GPIOH
#define DOUT3_Pin GPIO_PIN_4
#define DOUT3_GPIO_Port GPIOA
#define IN3_Pin GPIO_PIN_2
#define IN3_GPIO_Port GPIOB
#define IN3_EXTI_IRQn EXTI2_IRQn
#define CS_ETH_Pin GPIO_PIN_12
#define CS_ETH_GPIO_Port GPIOB
#define CS_ADC_Pin GPIO_PIN_13
#define CS_ADC_GPIO_Port GPIOB
#define IN1_Pin GPIO_PIN_6
#define IN1_GPIO_Port GPIOB
#define IN1_EXTI_IRQn EXTI9_5_IRQn
#define IN2_Pin GPIO_PIN_7
#define IN2_GPIO_Port GPIOB
#define IN2_EXTI_IRQn EXTI9_5_IRQn

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
