################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LwIP/src/netif/bridgeif.c \
../LwIP/src/netif/bridgeif_fdb.c \
../LwIP/src/netif/ethernet.c \
../LwIP/src/netif/lowpan6.c \
../LwIP/src/netif/lowpan6_ble.c \
../LwIP/src/netif/lowpan6_common.c \
../LwIP/src/netif/slipif.c \
../LwIP/src/netif/zepif.c 

OBJS += \
./LwIP/src/netif/bridgeif.o \
./LwIP/src/netif/bridgeif_fdb.o \
./LwIP/src/netif/ethernet.o \
./LwIP/src/netif/lowpan6.o \
./LwIP/src/netif/lowpan6_ble.o \
./LwIP/src/netif/lowpan6_common.o \
./LwIP/src/netif/slipif.o \
./LwIP/src/netif/zepif.o 

C_DEPS += \
./LwIP/src/netif/bridgeif.d \
./LwIP/src/netif/bridgeif_fdb.d \
./LwIP/src/netif/ethernet.d \
./LwIP/src/netif/lowpan6.d \
./LwIP/src/netif/lowpan6_ble.d \
./LwIP/src/netif/lowpan6_common.d \
./LwIP/src/netif/slipif.d \
./LwIP/src/netif/zepif.d 


# Each subdirectory must supply rules for building sources it contributes
LwIP/src/netif/%.o LwIP/src/netif/%.su LwIP/src/netif/%.cyclo: ../LwIP/src/netif/%.c LwIP/src/netif/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L433xx -c -I"C:/Users/Sowa/Desktop/Elektronika/SOFTWARE/_GIT/HomeIO/HomeIOv2/LwIP/src/include" -I"C:/Users/Sowa/Desktop/Elektronika/SOFTWARE/_GIT/HomeIO/HomeIOv2/ethernet/Inc" -I"C:/Users/Sowa/Desktop/Elektronika/SOFTWARE/_GIT/HomeIO/HomeIOv2/ethernet/Src" -I"C:/Users/Sowa/Desktop/Elektronika/SOFTWARE/_GIT/HomeIO/HomeIOv2/ethernet/arch" -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LwIP-2f-src-2f-netif

clean-LwIP-2f-src-2f-netif:
	-$(RM) ./LwIP/src/netif/bridgeif.cyclo ./LwIP/src/netif/bridgeif.d ./LwIP/src/netif/bridgeif.o ./LwIP/src/netif/bridgeif.su ./LwIP/src/netif/bridgeif_fdb.cyclo ./LwIP/src/netif/bridgeif_fdb.d ./LwIP/src/netif/bridgeif_fdb.o ./LwIP/src/netif/bridgeif_fdb.su ./LwIP/src/netif/ethernet.cyclo ./LwIP/src/netif/ethernet.d ./LwIP/src/netif/ethernet.o ./LwIP/src/netif/ethernet.su ./LwIP/src/netif/lowpan6.cyclo ./LwIP/src/netif/lowpan6.d ./LwIP/src/netif/lowpan6.o ./LwIP/src/netif/lowpan6.su ./LwIP/src/netif/lowpan6_ble.cyclo ./LwIP/src/netif/lowpan6_ble.d ./LwIP/src/netif/lowpan6_ble.o ./LwIP/src/netif/lowpan6_ble.su ./LwIP/src/netif/lowpan6_common.cyclo ./LwIP/src/netif/lowpan6_common.d ./LwIP/src/netif/lowpan6_common.o ./LwIP/src/netif/lowpan6_common.su ./LwIP/src/netif/slipif.cyclo ./LwIP/src/netif/slipif.d ./LwIP/src/netif/slipif.o ./LwIP/src/netif/slipif.su ./LwIP/src/netif/zepif.cyclo ./LwIP/src/netif/zepif.d ./LwIP/src/netif/zepif.o ./LwIP/src/netif/zepif.su

.PHONY: clean-LwIP-2f-src-2f-netif

