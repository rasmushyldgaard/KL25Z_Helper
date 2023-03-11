################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/_sleep/_sleep.c 

OBJS += \
./source/_sleep/_sleep.o 

C_DEPS += \
./source/_sleep/_sleep.d 


# Each subdirectory must supply rules for building sources it contributes
source/_sleep/%.o: ../source/_sleep/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -DSDK_OS_BAREMETAL -DFSL_RTOS_BM -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\rasmu\Documents\MCUXpressoIDE_11.4.0_6237\workspace\1_kl25z_helper\board" -I"C:\Users\rasmu\Documents\MCUXpressoIDE_11.4.0_6237\workspace\1_kl25z_helper\source" -I"C:\Users\rasmu\Documents\MCUXpressoIDE_11.4.0_6237\workspace\1_kl25z_helper" -I"C:\Users\rasmu\Documents\MCUXpressoIDE_11.4.0_6237\workspace\1_kl25z_helper\startup" -I"C:\Users\rasmu\Documents\MCUXpressoIDE_11.4.0_6237\workspace\1_kl25z_helper\CMSIS" -I"C:\Users\rasmu\Documents\MCUXpressoIDE_11.4.0_6237\workspace\1_kl25z_helper\drivers" -I"C:\Users\rasmu\Documents\MCUXpressoIDE_11.4.0_6237\workspace\1_kl25z_helper\utilities" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


