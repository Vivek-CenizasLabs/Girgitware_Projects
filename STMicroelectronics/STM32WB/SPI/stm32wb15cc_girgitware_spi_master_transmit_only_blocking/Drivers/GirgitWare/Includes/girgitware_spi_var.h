/**
 ******************************************************************************
 * @file    girgitware_spi_var.h
 * @author  Cenizas Labs Firmware Team
 * @brief   Header file of variable components for girgitware's SPI module.
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
#ifndef _GIRGITWARE_SPI_VAR_H
#define _GIRGITWARE_SPI_VAR_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stddef.h>
#include "stm32wbxx_hal.h" // Include HAL header for STM32WB
#include "girgitware_pin.h"
#include "girgitware_pin_map.h"
#include "girgitware_spi_const.h" // Include constants for SPI

/**
 * @brief SPI Handle Structure definition
 */
typedef struct SPI_Handle
{
    SPI_InitHandle init; /*!< SPI initialization parameters */

    SPI_TypeDef *instance; /*!< SPI registers base address */

    void (*pinSetup)(struct SPI_Handle *); /*!< Function pointer for pin setup */

    // Additional members can be added here as needed

} SPI_Handle;

#ifdef __cplusplus
}
#endif

#endif /* _GIRGITWARE_SPI_VAR_H */
