/**
 ******************************************************************************
 * @file    girgitware_link_tables.h
 * @author  Cenizas Labs Firmware Team
 * @brief   This header file defines the peripheral link table structure and provides
 *          utility functions for peripheral instance indexing.
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

#ifndef _GIRGITWARE_LINK_TABLES_H
#define _GIRGITWARE_LINK_TABLES_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "girgitware_index.h"
#include "girgitware_spi_var.h"

    typedef struct
    {
        SPI_HandleTypeDef sdkHandle; /*!< SDK SPI Handle */
        SPI_Handle *gwHandle;        /*!< Girgitware SPI Handle */
    } SPI_LinkTypeDef;

    static inline int GET_SPI_INDEX(SPI_TypeDef *instance)
    {
        if (instance == SPI1)
        {
            return SPI1_LINK_TABLE_INDEX;
        }
#if defined(SPI2) && defined(SPI2_LINK_TABLE_INDEX)
        if (instance == SPI2)
        {
            return SPI2_LINK_TABLE_INDEX;
        }
#endif

#if defined(SPI3) && defined(SPI3_LINK_TABLE_INDEX)
        if (instance == SPI3)
        {
            return SPI3_LINK_TABLE_INDEX;
        }
#endif

#if defined(SPI4) && defined(SPI4_LINK_TABLE_INDEX)
        if (instance == SPI4)
        {
            return SPI4_LINK_TABLE_INDEX;
        }
#endif

#if defined(SPI5) && defined(SPI5_LINK_TABLE_INDEX)
        if (instance == SPI5)
        {
            return SPI5_LINK_TABLE_INDEX;
        }
#endif

#if defined(SPI6) && defined(SPI6_LINK_TABLE_INDEX)
        if (instance == SPI6)
        {
            return SPI6_LINK_TABLE_INDEX;
        }
#endif
        return -1; // Default case for unknown instances
    }

#ifdef __cplusplus
}
#endif

#endif /* _GIRGITWARE_LINK_TABLES_H */
