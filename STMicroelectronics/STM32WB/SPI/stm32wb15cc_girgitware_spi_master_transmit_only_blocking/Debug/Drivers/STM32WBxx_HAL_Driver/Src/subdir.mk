################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Debug Subdirectory relative path
DEBUG_SUBDIRPATH := Drivers/STM32WBxx_HAL_Driver/Src
# Src Subdirectory relative path
SOURCE_SUBDIRPATH := ../$(DEBUG_SUBDIRPATH)

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_xy = \
$(wildcard $(SOURCE_SUBDIRPATH)/*.c)

C_SRCS += $(C_SRCS_xy)

C_DEPS += \
$(patsubst $(SOURCE_SUBDIRPATH)/%.c, ./$(DEBUG_SUBDIRPATH)/%.d, $(C_SRCS_xy))

OBJS += \
$(patsubst $(SOURCE_SUBDIRPATH)/%.c, ./$(DEBUG_SUBDIRPATH)/%.o, $(C_SRCS_xy))

# Each subdirectory must supply rules for building sources it contributes
$(DEBUG_SUBDIRPATH)/%.o: $(SOURCE_SUBDIRPATH)/%.c $(DEBUG_SUBDIRPATH)/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	$(CC) "$<" -mcpu=cortex-m4 -std=gnu11 -g3 $(DFLAGS) -c $(INCLUDE_FLAG_PATHS) -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Drivers-2f-$(DEBUG_SUBDIRPATH)-2f-Src

clean-Drivers-2f-$(DEBUG_SUBDIRPATH)-2f-Src:
	$(eval DEBUG_SUBDIRPATH := Drivers/STM32WBxx_HAL_Driver/Src)
	@echo 'Removing files from $(DEBUG_SUBDIRPATH)'
	-$(RM) $(wildcard ./$(DEBUG_SUBDIRPATH)/*.d) $(wildcard ./$(DEBUG_SUBDIRPATH)/*.o) $(wildcard ./$(DEBUG_SUBDIRPATH)/*.su)

.PHONY: clean-Drivers-2f-$(DEBUG_SUBDIRPATH)-2f-Src


