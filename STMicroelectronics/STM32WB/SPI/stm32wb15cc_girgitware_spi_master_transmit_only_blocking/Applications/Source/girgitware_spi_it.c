#include "girgitware_gpio.h"
#include "girgitware_spi.h"

extern SPI_Handle spiHandle;

void GW_SPI1_IRQHandler(void)
{
    /* USER CODE BEGIN */

    /* USER CODE END */

    // Pass the corresponding SPI handle to the SPI IRQ handler
    GW_SPI_IRQHandler(&spiHandle);

    /* USER CODE BEGIN */

    /* USER CODE END */
}

void GW_SPI_TxCpltCallback(SPI_Handle *userSPIHandle)
{
    // To unused argument(s) compilation warning and the user should remove the following line while defining the callback function
    (void)userSPIHandle;

    /* USER CODE BEGIN */

    /* USER CODE END */
}

void GW_SPI_RxCpltCallback(SPI_Handle *userSPIHandle)
{
    // To unused argument(s) compilation warning and the user should remove the following line while defining the callback function
    (void)userSPIHandle;

    /* USER CODE BEGIN */

    /* USER CODE END */
}

void GW_SPI_TxRxCpltCallback(SPI_Handle *userSPIHandle)
{
    // To unused argument(s) compilation warning and the user should remove the following line while defining the callback function
    (void)userSPIHandle;

    /* USER CODE BEGIN */

    /* USER CODE END */
}

void GW_SPI_TxHalfCpltCallback(SPI_Handle *userSPIHandle)
{
    // To unused argument(s) compilation warning and the user should remove the following line while defining the callback function
    (void)userSPIHandle;

    /* USER CODE BEGIN */

    /* USER CODE END */
}

void GW_SPI_RxHalfCpltCallback(SPI_Handle *userSPIHandle)
{
    // To unused argument(s) compilation warning and the user should remove the following line while defining the callback function
    (void)userSPIHandle;

    /* USER CODE BEGIN */

    /* USER CODE END */
}

void GW_SPI_TxRxHalfCpltCallback(SPI_Handle *userSPIHandle)
{
    // To unused argument(s) compilation warning and the user should remove the following line while defining the callback function
    (void)userSPIHandle;

    /* USER CODE BEGIN */

    /* USER CODE END */
}

void GW_SPI_ErrorCallback(SPI_Handle *userSPIHandle)
{
    // To unused argument(s) compilation warning and the user should remove the following line while defining the callback function
    (void)userSPIHandle;

    /* USER CODE BEGIN */

    /* USER CODE END */
}

void GW_SPI_AbortCpltCallback(SPI_Handle *userSPIHandle)
{
    // To unused argument(s) compilation warning and the user should remove the following line while defining the callback function
    (void)userSPIHandle;

    /* USER CODE BEGIN */

    /* USER CODE END */
}
