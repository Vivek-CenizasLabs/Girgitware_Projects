/**
 ******************************************************************************
 * @file    girgitware_gpio_var.h
 * @brief   Header file for GPIO variable definitions in GirgitWare middleware.
 ******************************************************************************
 * @attention
 *
 * This file is part of the GirgitWare middleware for GPIO abstraction.
 * It defines the GPIO_Handle structure used for GPIO configuration.
 *
 ******************************************************************************
 */

#ifndef _GIRGITWARE_GPIO_VAR_H_
#define _GIRGITWARE_GPIO_VAR_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stddef.h>
#include "stm32wbxx_hal.h"

/* GPIO Handle Structure Definition ------------------------------------------*/
typedef struct {
    GPIO_TypeDef *port;          /*!< GPIO port base address */
    uint16_t pin;                /*!< GPIO pin number */
    uint32_t mode;               /*!< GPIO mode (input, output, alternate, analog) */
    uint32_t pullUpPullDownSelect; /*!< GPIO pull-up/pull-down configuration */
    uint32_t alternateFunction;  /*!< GPIO alternate function configuration */
    uint32_t interruptEdge;      /*!< GPIO interrupt edge configuration */
} GPIO_Handle;

/* GPIO Pull-Up/Pull-Down Configuration --------------------------------------*/
#define GPIO_NO_PULL       GPIO_NOPULL
#define GPIO_PULL_UP       GPIO_PULLUP
#define GPIO_PULL_DOWN     GPIO_PULLDOWN

/* GPIO Interrupt Edge Configuration -----------------------------------------*/
#define GPIO_NO_INTERRUPT  0x00000000u
#define GPIO_RISING_EDGE   GPIO_MODE_IT_RISING
#define GPIO_FALLING_EDGE  GPIO_MODE_IT_FALLING

#ifdef __cplusplus
}
#endif

#endif /* _GIRGITWARE_GPIO_VAR_H_ */
