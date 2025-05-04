#include "girgitware_gpio.h"
#include "girgitware.h"

/**
 * @brief  Initializes the specified GPIO pin.
 * @param  gpio_handle: Pointer to a GPIO_Handle structure that contains
 *         the configuration information for the specified GPIO pin.
 * @retval None
 */
void GPIO_Init(GPIO_Handle* gpio_handle) {
    if (gpio_handle == NULL) {
        return;  // Handle null pointer
    }

    // Enable the clock for the specified GPIO port
    #ifdef GPIOA
    if (gpio_handle->port == GPIOA) {
        __HAL_RCC_GPIOA_CLK_ENABLE();
    }
    #endif

    #ifdef GPIOB
    if (gpio_handle->port == GPIOB) {
        __HAL_RCC_GPIOB_CLK_ENABLE();
    }
    #endif

    #ifdef GPIOC
    if (gpio_handle->port == GPIOC) {
        __HAL_RCC_GPIOC_CLK_ENABLE();
    }
    #endif

    #ifdef GPIOD
    if (gpio_handle->port == GPIOD) {
        __HAL_RCC_GPIOD_CLK_ENABLE();
    }
    #endif

    #ifdef GPIOE
    if (gpio_handle->port == GPIOE) {
        __HAL_RCC_GPIOE_CLK_ENABLE();
    }
    #endif

    #ifdef GPIOH
    if (gpio_handle->port == GPIOH) {
        __HAL_RCC_GPIOH_CLK_ENABLE();
    }
    #endif

    // Initialize the GPIO_InitTypeDef structure
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // Set the pin using the SDK-defined macros
    GPIO_InitStruct.Pin = gpio_handle->pin;

    // Set the mode, default to output push-pull if not specified
    GPIO_InitStruct.Mode = (gpio_handle->mode != 0) ? gpio_handle->mode : GPIO_MODE_OUTPUT_PP;

    // Set the pull-up/pull-down configuration, default to no pull
    GPIO_InitStruct.Pull = (gpio_handle->pullUpPullDownSelect != 0) ? gpio_handle->pullUpPullDownSelect : GPIO_NOPULL;

    // Set the speed, default to low speed
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

    // Set the alternate function if specified
    if (gpio_handle->alternateFunction != 0) {
        GPIO_InitStruct.Alternate = gpio_handle->alternateFunction;
    }

    // Initialize the GPIO with the configured settings
    HAL_GPIO_Init(gpio_handle->port, &GPIO_InitStruct);
}

/**
 * @brief  Deinitializes the specified GPIO pin.
 * @param  gpio_handle: Pointer to a GPIO_Handle structure that contains
 *         the configuration information for the specified GPIO pin.
 * @retval None
 */
void GPIO_DeInit(GPIO_Handle* gpio_handle) {
    if (gpio_handle == NULL) {
        return;  // Handle null pointer
    }

    // Deinitialize the specified GPIO pin using HAL function
    HAL_GPIO_DeInit(gpio_handle->port, gpio_handle->pin);
}

/**
 * @brief  Reads the state of the specified GPIO pin.
 * @param  gpio_handle: Pointer to a GPIO_Handle structure that contains
 *         the configuration information for the specified GPIO pin.
 * @retval PinState: The state of the pin (PIN_HIGH or PIN_LOW).
 */
PinState GPIO_Read(GPIO_Handle* gpio_handle) {
    if (gpio_handle == NULL) {
        return PIN_LOW;  // Handle null pointer by returning a default value
    }

    // Read the pin state using HAL function
    GPIO_PinState pinState = HAL_GPIO_ReadPin(gpio_handle->port, gpio_handle->pin);

    // Convert HAL GPIO_PinState to PinState
    return (pinState == GPIO_PIN_SET) ? PIN_HIGH : PIN_LOW;
}

/**
 * @brief  Writes a state to the specified GPIO pin.
 * @param  gpio_handle: Pointer to a GPIO_Handle structure that contains
 *         the configuration information for the specified GPIO pin.
 * @param  value: The state to write to the pin (PIN_HIGH or PIN_LOW).
 * @retval None
 */
void GPIO_Write(GPIO_Handle* gpio_handle, PinState value) {
    if (gpio_handle == NULL) {
        return;  // Handle null pointer
    }

    // Convert PinState to HAL GPIO_PinState
    GPIO_PinState pinState = (value == PIN_HIGH) ? GPIO_PIN_SET : GPIO_PIN_RESET;

    // Write the pin state using HAL function
    HAL_GPIO_WritePin(gpio_handle->port, gpio_handle->pin, pinState);
}

/**
 * @brief  Toggles the state of the specified GPIO pin.
 * @param  gpio_handle: Pointer to a GPIO_Handle structure that contains
 *         the configuration information for the specified GPIO pin.
 * @retval None
 */
void GPIO_Toggle(GPIO_Handle* gpio_handle) {
    if (gpio_handle == NULL) {
        return;  // Handle null pointer
    }

    // Toggle the pin state using HAL function
    HAL_GPIO_TogglePin(gpio_handle->port, gpio_handle->pin);
}
