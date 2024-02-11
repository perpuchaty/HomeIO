################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ethernet/Src/enc28j60.c \
../ethernet/Src/enchw.c \
../ethernet/Src/mchdrv.c 

OBJS += \
./ethernet/Src/enc28j60.o \
./ethernet/Src/enchw.o \
./ethernet/Src/mchdrv.o 

C_DEPS += \
./ethernet/Src/enc28j60.d \
./ethernet/Src/enchw.d \
./ethernet/Src/mchdrv.d 


# Each subdirectory must supply rules for building sources it contributes
ethernet/Src/%.o ethernet/Src/%.su ethernet/Src/%.cyclo: ../ethernet/Src/%.c ethernet/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L433xx -c -I"C:/Users/Sowa/Desktop/Elektronika/SOFTWARE/_GIT/HomeIO/HomeIOv2/LwIP/src/include" -I"C:/Users/Sowa/Desktop/Elektronika/SOFTWARE/_GIT/HomeIO/HomeIOv2/ethernet/Inc" -I"C:/Users/Sowa/Desktop/Elektronika/SOFTWARE/_GIT/HomeIO/HomeIOv2/ethernet/Src" -I"C:/Users/Sowa/Desktop/Elektronika/SOFTWARE/_GIT/HomeIO/HomeIOv2/ethernet/arch" -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ethernet-2f-Src

clean-ethernet-2f-Src:
	-$(RM) ./ethernet/Src/enc28j60.cyclo ./ethernet/Src/enc28j60.d ./ethernet/Src/enc28j60.o ./ethernet/Src/enc28j60.su ./ethernet/Src/enchw.cyclo ./ethernet/Src/enchw.d ./ethernet/Src/enchw.o ./ethernet/Src/enchw.su ./ethernet/Src/mchdrv.cyclo ./ethernet/Src/mchdrv.d ./ethernet/Src/mchdrv.o ./ethernet/Src/mchdrv.su

.PHONY: clean-ethernet-2f-Src

