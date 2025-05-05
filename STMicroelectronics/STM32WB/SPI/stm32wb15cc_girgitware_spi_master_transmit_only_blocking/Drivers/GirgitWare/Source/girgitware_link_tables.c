/**
 ******************************************************************************
 * @file    girgitware_link_tables.c
 * @author  Cenizas Labs Firmware Team
 * @brief   Source file for peripheral link table structure.
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

#include "girgitware_link_tables.h"

#if defined (HAL_SPI_MODULE_ENABLED)
SPI_LinkTypeDef spiHandleLinkTable[SPI_HANDLE_LINK_TABLE_SIZE] = {0};
#endif
