################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Compilers
CC = arm-none-eabi-gcc
CCSIZE = arm-none-eabi-size
CCDUMP = arm-none-eabi-objdump
DFLAGS = -DDEBUG -DUSE_HAL_DRIVER -DSTM32WB15xx

-include ../makefile.init

RM := del

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/GirgitWare/Source/subdir.mk
-include Drivers/STM32WBxx_HAL_Driver/Src/subdir.mk
-include Applications/Source/subdir.mk
-include Applications/Startup/subdir.mk
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# User dependent variables
LINKER_SCRIPT = ../STM32WB15CCUX_FLASH.ld

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := STM32WB
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
$(BUILD_ARTIFACT_NAME).elf \

MAP_FILES += \
$(BUILD_ARTIFACT_NAME).map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
$(BUILD_ARTIFACT_NAME).list \

# All Target
all: main-build

# Main-build Target
main-build: $(BUILD_ARTIFACT_NAME).elf secondary-outputs

# Tool invocations
$(BUILD_ARTIFACT_NAME).elf $(BUILD_ARTIFACT_NAME).map: $(OBJS) $(USER_OBJS) $(LINKER_SCRIPT) makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	$(CC) -o "STM32WB.elf" $(OBJS) $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"$(LINKER_SCRIPT)" --specs=nosys.specs -Wl,-Map="STM32WB.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group $(DFLAGS)
	@echo 'Finished building target: $@'
	@echo ' '
	
default.size.stdout: $(EXECUTABLES) makefile $(OPTIONAL_TOOL_DEPS)
	$(CCSIZE) $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

$(BUILD_ARTIFACT_NAME).list: $(EXECUTABLES) makefile $(OPTIONAL_TOOL_DEPS)
	$(CCDUMP) -h -S $(EXECUTABLES) > "$(BUILD_ARTIFACT_NAME).list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BUILD_ARTIFACT_NAME).elf $(BUILD_ARTIFACT_NAME).list $(BUILD_ARTIFACT_NAME).map default.size.stdout
	-@echo ' '
	
secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets


