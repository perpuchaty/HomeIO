################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LwIP/test/unit/core/test_def.c \
../LwIP/test/unit/core/test_mem.c \
../LwIP/test/unit/core/test_netif.c \
../LwIP/test/unit/core/test_pbuf.c \
../LwIP/test/unit/core/test_timers.c 

OBJS += \
./LwIP/test/unit/core/test_def.o \
./LwIP/test/unit/core/test_mem.o \
./LwIP/test/unit/core/test_netif.o \
./LwIP/test/unit/core/test_pbuf.o \
./LwIP/test/unit/core/test_timers.o 

C_DEPS += \
./LwIP/test/unit/core/test_def.d \
./LwIP/test/unit/core/test_mem.d \
./LwIP/test/unit/core/test_netif.d \
./LwIP/test/unit/core/test_pbuf.d \
./LwIP/test/unit/core/test_timers.d 


# Each subdirectory must supply rules for building sources it contributes
LwIP/test/unit/core/%.o LwIP/test/unit/core/%.su LwIP/test/unit/core/%.cyclo: ../LwIP/test/unit/core/%.c LwIP/test/unit/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L433xx -c -I"C:/Users/Sowa/Desktop/homeiov2 custom libs/HomeIOv2/LwIP/src/include" -I"C:/Users/Sowa/Desktop/homeiov2 custom libs/HomeIOv2/ethernet" -I"C:/Users/Sowa/Desktop/homeiov2 custom libs/HomeIOv2/ethernet/Src" -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LwIP-2f-test-2f-unit-2f-core

clean-LwIP-2f-test-2f-unit-2f-core:
	-$(RM) ./LwIP/test/unit/core/test_def.cyclo ./LwIP/test/unit/core/test_def.d ./LwIP/test/unit/core/test_def.o ./LwIP/test/unit/core/test_def.su ./LwIP/test/unit/core/test_mem.cyclo ./LwIP/test/unit/core/test_mem.d ./LwIP/test/unit/core/test_mem.o ./LwIP/test/unit/core/test_mem.su ./LwIP/test/unit/core/test_netif.cyclo ./LwIP/test/unit/core/test_netif.d ./LwIP/test/unit/core/test_netif.o ./LwIP/test/unit/core/test_netif.su ./LwIP/test/unit/core/test_pbuf.cyclo ./LwIP/test/unit/core/test_pbuf.d ./LwIP/test/unit/core/test_pbuf.o ./LwIP/test/unit/core/test_pbuf.su ./LwIP/test/unit/core/test_timers.cyclo ./LwIP/test/unit/core/test_timers.d ./LwIP/test/unit/core/test_timers.o ./LwIP/test/unit/core/test_timers.su

.PHONY: clean-LwIP-2f-test-2f-unit-2f-core

