################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LwIP/test/fuzz/fuzz.c 

OBJS += \
./LwIP/test/fuzz/fuzz.o 

C_DEPS += \
./LwIP/test/fuzz/fuzz.d 


# Each subdirectory must supply rules for building sources it contributes
LwIP/test/fuzz/%.o LwIP/test/fuzz/%.su LwIP/test/fuzz/%.cyclo: ../LwIP/test/fuzz/%.c LwIP/test/fuzz/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L433xx -c -I"C:/Users/Sowa/Desktop/homeiov2 custom libs/HomeIOv2/LwIP/src/include" -I"C:/Users/Sowa/Desktop/homeiov2 custom libs/HomeIOv2/ethernet" -I"C:/Users/Sowa/Desktop/homeiov2 custom libs/HomeIOv2/ethernet/Src" -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LwIP-2f-test-2f-fuzz

clean-LwIP-2f-test-2f-fuzz:
	-$(RM) ./LwIP/test/fuzz/fuzz.cyclo ./LwIP/test/fuzz/fuzz.d ./LwIP/test/fuzz/fuzz.o ./LwIP/test/fuzz/fuzz.su

.PHONY: clean-LwIP-2f-test-2f-fuzz

