/**
 ******************************************************************************
 * @file    girgitware_gpio.h
 * @author  Cenizas Labs Firmware Team
 * @brief   Header file of GirgitWare GPIO module.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 Cenizas Labs.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _GIRGITWARE_GPIO_H_
#define _GIRGITWARE_GPIO_H_

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "girgitware_gpio_var.h"

/**
 * @brief enum class for pin state
 * 
 */
typedef enum{
  PIN_LOW = 0U,
  PIN_HIGH = 1U
}PinState;

/* Exported functions --------------------------------------------------------*/
/**
 * @brief GirgitWare GPIO driver functions
 * 
 */

void GPIO_Init(GPIO_Handle* gpio_handle);
void GPIO_DeInit(GPIO_Handle* gpio_handle);
PinState GPIO_Read(GPIO_Handle* gpio_handle);
void GPIO_Write(GPIO_Handle* gpio_handle, PinState value);
void GPIO_Toggle(GPIO_Handle* gpio_handle);

#ifdef __cplusplus
}
#endif

#endif /* _GIRGITWARE_GPIO_H_ */