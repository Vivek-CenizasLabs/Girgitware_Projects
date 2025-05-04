/**
 ******************************************************************************
 * @file    girgitware_spi.h
 * @author  Cenizas Labs Firmware Team
 * @brief   Header file for SPI module.
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
#ifndef _GIRGITWARE_SPI_H_
#define _GIRGITWARE_SPI_H_

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include "girgitware_spi_var.h"

// Functions prototypes
SPI_Status SPI_Init(SPI_Handle *user_spi_handle);
SPI_Status SPI_DeInit(SPI_Handle *user_spi_handle);
SPI_Status SPI_Transmit(SPI_Handle *user_spi_handle, const uint8_t *txData, uint16_t dataSize, uint16_t timeout);
SPI_Status SPI_Receive(SPI_Handle *user_spi_handle, uint8_t *rxData, uint16_t dataSize, uint16_t timeout);
SPI_Status SPI_TransmitReceive(SPI_Handle *user_spi_handle, const uint8_t *txData, uint8_t *rxData, uint16_t dataSize, uint16_t timeout);
SPI_Status SPI_Transmit_IT(SPI_Handle *user_spi_handle, const uint8_t *txData, uint16_t dataSize);
SPI_Status SPI_Receive_IT(SPI_Handle *user_spi_handle, uint8_t *rxData, uint16_t dataSize);
SPI_Status SPI_TransmitReceive_IT(SPI_Handle *user_spi_handle, const uint8_t *txData, uint8_t *rxData, uint16_t dataSize);

SPI_Status SPI_Abort(SPI_Handle *user_spi_handle);
SPI_Status SPI_Abort_IT(SPI_Handle *user_spi_handle);

// IRQ Handlers
void GW_SPI_IRQHandler(SPI_Handle *user_spi_handle);

#ifdef SPI1
void GW_SPI1_IRQHandler(void);
#endif
#ifdef SPI2
void GW_SPI2_IRQHandler(void);
#endif
#ifdef SPI3
void GW_SPI3_IRQHandler(void);
#endif
#ifdef SPI4
void GW_SPI4_IRQHandler(void);
#endif
#ifdef SPI5
void GW_SPI5_IRQHandler(void);
#endif
#ifdef SPI6
void GW_SPI6_IRQHandler(void);
#endif

// Callbacks
void GW_SPI_TxCpltCallback(SPI_Handle *user_spi_handle);
void GW_SPI_RxCpltCallback(SPI_Handle *user_spi_handle);
void GW_SPI_TxRxCpltCallback(SPI_Handle *user_spi_handle);
void GW_SPI_TxHalfCpltCallback(SPI_Handle *user_spi_handle);
void GW_SPI_RxHalfCpltCallback(SPI_Handle *user_spi_handle);
void GW_SPI_TxRxHalfCpltCallback(SPI_Handle *user_spi_handle);
void GW_SPI_ErrorCallback(SPI_Handle *user_spi_handle);
void GW_SPI_AbortCpltCallback(SPI_Handle *user_spi_handle);

#ifdef __cplusplus
}
#endif

#endif /* _GIRGITWARE_SPI_H_ */
