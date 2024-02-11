################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LwIP/test/unit/tcp/tcp_helper.c \
../LwIP/test/unit/tcp/test_tcp.c \
../LwIP/test/unit/tcp/test_tcp_oos.c 

OBJS += \
./LwIP/test/unit/tcp/tcp_helper.o \
./LwIP/test/unit/tcp/test_tcp.o \
./LwIP/test/unit/tcp/test_tcp_oos.o 

C_DEPS += \
./LwIP/test/unit/tcp/tcp_helper.d \
./LwIP/test/unit/tcp/test_tcp.d \
./LwIP/test/unit/tcp/test_tcp_oos.d 


# Each subdirectory must supply rules for building sources it contributes
LwIP/test/unit/tcp/%.o LwIP/test/unit/tcp/%.su LwIP/test/unit/tcp/%.cyclo: ../LwIP/test/unit/tcp/%.c LwIP/test/unit/tcp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L433xx -c -I"C:/Users/Sowa/Desktop/homeiov2 custom libs/HomeIOv2/LwIP/src/include" -I"C:/Users/Sowa/Desktop/homeiov2 custom libs/HomeIOv2/ethernet" -I"C:/Users/Sowa/Desktop/homeiov2 custom libs/HomeIOv2/ethernet/Src" -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LwIP-2f-test-2f-unit-2f-tcp

clean-LwIP-2f-test-2f-unit-2f-tcp:
	-$(RM) ./LwIP/test/unit/tcp/tcp_helper.cyclo ./LwIP/test/unit/tcp/tcp_helper.d ./LwIP/test/unit/tcp/tcp_helper.o ./LwIP/test/unit/tcp/tcp_helper.su ./LwIP/test/unit/tcp/test_tcp.cyclo ./LwIP/test/unit/tcp/test_tcp.d ./LwIP/test/unit/tcp/test_tcp.o ./LwIP/test/unit/tcp/test_tcp.su ./LwIP/test/unit/tcp/test_tcp_oos.cyclo ./LwIP/test/unit/tcp/test_tcp_oos.d ./LwIP/test/unit/tcp/test_tcp_oos.o ./LwIP/test/unit/tcp/test_tcp_oos.su

.PHONY: clean-LwIP-2f-test-2f-unit-2f-tcp

