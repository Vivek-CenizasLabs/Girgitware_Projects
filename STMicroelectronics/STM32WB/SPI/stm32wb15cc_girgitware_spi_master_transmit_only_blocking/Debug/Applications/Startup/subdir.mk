################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Debug Subdirectory relative path, to be changed in clean recipe too.
DEBUG_SUBDIRPATH := Applications/Startup
# Src Subdirectory relative path
SOURCE_SUBDIRPATH := ../$(DEBUG_SUBDIRPATH)

# Add inputs and outputs from these tool invocations to the build variables 

S_SRCS_xy = $(wildcard $(SOURCE_SUBDIRPATH)/*.s)
S_SRCS += $(S_SRCS_xy)

S_DEPS += \
$(patsubst $(SOURCE_SUBDIRPATH)/%.s, ./$(DEBUG_SUBDIRPATH)/%.d, $(S_SRCS_xy))

OBJS += \
$(patsubst $(SOURCE_SUBDIRPATH)/%.s, ./$(DEBUG_SUBDIRPATH)/%.o, $(S_SRCS_xy))

# Each subdirectory must supply rules for building sources it contributes
$(DEBUG_SUBDIRPATH)/%.o: $(SOURCE_SUBDIRPATH)/%.s $(DEBUG_SUBDIRPATH)/subdir.mk
	@echo 'Building file: $<'
	$(CC) -mcpu=cortex-m4 -g3 $(DFLAGS) -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
	@echo 'Done Building'

clean: clean-Core-2f-Startup

clean-Core-2f-Startup:
	$(eval DEBUG_SUBDIRPATH := Applications/Startup)
	@echo 'Removing files from $(DEBUG_SUBDIRPATH)'
	-$(RM) $(wildcard ./$(DEBUG_SUBDIRPATH)/*.d) $(wildcard ./$(DEBUG_SUBDIRPATH)/*.o)

.PHONY: clean-Core-2f-Startup
