################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include utilities/subdir.mk
-include startup/subdir.mk
-include source/sw_debounce/subdir.mk
-include source/pit_driver/subdir.mk
-include source/gpio_driver/subdir.mk
-include source/examples/subdir.mk
-include source/_sleep/subdir.mk
-include source/subdir.mk
-include drivers/subdir.mk
-include board/subdir.mk
-include CMSIS/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: 1_kl25z_helper.axf

# Tool invocations
1_kl25z_helper.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -Xlinker -Map="1_kl25z_helper.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -Xlinker --sort-section=alignment -Xlinker --cref -mcpu=cortex-m0plus -mthumb -T 1_kl25z_helper_Debug.ld -o "1_kl25z_helper.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) 1_kl25z_helper.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "1_kl25z_helper.axf"; # arm-none-eabi-objcopy -v -O binary "1_kl25z_helper.axf" "1_kl25z_helper.bin" ; # checksum -p MKL25Z128xxx4 -d "1_kl25z_helper.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
