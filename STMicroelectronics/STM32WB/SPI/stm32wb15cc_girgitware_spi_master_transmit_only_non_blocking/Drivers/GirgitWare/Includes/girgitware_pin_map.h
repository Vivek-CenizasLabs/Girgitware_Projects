/**
 ******************************************************************************
 * @file    girgitware_pin_map.h
 * @author  Cenizas Labs Firmware Team
 * @brief   Header file for GirgitWare Pin Mapping module
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
#ifndef _GIRGITWARE_PIN_MAP_H_
#define _GIRGITWARE_PIN_MAP_H_

#include "girgitware.h"
#include "girgitware_pin.h"

#ifndef GPIOA
#define GPIOA ((GPIO_TypeDef *)GPIOA_BASE)
#endif

#ifndef GPIOB
#define GPIOB ((GPIO_TypeDef *)GPIOA_BASE)
#endif

#ifndef GPIOC
#define GPIOC ((GPIO_TypeDef *)GPIOA_BASE)
#endif

#ifndef GPIOD
#define GPIOD ((GPIO_TypeDef *)GPIOA_BASE)
#endif

#ifndef GPIOE
#define GPIOE ((GPIO_TypeDef *)GPIOA_BASE)
#endif

#ifndef GPIOF
#define GPIOF ((GPIO_TypeDef *)GPIOA_BASE)
#endif

#ifndef GPIOG
#define GPIOG ((GPIO_TypeDef *)GPIOA_BASE)
#endif

#ifndef GPIOH
#define GPIOH ((GPIO_TypeDef *)GPIOA_BASE)
#endif

#ifndef GPIOI
#define GPIOI ((GPIO_TypeDef *)GPIOA_BASE)
#endif

#ifndef GPIOJ
#define GPIOJ ((GPIO_TypeDef *)GPIOA_BASE)
#endif

#ifndef GPIOK
#define GPIOK ((GPIO_TypeDef *)GPIOA_BASE)
#endif

#ifndef GPIOL
#define GPIOL ((GPIO_TypeDef *)GPIOA_BASE)
#endif

#ifndef GPIOM
#define GPIOM ((GPIO_TypeDef *)GPIOA_BASE)
#endif

#ifndef GPION
#define GPION ((GPIO_TypeDef *)GPIOA_BASE)
#endif

#ifndef GPIOO
#define GPIOO ((GPIO_TypeDef *)GPIOA_BASE)
#endif

#ifndef GPIOP
#define GPIOP ((GPIO_TypeDef *)GPIOA_BASE)
#endif

#ifndef GPIOQ
#define GPIOQ ((GPIO_TypeDef *)GPIOA_BASE)
#endif

#ifndef GPIOR
#define GPIOR ((GPIO_TypeDef *)GPIOA_BASE)
#endif

#ifndef GPIOS
#define GPIOS ((GPIO_TypeDef *)GPIOA_BASE)
#endif

#ifndef GPIOT
#define GPIOT ((GPIO_TypeDef *)GPIOA_BASE)
#endif

#ifndef GPIOU
#define GPIOU ((GPIO_TypeDef *)GPIOA_BASE)
#endif

#ifndef GPIOV
#define GPIOV ((GPIO_TypeDef *)GPIOA_BASE)
#endif

#ifndef GPIOW
#define GPIOW ((GPIO_TypeDef *)GPIOA_BASE)
#endif

#ifndef GPIOX
#define GPIOX ((GPIO_TypeDef *)GPIOA_BASE)
#endif

#ifndef GPIOY
#define GPIOY ((GPIO_TypeDef *)GPIOA_BASE)
#endif

#ifndef GPIOZ
#define GPIOZ ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOZ_IS_NULL
#endif

#ifndef GPIO_PIN_0
#define GPIO_PIN_0 ((uint16_t)0x0000)
#endif

#ifndef GPIO_PIN_1
#define GPIO_PIN_1 ((uint16_t)0x0000)
#endif

#ifndef GPIO_PIN_2
#define GPIO_PIN_2 ((uint16_t)0x0000)
#endif

#ifndef GPIO_PIN_3
#define GPIO_PIN_3 ((uint16_t)0x0000)
#endif

#ifndef GPIO_PIN_4
#define GPIO_PIN_4 ((uint16_t)0x0000)
#endif

#ifndef GPIO_PIN_5
#define GPIO_PIN_5 ((uint16_t)0x0000)
#endif

#ifndef GPIO_PIN_6
#define GPIO_PIN_6 ((uint16_t)0x0000)
#endif

#ifndef GPIO_PIN_7
#define GPIO_PIN_7 ((uint16_t)0x0000)
#endif

#ifndef GPIO_PIN_8
#define GPIO_PIN_8 ((uint16_t)0x0000)
#endif

#ifndef GPIO_PIN_9
#define GPIO_PIN_9 ((uint16_t)0x0000)
#endif

#ifndef GPIO_PIN_10
#define GPIO_PIN_10 ((uint16_t)0x0000)
#endif

#ifndef GPIO_PIN_11
#define GPIO_PIN_11 ((uint16_t)0x0000)
#endif

#ifndef GPIO_PIN_12
#define GPIO_PIN_12 ((uint16_t)0x0000)
#endif

#ifndef GPIO_PIN_13
#define GPIO_PIN_13 ((uint16_t)0x0000)
#endif

#ifndef GPIO_PIN_14
#define GPIO_PIN_14 ((uint16_t)0x0000)
#endif

#ifndef GPIO_PIN_15
#define GPIO_PIN_15 ((uint16_t)0x0000)
#endif

#ifndef GPIO_PIN_16
#define GPIO_PIN_16 ((uint16_t)0x0000)
#endif

#ifndef GPIO_PIN_17
#define GPIO_PIN_17 ((uint16_t)0x0000)
#endif

#ifndef GPIO_PIN_18
#define GPIO_PIN_18 ((uint16_t)0x0000)
#endif

#ifndef GPIO_PIN_19
#define GPIO_PIN_19 ((uint16_t)0x0000)
#endif

#ifndef GPIO_PIN_20
#define GPIO_PIN_20 ((uint16_t)0x0000)
#endif

#ifndef GPIO_PIN_21
#define GPIO_PIN_21 ((uint16_t)0x0000)
#endif

#ifndef GPIO_PIN_22
#define GPIO_PIN_22 ((uint16_t)0x0000)
#endif

#ifndef GPIO_PIN_23
#define GPIO_PIN_23 ((uint16_t)0x0000)
#endif

#ifndef GPIO_PIN_24
#define GPIO_PIN_24 ((uint16_t)0x0000)
#endif

#ifndef GPIO_PIN_25
#define GPIO_PIN_25 ((uint16_t)0x0000)
#endif

#ifndef GPIO_PIN_26
#define GPIO_PIN_26 ((uint16_t)0x0000)
#endif

#ifndef GPIO_PIN_27
#define GPIO_PIN_27 ((uint16_t)0x0000)
#endif

#ifndef GPIO_PIN_28
#define GPIO_PIN_28 ((uint16_t)0x0000)
#endif

#ifndef GPIO_PIN_29
#define GPIO_PIN_29 ((uint16_t)0x0000)
#endif

#ifndef GPIO_PIN_30
#define GPIO_PIN_30 ((uint16_t)0x0000)
#endif

#ifndef GPIO_PIN_31
#define GPIO_PIN_31 ((uint16_t)0x0000)
#endif

#ifndef GPIO_PIN_32
#define GPIO_PIN_32 ((uint16_t)0x0000)
#endif

extern GPIO_TypeDef *portMap[];
extern uint16_t pinMap[];

#endif // _GIRGITWARE_PIN_MAP_H_
