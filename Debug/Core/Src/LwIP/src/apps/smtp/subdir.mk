################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/LwIP/src/apps/smtp/smtp.c 

OBJS += \
./Core/Src/LwIP/src/apps/smtp/smtp.o 

C_DEPS += \
./Core/Src/LwIP/src/apps/smtp/smtp.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/LwIP/src/apps/smtp/%.o Core/Src/LwIP/src/apps/smtp/%.su Core/Src/LwIP/src/apps/smtp/%.cyclo: ../Core/Src/LwIP/src/apps/smtp/%.c Core/Src/LwIP/src/apps/smtp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L433xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-LwIP-2f-src-2f-apps-2f-smtp

clean-Core-2f-Src-2f-LwIP-2f-src-2f-apps-2f-smtp:
	-$(RM) ./Core/Src/LwIP/src/apps/smtp/smtp.cyclo ./Core/Src/LwIP/src/apps/smtp/smtp.d ./Core/Src/LwIP/src/apps/smtp/smtp.o ./Core/Src/LwIP/src/apps/smtp/smtp.su

.PHONY: clean-Core-2f-Src-2f-LwIP-2f-src-2f-apps-2f-smtp

