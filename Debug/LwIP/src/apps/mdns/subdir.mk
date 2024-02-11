################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LwIP/src/apps/mdns/mdns.c 

OBJS += \
./LwIP/src/apps/mdns/mdns.o 

C_DEPS += \
./LwIP/src/apps/mdns/mdns.d 


# Each subdirectory must supply rules for building sources it contributes
LwIP/src/apps/mdns/%.o LwIP/src/apps/mdns/%.su LwIP/src/apps/mdns/%.cyclo: ../LwIP/src/apps/mdns/%.c LwIP/src/apps/mdns/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L433xx -c -I"C:/Users/Sowa/Desktop/homeiov2 custom libs/HomeIOv2/LwIP/src/include" -I"C:/Users/Sowa/Desktop/homeiov2 custom libs/HomeIOv2/ethernet/Inc" -I"C:/Users/Sowa/Desktop/homeiov2 custom libs/HomeIOv2/ethernet" -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LwIP-2f-src-2f-apps-2f-mdns

clean-LwIP-2f-src-2f-apps-2f-mdns:
	-$(RM) ./LwIP/src/apps/mdns/mdns.cyclo ./LwIP/src/apps/mdns/mdns.d ./LwIP/src/apps/mdns/mdns.o ./LwIP/src/apps/mdns/mdns.su

.PHONY: clean-LwIP-2f-src-2f-apps-2f-mdns

