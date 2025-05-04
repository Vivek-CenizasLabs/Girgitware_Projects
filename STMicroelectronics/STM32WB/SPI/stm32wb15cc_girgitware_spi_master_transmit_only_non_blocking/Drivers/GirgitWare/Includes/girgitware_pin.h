/**
 ******************************************************************************
 * @file    girgitware_pin.h
 * @author  Cenizas Labs Firmware Team
 * @brief   Header file for GirgitWare Pin module.
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
#ifndef _GIRGITWARE_PIN_H_
#define _GIRGITWARE_PIN_H_

#include <stdint.h>

/**
 * @enum GPIO_Port
 * @brief Enum for representing GPIO ports on a microcontroller.
 *
 * This enum provides symbolic names for the GPIO ports from PORT_A to PORT_Z.
 * It also includes numeric aliases (PORT_1 to PORT_26) for each lettered port.
 */
typedef enum
{
    PORT_A,
    PORT_B,
    PORT_C,
    PORT_D,
    PORT_E,
    PORT_F,
    PORT_G,
    PORT_H,
    PORT_I,
    PORT_J,
    PORT_K,
    PORT_L,
    PORT_M,
    PORT_N,
    PORT_O,
    PORT_P,
    PORT_Q,
    PORT_R,
    PORT_S,
    PORT_T,
    PORT_U,
    PORT_V,
    PORT_W,
    PORT_X,
    PORT_Y,
    PORT_Z,
    PORT_1,
    PORT_2,
    PORT_3,
    PORT_4,
    PORT_5,
    PORT_6,
    PORT_7,
    PORT_8,
    PORT_9,
    PORT_10,
    PORT_11,
    PORT_12,
    PORT_13,
    PORT_14,
    PORT_15,
    PORT_16,
    PORT_17,
    PORT_18,
    PORT_19,
    PORT_20,
    PORT_21,
    PORT_22,
    PORT_23,
    PORT_24,
    PORT_25,
    PORT_26
} GPIO_Port;

/**
 * @enum GPIO_Pin
 * @brief Enum for representing GPIO pin numbers.
 *
 * This enum provides symbolic names for GPIO pins, ranging from PIN_0 to PIN_32
 */
typedef enum
{
    PIN_0,
    PIN_1,
    PIN_2,
    PIN_3,
    PIN_4,
    PIN_5,
    PIN_6,
    PIN_7,
    PIN_8,
    PIN_9,
    PIN_10,
    PIN_11,
    PIN_12,
    PIN_13,
    PIN_14,
    PIN_15,
    PIN_16,
    PIN_17,
    PIN_18,
    PIN_19,
    PIN_20,
    PIN_21,
    PIN_22,
    PIN_23,
    PIN_24,
    PIN_25,
    PIN_26,
    PIN_27,
    PIN_28,
    PIN_29,
    PIN_30,
    PIN_31,
    PIN_32
} GPIO_Pin;

/**
 * @struct GPIO_PinStruct
 * @brief Structure representing a specific GPIO pin and port combination.
 *
 * This structure combines a GPIO port and pin to identify a unique pin on
 * the microcontroller. It is useful for passing pin information to GPIO
 * functions in a single argument.
 */
typedef struct
{
    GPIO_Port port;
    GPIO_Pin pin;
} GPIO_PinStruct;

#endif // _GIRGITWARE_PIN_H_
