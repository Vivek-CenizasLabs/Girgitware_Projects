/**
 ******************************************************************************
 * @file    girgitware_spi.c
 * @author  Cenizas Labs Firmware Team
 * @brief   Source file for SPI module.
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

/* Includes ------------------------------------------------------------------*/
#include "girgitware.h"
#include "girgitware_spi.h"
#include "girgitware_link_tables.h"

/* Externally declare the SPI handle link table */
extern SPI_LinkTypeDef spiHandleLinkTable[SPI_HANDLE_LINK_TABLE_SIZE];

/* Function Definitions -----------------------------------------------------*/

SPI_Status SPI_Init(SPI_Handle *user_spi_handle) {
    // Check if the user handle is NULL
    if (user_spi_handle == NULL) {
        return SPI_ERROR; // Return error if handle is NULL
    }

    // Enable the clock for the SPI instance
    if (user_spi_handle->instance == SPI1) {
        __HAL_RCC_SPI1_CLK_ENABLE();
    }
#if defined(SPI2)
    else if (user_spi_handle->instance == SPI2) {
        __HAL_RCC_SPI2_CLK_ENABLE();
    }
#endif
#if defined(SPI3)
    else if (user_spi_handle->instance == SPI3) {
        __HAL_RCC_SPI3_CLK_ENABLE();
    }
#endif
#if defined(SPI4)
    else if (user_spi_handle->instance == SPI4) {
        __HAL_RCC_SPI4_CLK_ENABLE();
    }
#endif
#if defined(SPI5)
    else if (user_spi_handle->instance == SPI5) {
        __HAL_RCC_SPI5_CLK_ENABLE();
    }
#endif
#if defined(SPI6)
    else if (user_spi_handle->instance == SPI6) {
        __HAL_RCC_SPI6_CLK_ENABLE();
    }
#endif

    // Get the index for the corresponding SPI instance
    int index = GET_SPI_INDEX(user_spi_handle->instance);
    if (index < 0) {
        return SPI_ERROR; // Return error if index is invalid
    }

    // Access the SPI link table
    SPI_LinkTypeDef *link = &spiHandleLinkTable[index];

    // Assign the user handle to the link table's girgitware handle
    link->gwHandle = user_spi_handle;

    // Assign values from user handle to SDK handle
    link->sdkHandle.Instance = user_spi_handle->instance;
    link->sdkHandle.Init.Mode = user_spi_handle->init.deviceMode;
    link->sdkHandle.Init.Direction = user_spi_handle->init.direction;
    link->sdkHandle.Init.DataSize = user_spi_handle->init.dataFrameSize;
    link->sdkHandle.Init.CLKPolarity = user_spi_handle->init.clockPolarity;
    link->sdkHandle.Init.CLKPhase = user_spi_handle->init.clockPhase;
    link->sdkHandle.Init.NSS = user_spi_handle->init.chipSelectMode;
    link->sdkHandle.Init.FirstBit = user_spi_handle->init.bitOrder;
    link->sdkHandle.Init.TIMode = SPI_TIMODE_DISABLE; // Default value
    link->sdkHandle.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE; // Default value
    link->sdkHandle.Init.CRCPolynomial = 7; // Default value
    link->sdkHandle.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE; // Default value
    link->sdkHandle.Init.NSSPMode = SPI_NSS_PULSE_DISABLE; // Default value

    // Set the baud rate prescaler
    uint32_t sourceClockFrequency = user_spi_handle->init.sourceClockFrequency;
    uint32_t sclkFrequency = user_spi_handle->init.spiClockFrequency;
    uint32_t division = sourceClockFrequency / sclkFrequency;

    // Assign the best baud rate prescaler based on the division
    if (division <= 2) {
        link->sdkHandle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
    } else if (division <= 4) {
        link->sdkHandle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
    } else if (division <= 8) {
        link->sdkHandle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_8;
    } else if (division <= 16) {
        link->sdkHandle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
    } else if (division <= 32) {
        link->sdkHandle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_32;
    } else if (division <= 64) {
        link->sdkHandle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_64;
    } else if (division <= 128) {
        link->sdkHandle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_128;
    } else {
        link->sdkHandle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_256;
    }

    // Call the pin setup function
    if (user_spi_handle->pinSetup != NULL) {
        user_spi_handle->pinSetup(user_spi_handle);
    }

    // Enable interrupts if enabled in user handle
    if (user_spi_handle->init.interruptEnable) {
#if defined(SPI1)
        if (user_spi_handle->instance == SPI1) {
            HAL_NVIC_EnableIRQ(SPI1_IRQn);
        }
#endif
#if defined(SPI2)
        else if (user_spi_handle->instance == SPI2) {
            HAL_NVIC_EnableIRQ(SPI2_IRQn);
        }
#endif
#if defined(SPI3)
        else if (user_spi_handle->instance == SPI3) {
            HAL_NVIC_EnableIRQ(SPI3_IRQn);
        }
#endif
#if defined(SPI4)
        else if (user_spi_handle->instance == SPI4) {
            HAL_NVIC_EnableIRQ(SPI4_IRQn);
        }
#endif
#if defined(SPI5)
        else if (user_spi_handle->instance == SPI5) {
            HAL_NVIC_EnableIRQ(SPI5_IRQn);
        }
#endif
#if defined(SPI6)
        else if (user_spi_handle->instance == SPI6) {
            HAL_NVIC_EnableIRQ(SPI6_IRQn);
        }
#endif
    }

    // Call the SDK function to initialize the SPI module
    return (HAL_SPI_Init(&link->sdkHandle) == HAL_OK) ? SPI_OK : SPI_ERROR;
}

SPI_Status SPI_DeInit(SPI_Handle *user_spi_handle) {
    // Check if the user handle is NULL
    if (user_spi_handle == NULL) {
        return SPI_ERROR; // Return error if handle is NULL
    }

    // Get the index for the corresponding SPI instance
    int index = GET_SPI_INDEX(user_spi_handle->instance);
    if (index < 0) {
        return SPI_ERROR; // Return error if index is invalid
    }

    // Access the link table to get the corresponding SDK handle
    SPI_LinkTypeDef *link = &spiHandleLinkTable[index];

    // Deinitialize the SPI module using the SDK function
    if (HAL_SPI_DeInit(&link->sdkHandle) != HAL_OK) {
        return SPI_ERROR; // Return error if deinitialization fails
    }

    return SPI_OK; // Return success code
}

SPI_Status SPI_Transmit(SPI_Handle *user_spi_handle, const uint8_t *txData, uint16_t dataSize, uint16_t timeout) {
    // Check if the user handle or data pointer is NULL
    if (user_spi_handle == NULL || txData == NULL) {
        return SPI_ERROR; // Return error if handle or data is NULL
    }

    // Get the index for the corresponding SPI instance
    int index = GET_SPI_INDEX(user_spi_handle->instance);
    if (index < 0) {
        return SPI_ERROR; // Return error if index is invalid
    }

    // Access the link table to get the corresponding SDK handle
    SPI_LinkTypeDef *link = &spiHandleLinkTable[index];

    // Transmit the data using the SDK function
    HAL_StatusTypeDef halStatus = HAL_SPI_Transmit(&link->sdkHandle, (uint8_t *)txData, dataSize, timeout);

    // Map the HAL status code to SPI status code
    switch (halStatus) {
        case HAL_OK:
            return SPI_OK;
        case HAL_ERROR:
            return SPI_ERROR;
        case HAL_BUSY:
            return SPI_BUSY;
        default:
            return SPI_OTHER; // For any other status codes
    }
}

SPI_Status SPI_Receive(SPI_Handle *user_spi_handle, uint8_t *rxData, uint16_t dataSize, uint16_t timeout) {
    // Check if the user handle or data pointer is NULL
    if (user_spi_handle == NULL || rxData == NULL) {
        return SPI_ERROR; // Return error if handle or data is NULL
    }

    // Get the index for the corresponding SPI instance
    int index = GET_SPI_INDEX(user_spi_handle->instance);
    if (index < 0) {
        return SPI_ERROR; // Return error if index is invalid
    }

    // Access the link table to get the corresponding SDK handle
    SPI_LinkTypeDef *link = &spiHandleLinkTable[index];

    // Receive the data using the SDK function
    HAL_StatusTypeDef halStatus = HAL_SPI_Receive(&link->sdkHandle, rxData, dataSize, timeout);

    // Map the HAL status code to SPI status code
    switch (halStatus) {
        case HAL_OK:
            return SPI_OK;
        case HAL_ERROR:
            return SPI_ERROR;
        case HAL_BUSY:
            return SPI_BUSY;
        default:
            return SPI_OTHER; // For any other status codes
    }
}

SPI_Status SPI_TransmitReceive(SPI_Handle *user_spi_handle, const uint8_t *txData, uint8_t *rxData, uint16_t dataSize, uint16_t timeout) {
    // Check if the user handle or data pointers are NULL
    if (user_spi_handle == NULL || txData == NULL || rxData == NULL) {
        return SPI_ERROR; // Return error if handle or data pointers are NULL
    }

    // Get the index for the corresponding SPI instance
    int index = GET_SPI_INDEX(user_spi_handle->instance);
    if (index < 0) {
        return SPI_ERROR; // Return error if index is invalid
    }

    // Access the link table to get the corresponding SDK handle
    SPI_LinkTypeDef *link = &spiHandleLinkTable[index];

    // Transmit and receive data using the SDK function
    HAL_StatusTypeDef halStatus = HAL_SPI_TransmitReceive(&link->sdkHandle, (uint8_t *)txData, rxData, dataSize, timeout);

    // Map the HAL status code to SPI status code
    switch (halStatus) {
        case HAL_OK:
            return SPI_OK;
        case HAL_ERROR:
            return SPI_ERROR;
        case HAL_BUSY:
            return SPI_BUSY;
        default:
            return SPI_OTHER; // For any other status codes
    }
}

SPI_Status SPI_Transmit_IT(SPI_Handle *user_spi_handle, const uint8_t *txData, uint16_t dataSize) {
    // Check if the user handle or data pointer is NULL
    if (user_spi_handle == NULL || txData == NULL) {
        return SPI_ERROR; // Return error if handle or data is NULL
    }

    // Get the index for the corresponding SPI instance
    int index = GET_SPI_INDEX(user_spi_handle->instance);
    if (index < 0) {
        return SPI_ERROR; // Return error if index is invalid
    }

    // Access the link table to get the corresponding SDK handle
    SPI_LinkTypeDef *link = &spiHandleLinkTable[index];

    // Transmit data using the SDK function in interrupt mode
    HAL_StatusTypeDef halStatus = HAL_SPI_Transmit_IT(&link->sdkHandle, (uint8_t *)txData, dataSize);

    // Map the HAL status code to SPI status code
    switch (halStatus) {
        case HAL_OK:
            return SPI_OK;
        case HAL_ERROR:
            return SPI_ERROR;
        case HAL_BUSY:
            return SPI_BUSY;
        default:
            return SPI_OTHER; // For any other status codes
    }
}

SPI_Status SPI_Receive_IT(SPI_Handle *user_spi_handle, uint8_t *rxData, uint16_t dataSize) {
    // Check if the user handle or data pointer is NULL
    if (user_spi_handle == NULL || rxData == NULL) {
        return SPI_ERROR; // Return error if handle or data is NULL
    }

    // Get the index for the corresponding SPI instance
    int index = GET_SPI_INDEX(user_spi_handle->instance);
    if (index < 0) {
        return SPI_ERROR; // Return error if index is invalid
    }

    // Access the link table to get the corresponding SDK handle
    SPI_LinkTypeDef *link = &spiHandleLinkTable[index];

    // Receive data using the SDK function in interrupt mode
    HAL_StatusTypeDef halStatus = HAL_SPI_Receive_IT(&link->sdkHandle, rxData, dataSize);

    // Map the HAL status code to SPI status code
    switch (halStatus) {
        case HAL_OK:
            return SPI_OK;
        case HAL_ERROR:
            return SPI_ERROR;
        case HAL_BUSY:
            return SPI_BUSY;
        default:
            return SPI_OTHER; // For any other status codes
    }
}

SPI_Status SPI_TransmitReceive_IT(SPI_Handle *user_spi_handle, const uint8_t *txData, uint8_t *rxData, uint16_t dataSize) {
    // Check if the user handle or data pointers are NULL
    if (user_spi_handle == NULL || txData == NULL || rxData == NULL) {
        return SPI_ERROR; // Return error if handle or data pointers are NULL
    }

    // Get the index for the corresponding SPI instance
    int index = GET_SPI_INDEX(user_spi_handle->instance);
    if (index < 0) {
        return SPI_ERROR; // Return error if index is invalid
    }

    // Access the link table to get the corresponding SDK handle
    SPI_LinkTypeDef *link = &spiHandleLinkTable[index];

    // Transmit and receive data using the SDK function in interrupt mode
    HAL_StatusTypeDef halStatus = HAL_SPI_TransmitReceive_IT(&link->sdkHandle, (uint8_t *)txData, rxData, dataSize);

    // Map the HAL status code to SPI status code
    switch (halStatus) {
        case HAL_OK:
            return SPI_OK;
        case HAL_ERROR:
            return SPI_ERROR;
        case HAL_BUSY:
            return SPI_BUSY;
        default:
            return SPI_OTHER; // For any other status codes
    }
}

SPI_Status SPI_Abort(SPI_Handle *user_spi_handle) {
    // Check if the user handle is NULL
    if (user_spi_handle == NULL) {
        return SPI_ERROR; // Return error if handle is NULL
    }

    // Get the index for the corresponding SPI instance
    int index = GET_SPI_INDEX(user_spi_handle->instance);
    if (index < 0) {
        return SPI_ERROR; // Return error if index is invalid
    }

    // Access the link table to get the corresponding SDK handle
    SPI_LinkTypeDef *link = &spiHandleLinkTable[index];

    // Abort the SPI operation using the SDK function
    HAL_StatusTypeDef halStatus = HAL_SPI_Abort(&link->sdkHandle);

    // Map the HAL status code to SPI status code
    switch (halStatus) {
        case HAL_OK:
            return SPI_OK;
        case HAL_ERROR:
            return SPI_ERROR;
        case HAL_BUSY:
            return SPI_BUSY;
        default:
            return SPI_OTHER; // For any other status codes
    }
}

SPI_Status SPI_Abort_IT(SPI_Handle *user_spi_handle) {
    // Check if the user handle is NULL
    if (user_spi_handle == NULL) {
        return SPI_ERROR; // Return error if handle is NULL
    }

    // Get the index for the corresponding SPI instance
    int index = GET_SPI_INDEX(user_spi_handle->instance);
    if (index < 0) {
        return SPI_ERROR; // Return error if index is invalid
    }

    // Access the link table to get the corresponding SDK handle
    SPI_LinkTypeDef *link = &spiHandleLinkTable[index];

    // Abort the SPI operation in interrupt mode using the SDK function
    HAL_StatusTypeDef halStatus = HAL_SPI_Abort_IT(&link->sdkHandle);

    // Map the HAL status code to SPI status code
    switch (halStatus) {
        case HAL_OK:
            return SPI_OK;
        case HAL_ERROR:
            return SPI_ERROR;
        case HAL_BUSY:
            return SPI_BUSY;
        default:
            return SPI_OTHER; // For any other status codes
    }
}

/* Interrupt Handlers --------------------------------------------------------*/
#ifdef SPI1
void SPI1_IRQHandler(void) {
    GW_SPI1_IRQHandler();
}
#endif
#ifdef SPI2
void SPI2_IRQHandler(void) {
    GW_SPI2_IRQHandler();
}
#endif
#ifdef SPI3
void SPI3_IRQHandler(void) {
    GW_SPI3_IRQHandler();
}
#endif
#ifdef SPI4
void SPI4_IRQHandler(void) {
    GW_SPI4_IRQHandler();
}
#endif
#ifdef SPI5
void SPI5_IRQHandler(void) {
    GW_SPI5_IRQHandler();
}
#endif
#ifdef SPI6
void SPI6_IRQHandler(void) {
    GW_SPI6_IRQHandler();
}
#endif

void GW_SPI_IRQHandler(SPI_Handle *user_spi_handle) {
    // Check if the user handle is NULL
    if (user_spi_handle == NULL) {
        return; // Exit if handle is NULL
    }

    // Get the index for the corresponding SPI instance
    int index = GET_SPI_INDEX(user_spi_handle->instance);
    if (index < 0) {
        return; // Exit if index is invalid
    }

    // Access the link table to get the corresponding SDK handle
    SPI_LinkTypeDef *link = &spiHandleLinkTable[index];

    // Call the HAL SPI IRQ handler
    HAL_SPI_IRQHandler(&link->sdkHandle);
}

/* HAL Callback Functions ---------------------------------------------------*/
void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi) {
    // Get the index for the corresponding SPI instance
    uint16_t spiIndex = GET_SPI_INDEX(hspi->Instance);

    // Access the SPI_LinkTypeDef struct at the index in the spiHandleLinkTable array
    SPI_LinkTypeDef *linkEntry = &spiHandleLinkTable[spiIndex];

    // Call the user-defined callback function by passing the user handle
    GW_SPI_TxCpltCallback(linkEntry->gwHandle);
}

void HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef *hspi) {
    // Get the index for the corresponding SPI instance
    uint16_t spiIndex = GET_SPI_INDEX(hspi->Instance);

    // Access the SPI_LinkTypeDef struct at the index in the spiHandleLinkTable array
    SPI_LinkTypeDef *linkEntry = &spiHandleLinkTable[spiIndex];

    // Call the user-defined callback function by passing the user handle
    GW_SPI_TxRxCpltCallback(linkEntry->gwHandle);
}

void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi) {
    // Get the index for the corresponding SPI instance
    uint16_t spiIndex = GET_SPI_INDEX(hspi->Instance);

    // Access the SPI_LinkTypeDef struct at the index in the spiHandleLinkTable array
    SPI_LinkTypeDef *linkEntry = &spiHandleLinkTable[spiIndex];

    // Call the user-defined callback function by passing the user handle
    GW_SPI_RxCpltCallback(linkEntry->gwHandle);
}

void HAL_SPI_TxHalfCpltCallback(SPI_HandleTypeDef *hspi) {
    // Get the index for the corresponding SPI instance
    uint16_t spiIndex = GET_SPI_INDEX(hspi->Instance);

    // Access the SPI_LinkTypeDef struct at the index in the spiHandleLinkTable array
    SPI_LinkTypeDef *linkEntry = &spiHandleLinkTable[spiIndex];

    // Call the user-defined callback function by passing the user handle
    GW_SPI_TxHalfCpltCallback(linkEntry->gwHandle);
}

void HAL_SPI_RxHalfCpltCallback(SPI_HandleTypeDef *hspi) {
    // Get the index for the corresponding SPI instance
    uint16_t spiIndex = GET_SPI_INDEX(hspi->Instance);

    // Access the SPI_LinkTypeDef struct at the index in the spiHandleLinkTable array
    SPI_LinkTypeDef *linkEntry = &spiHandleLinkTable[spiIndex];

    // Call the user-defined callback function by passing the user handle
    GW_SPI_RxHalfCpltCallback(linkEntry->gwHandle);
}

void HAL_SPI_TxRxHalfCpltCallback(SPI_HandleTypeDef *hspi) {
    // Get the index for the corresponding SPI instance
    uint16_t spiIndex = GET_SPI_INDEX(hspi->Instance);

    // Access the SPI_LinkTypeDef struct at the index in the spiHandleLinkTable array
    SPI_LinkTypeDef *linkEntry = &spiHandleLinkTable[spiIndex];

    // Call the user-defined callback function by passing the user handle
    GW_SPI_TxRxHalfCpltCallback(linkEntry->gwHandle);
}

void HAL_SPI_ErrorCallback(SPI_HandleTypeDef *hspi) {
    // Get the index for the corresponding SPI instance
    uint16_t spiIndex = GET_SPI_INDEX(hspi->Instance);

    // Access the SPI_LinkTypeDef struct at the index in the spiHandleLinkTable array
    SPI_LinkTypeDef *linkEntry = &spiHandleLinkTable[spiIndex];

    // Call the user-defined callback function by passing the user handle
    GW_SPI_ErrorCallback(linkEntry->gwHandle);
}

void HAL_SPI_AbortCpltCallback(SPI_HandleTypeDef *hspi) {
    // Get the index for the corresponding SPI instance
    uint16_t spiIndex = GET_SPI_INDEX(hspi->Instance);

    // Access the SPI_LinkTypeDef struct at the index in the spiHandleLinkTable array
    SPI_LinkTypeDef *linkEntry = &spiHandleLinkTable[spiIndex];

    // Call the user-defined callback function by passing the user handle
    GW_SPI_AbortCpltCallback(linkEntry->gwHandle);
}
