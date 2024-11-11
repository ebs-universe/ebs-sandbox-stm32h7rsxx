/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f4xx_it.h
  * @brief   This file contains the headers of the interrupt handlers.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

#ifndef __STM32F4xx_IT_H
#define __STM32F4xx_IT_H

#ifdef __cplusplus
 extern "C" {
#endif

// These are inlineable handlers defined by application code. We 
// include them here for later inlining into the actual IRQ Handlers. 
#include <time/systick_handler.h>

// These IRQ handlers are defined by the HAL. These are included 
// here to bring the inclusion variable into scope.
#include <hal_platform/shared_handlers.h>
#include <hal_platform/exti_handlers.h>
#include <hal_platform/entropy_handlers.h>
#include <hal_platform/uart_handlers.h>
#include <hal_platform/usb_handlers.h>
#include <hal_platform/adc_handlers.h>

/**
 * @name Core IRQ Handlers
 */
/**@{*/   
void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);
/**@}*/ 

/**
 * @name GPIO EXTI IRQ Handlers
 */
/**@{*/   
void EXTI0_IRQHandler(void);
void EXTI1_IRQHandler(void);
void EXTI2_IRQHandler(void);
void EXTI3_IRQHandler(void);
void EXTI4_IRQHandler(void);
void EXTI5_IRQHandler(void);
void EXTI6_IRQHandler(void);
void EXTI7_IRQHandler(void);
void EXTI8_IRQHandler(void);
void EXTI9_IRQHandler(void);
void EXTI10_IRQHandler(void);
void EXTI11_IRQHandler(void);
void EXTI12_IRQHandler(void);
void EXTI13_IRQHandler(void);
void EXTI14_IRQHandler(void);
void EXTI15_IRQHandler(void);
/**@}*/ 

/**
 * @name Shared IRQ Handlers
 */
/**@{*/   
// void HASH_RNG_IRQHandler(void);
/**@}*/ 

/**
 * @name Entropy IRQ Handlers
 */
/**@{*/   
void RNG_IRQHandler(void);
/**@}*/ 

/**
 * @name ADC IRQ Handlers
 */
/**@{*/   
void ADC1_2_IRQHandler(void);
/**@}*/ 

/**
 * @name UART IRQ Handlers
 */
/**@{*/   
void USART1_IRQHandler(void);
void USART2_IRQHandler(void);
void USART3_IRQHandler(void);
void UART4_IRQHandler(void);
void UART5_IRQHandler(void);
void UART7_IRQHandler(void);
void UART8_IRQHandler(void);
void LPUART1_IRQHandler(void);
/**@}*/ 

/**
 * @name USB IRQ Handlers
 */
/**@{*/   
void OTG_FS_IRQHandler(void);
void OTG_HS_IRQHandler(void);
void UCPD1_IRQHandler(void);
/**@}*/

/**
 * @name Other Handlers
 * 
 * This is not an IRQ, but needed by the HAL. Since there isn't a better 
 * place to put it, we put here for now. These are implemented with the 
 * shared handlers.
 */
/**@{*/    
void Error_Handler(void);
/**@}*/ 

#ifdef __cplusplus
}
#endif

#endif /* __STM32F4xx_IT_H */
