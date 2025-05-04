/**
 ******************************************************************************
 * @file    girgitware.h
 * @author  Cenizas Labs Firmware Team
 * @brief   Header file for GirgitWare module.
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
#ifndef _GIRGITWARE_H_
#define _GIRGITWARE_H_

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include "stm32wbxx_hal.h"

#define SysTickHandler SysTick_Handler

void GirgitWareInit(void);
void ErrorHandler(void);
void DelayMS(uint32_t);

#endif // _GIRGITWARE_H_
