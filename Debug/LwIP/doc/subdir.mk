################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LwIP/doc/NO_SYS_SampleCode.c \
../LwIP/doc/ZeroCopyRx.c 

OBJS += \
./LwIP/doc/NO_SYS_SampleCode.o \
./LwIP/doc/ZeroCopyRx.o 

C_DEPS += \
./LwIP/doc/NO_SYS_SampleCode.d \
./LwIP/doc/ZeroCopyRx.d 


# Each subdirectory must supply rules for building sources it contributes
LwIP/doc/%.o LwIP/doc/%.su LwIP/doc/%.cyclo: ../LwIP/doc/%.c LwIP/doc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L433xx -c -I"C:/Users/Sowa/Desktop/homeiov2 custom libs/HomeIOv2/LwIP/src/include" -I"C:/Users/Sowa/Desktop/homeiov2 custom libs/HomeIOv2/ethernet/Inc" -I"C:/Users/Sowa/Desktop/homeiov2 custom libs/HomeIOv2/ethernet" -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LwIP-2f-doc

clean-LwIP-2f-doc:
	-$(RM) ./LwIP/doc/NO_SYS_SampleCode.cyclo ./LwIP/doc/NO_SYS_SampleCode.d ./LwIP/doc/NO_SYS_SampleCode.o ./LwIP/doc/NO_SYS_SampleCode.su ./LwIP/doc/ZeroCopyRx.cyclo ./LwIP/doc/ZeroCopyRx.d ./LwIP/doc/ZeroCopyRx.o ./LwIP/doc/ZeroCopyRx.su

.PHONY: clean-LwIP-2f-doc

