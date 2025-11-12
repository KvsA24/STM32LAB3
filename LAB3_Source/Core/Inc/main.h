/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BUT1_Pin GPIO_PIN_1
#define BUT1_GPIO_Port GPIOA
#define BUT2_Pin GPIO_PIN_2
#define BUT2_GPIO_Port GPIOA
#define BUT3_Pin GPIO_PIN_3
#define BUT3_GPIO_Port GPIOA
#define RED1_Pin GPIO_PIN_4
#define RED1_GPIO_Port GPIOA
#define AMB1_Pin GPIO_PIN_5
#define AMB1_GPIO_Port GPIOA
#define GRE1_Pin GPIO_PIN_6
#define GRE1_GPIO_Port GPIOA
#define RED2_Pin GPIO_PIN_7
#define RED2_GPIO_Port GPIOA
#define LED1_Pin GPIO_PIN_1
#define LED1_GPIO_Port GPIOB
#define LED2_Pin GPIO_PIN_2
#define LED2_GPIO_Port GPIOB
#define SEG1_Pin GPIO_PIN_10
#define SEG1_GPIO_Port GPIOB
#define SEG2_Pin GPIO_PIN_11
#define SEG2_GPIO_Port GPIOB
#define SEG3_Pin GPIO_PIN_12
#define SEG3_GPIO_Port GPIOB
#define SEG4_Pin GPIO_PIN_13
#define SEG4_GPIO_Port GPIOB
#define SEG5_Pin GPIO_PIN_14
#define SEG5_GPIO_Port GPIOB
#define SEG6_Pin GPIO_PIN_15
#define SEG6_GPIO_Port GPIOB
#define AMB2_Pin GPIO_PIN_8
#define AMB2_GPIO_Port GPIOA
#define GRE2_Pin GPIO_PIN_9
#define GRE2_GPIO_Port GPIOA
#define LED3_Pin GPIO_PIN_3
#define LED3_GPIO_Port GPIOB
#define LED4_Pin GPIO_PIN_4
#define LED4_GPIO_Port GPIOB
#define SEG0_Pin GPIO_PIN_9
#define SEG0_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
