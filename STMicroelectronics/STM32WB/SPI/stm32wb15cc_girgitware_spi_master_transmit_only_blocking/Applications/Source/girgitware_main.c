#include "girgitware.h"
#include "girgitware_gpio.h"
#include "girgitware_spi.h"
#include <stdio.h>

/* Pin setup function declarations */
void SPI1_PinSetup(SPI_Handle *spiHandle);

// chip select initialization function
void chipSelect(void);

GPIO_Handle spiChipSelect = {0};


// SPI Handle declaration and initialization
SPI_Handle spiHandle = {

    .instance = SPI1, // SPI instance (e.g., SPI1, SPI2)

    // SPI_MODE_MASTER
    // SPI_MODE_SLAVE

    .init.deviceMode = SPI_MODE_MASTER, // Specifies the SPI operating mode.

    // SPI_DIRECTION_2LINES
    // SPI_DIRECTION_1LINE

    .init.direction = SPI_DIRECTION_2LINES, // Specifies the SPI direction.

    // SPI_DATASIZE_8BIT
    // SPI_DATASIZE_16BIT

    .init.dataFrameSize = SPI_DATASIZE_8BIT, // Specifies the SPI frame size.

    // SPI_POLARITY_LOW
    // SPI_POLARITY_HIGH

    .init.clockPolarity = SPI_POLARITY_LOW, // Specifies the clock polarity.

    // SPI_PHASE_1EDGE
    // SPI_PHASE_2EDGE

    .init.clockPhase = SPI_PHASE_1EDGE, // Specifies the clock phase.

    // SPI_NSS_SOFT
    // SPI_NSS_HARD_INPUT
    // SPI_NSS_HARD_OUTPUT

    .init.chipSelectMode = SPI_NSS_SOFT, // Specifies the SPI Chip Select management mode.

    // 1000000
    // 2000000
    // 4000000
    // 8000000

    .init.sourceClockFrequency = 4000000, // Specifies the SPI source clock frequency.

    // 1000000
    // 2000000
    // 4000000
    // 8000000

    .init.spiClockFrequency = 2000000, // Specifies the SPI clock frequency.

    // 0
    // 1

    .init.interruptEnable = 0, // Specifies the SPI interrupt enable.

    // 0
    // 1

    .pinSetup = SPI1_PinSetup, // Function pointer for pin setup.
};


// tx buffer
uint8_t txBuffer = 1;

int main(void)
{
    // Initialize GirgitWare
    GirgitWareInit();

    // Initialize SPI
    if (SPI_Init(&spiHandle) != SPI_OK)
    {
        printf("SPI initialization failed !\n");
        ErrorHandler();
    } else
    {
        printf("SPI initialization successful !\n");
    }

    // Initialize the chip select pin
    chipSelect();
    printf("SPI chip select setup successful !\n");

    printf("Starting transmission in blocking mode...\n");

    // Infinite loop to transmit data

    // Pull down the chip select pin to start transmission
    GPIO_Write(&spiChipSelect, GPIO_PIN_RESET); // CS low
    while (1)
    {
        // Transmit the data
        if (SPI_Transmit(&spiHandle, &txBuffer, 1, 100) != SPI_OK)
        {
            printf("SPI transmission failed !\n");
            ErrorHandler();
        } else
        {
            printf("SPI transmission successful !\n");
        }

        // Optionally add a delay or some other logic here
        DelayMS(2000); // Delay for 2 second
    }

    // No need to deinitialize SPI as per instructions
}

void SPI1_PinSetup(SPI_Handle *user_spi_handle)
{

    // GPIO Handle for SPI pins
    GPIO_Handle gpioHandle = {0};

    // Configure MISO pin (PA.11)
    gpioHandle.port = portMap[PORT_A];
    gpioHandle.pin = pinMap[PIN_11];
    gpioHandle.mode = GPIO_MODE_AF_PP;
    gpioHandle.pullUpPullDownSelect = GPIO_NO_PULL;
    gpioHandle.alternateFunction = GPIO_AF5_SPI1;
    gpioHandle.interruptEdge = GPIO_NO_INTERRUPT;
    GPIO_Init(&gpioHandle);

    // Configure MOSI pin (PA.5)
    gpioHandle.port = portMap[PORT_A];
    gpioHandle.pin = pinMap[PIN_5];
    gpioHandle.mode = GPIO_MODE_AF_PP;
    gpioHandle.pullUpPullDownSelect = GPIO_NO_PULL;
    gpioHandle.alternateFunction = GPIO_AF4_SPI1;
    gpioHandle.interruptEdge = GPIO_NO_INTERRUPT;
    GPIO_Init(&gpioHandle);

    // Configure Serial Clock (SCK) pin (PA.1)
    gpioHandle.port = portMap[PORT_A];
    gpioHandle.pin = pinMap[PIN_1];
    gpioHandle.mode = GPIO_MODE_AF_PP;
    gpioHandle.pullUpPullDownSelect = GPIO_NO_PULL;
    gpioHandle.alternateFunction = GPIO_AF5_SPI1;
    GPIO_Init(&gpioHandle);

    //    // Configure Chip Select pin (PA.4)
    //    gpioHandle.port = portMap[PORT_A];
    //    gpioHandle.pin = pinMap[PIN_4];
    //    gpioHandle.mode = (user_spi_handle->init->deviceMode == SPI_MASTER) ? GPIO_MODE_OUTPUT_PP : GPIO_MODE_INPUT;
    //    gpioHandle.pullUpPullDownSelect = GPIO_NO_PULL;
    //    gpioHandle.alternateFunction = GPIO_AF5_SPI1;
    //    GPIO_Init(&gpioHandle);
}

void chipSelect(void)
{
    // Configure CS pin (PA.6)
    spiChipSelect.port = portMap[PORT_A];
    spiChipSelect.pin = pinMap[PIN_6];
    spiChipSelect.mode = GPIO_MODE_OUTPUT_PP;
    spiChipSelect.pullUpPullDownSelect = GPIO_NO_PULL;
    GPIO_Init(&spiChipSelect);
}

/* for printf */
int _write(int file, char *ptr, int len)
{
    int i = 0;
    for (i = 0; i < len; i++)
    {
        ITM_SendChar((*ptr++));
    }
    return len;
}
