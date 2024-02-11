################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LwIP/test/unit/dhcp/test_dhcp.c 

OBJS += \
./LwIP/test/unit/dhcp/test_dhcp.o 

C_DEPS += \
./LwIP/test/unit/dhcp/test_dhcp.d 


# Each subdirectory must supply rules for building sources it contributes
LwIP/test/unit/dhcp/%.o LwIP/test/unit/dhcp/%.su LwIP/test/unit/dhcp/%.cyclo: ../LwIP/test/unit/dhcp/%.c LwIP/test/unit/dhcp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L433xx -c -I"C:/Users/Sowa/Desktop/homeiov2 custom libs/HomeIOv2/LwIP/src/include" -I"C:/Users/Sowa/Desktop/homeiov2 custom libs/HomeIOv2/ethernet" -I"C:/Users/Sowa/Desktop/homeiov2 custom libs/HomeIOv2/ethernet/Src" -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LwIP-2f-test-2f-unit-2f-dhcp

clean-LwIP-2f-test-2f-unit-2f-dhcp:
	-$(RM) ./LwIP/test/unit/dhcp/test_dhcp.cyclo ./LwIP/test/unit/dhcp/test_dhcp.d ./LwIP/test/unit/dhcp/test_dhcp.o ./LwIP/test/unit/dhcp/test_dhcp.su

.PHONY: clean-LwIP-2f-test-2f-unit-2f-dhcp

