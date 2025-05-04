/**
 ******************************************************************************
 * @file    girgitware_spi_const.h
 * @author  Cenizas Labs Firmware Team
 * @brief   Header file of constant components for girgitware's SPI module.
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
#ifndef _GIRGITWARE_SPI_CONST_H
#define _GIRGITWARE_SPI_CONST_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include "girgitware_pin.h"

    typedef enum
    {
        SPI_OK,
        SPI_ERROR,
        SPI_BUSY,
        SPI_IDLE,
        SPI_OTHER
    } SPI_Status;

    /**
     * @brief SPI Init Structure definition
     */

    typedef struct
    {
        uint32_t deviceMode; /*!< Specifies the SPI operating mode. */

        uint32_t clockPolarity; /*!< Specifies the clock polarity. */

        uint32_t clockPhase; /*!< Specifies the clock phase. */

        uint32_t direction; /*!< Specifies the SPI direction. */

        uint32_t bitOrder; /*!< Specifies the SPI bit order. */

        uint32_t dataFrameSize; /*!< Specifies the SPI frame size. */

        uint32_t sourceClockFrequency; /*!< Specifies the SPI source clock frequency*/

        uint32_t spiClockFrequency; /*!< Specifies the SPI source clock frequency*/

        uint32_t chipSelectMode; /*!< Specifies the SPI Chip Select management mode. */

        uint32_t interruptEnable; /*!< Specifies the SPI interrupt enable. */

    } SPI_InitHandle;

#ifdef __cplusplus
}
#endif

#endif /* _GIRGITWARE_SPI_CONST_H */
