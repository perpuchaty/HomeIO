################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LwIP/src/core/ipv4/autoip.c \
../LwIP/src/core/ipv4/dhcp.c \
../LwIP/src/core/ipv4/etharp.c \
../LwIP/src/core/ipv4/icmp.c \
../LwIP/src/core/ipv4/igmp.c \
../LwIP/src/core/ipv4/ip4.c \
../LwIP/src/core/ipv4/ip4_addr.c \
../LwIP/src/core/ipv4/ip4_frag.c 

OBJS += \
./LwIP/src/core/ipv4/autoip.o \
./LwIP/src/core/ipv4/dhcp.o \
./LwIP/src/core/ipv4/etharp.o \
./LwIP/src/core/ipv4/icmp.o \
./LwIP/src/core/ipv4/igmp.o \
./LwIP/src/core/ipv4/ip4.o \
./LwIP/src/core/ipv4/ip4_addr.o \
./LwIP/src/core/ipv4/ip4_frag.o 

C_DEPS += \
./LwIP/src/core/ipv4/autoip.d \
./LwIP/src/core/ipv4/dhcp.d \
./LwIP/src/core/ipv4/etharp.d \
./LwIP/src/core/ipv4/icmp.d \
./LwIP/src/core/ipv4/igmp.d \
./LwIP/src/core/ipv4/ip4.d \
./LwIP/src/core/ipv4/ip4_addr.d \
./LwIP/src/core/ipv4/ip4_frag.d 


# Each subdirectory must supply rules for building sources it contributes
LwIP/src/core/ipv4/%.o LwIP/src/core/ipv4/%.su LwIP/src/core/ipv4/%.cyclo: ../LwIP/src/core/ipv4/%.c LwIP/src/core/ipv4/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L433xx -c -I"C:/Users/Sowa/Desktop/Elektronika/SOFTWARE/_GIT/HomeIO/HomeIOv2/LwIP/src/include" -I"C:/Users/Sowa/Desktop/Elektronika/SOFTWARE/_GIT/HomeIO/HomeIOv2/ethernet/Inc" -I"C:/Users/Sowa/Desktop/Elektronika/SOFTWARE/_GIT/HomeIO/HomeIOv2/ethernet/Src" -I"C:/Users/Sowa/Desktop/Elektronika/SOFTWARE/_GIT/HomeIO/HomeIOv2/ethernet/arch" -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LwIP-2f-src-2f-core-2f-ipv4

clean-LwIP-2f-src-2f-core-2f-ipv4:
	-$(RM) ./LwIP/src/core/ipv4/autoip.cyclo ./LwIP/src/core/ipv4/autoip.d ./LwIP/src/core/ipv4/autoip.o ./LwIP/src/core/ipv4/autoip.su ./LwIP/src/core/ipv4/dhcp.cyclo ./LwIP/src/core/ipv4/dhcp.d ./LwIP/src/core/ipv4/dhcp.o ./LwIP/src/core/ipv4/dhcp.su ./LwIP/src/core/ipv4/etharp.cyclo ./LwIP/src/core/ipv4/etharp.d ./LwIP/src/core/ipv4/etharp.o ./LwIP/src/core/ipv4/etharp.su ./LwIP/src/core/ipv4/icmp.cyclo ./LwIP/src/core/ipv4/icmp.d ./LwIP/src/core/ipv4/icmp.o ./LwIP/src/core/ipv4/icmp.su ./LwIP/src/core/ipv4/igmp.cyclo ./LwIP/src/core/ipv4/igmp.d ./LwIP/src/core/ipv4/igmp.o ./LwIP/src/core/ipv4/igmp.su ./LwIP/src/core/ipv4/ip4.cyclo ./LwIP/src/core/ipv4/ip4.d ./LwIP/src/core/ipv4/ip4.o ./LwIP/src/core/ipv4/ip4.su ./LwIP/src/core/ipv4/ip4_addr.cyclo ./LwIP/src/core/ipv4/ip4_addr.d ./LwIP/src/core/ipv4/ip4_addr.o ./LwIP/src/core/ipv4/ip4_addr.su ./LwIP/src/core/ipv4/ip4_frag.cyclo ./LwIP/src/core/ipv4/ip4_frag.d ./LwIP/src/core/ipv4/ip4_frag.o ./LwIP/src/core/ipv4/ip4_frag.su

.PHONY: clean-LwIP-2f-src-2f-core-2f-ipv4

