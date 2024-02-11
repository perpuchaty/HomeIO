################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LwIP/src/core/ipv6/dhcp6.c \
../LwIP/src/core/ipv6/ethip6.c \
../LwIP/src/core/ipv6/icmp6.c \
../LwIP/src/core/ipv6/inet6.c \
../LwIP/src/core/ipv6/ip6.c \
../LwIP/src/core/ipv6/ip6_addr.c \
../LwIP/src/core/ipv6/ip6_frag.c \
../LwIP/src/core/ipv6/mld6.c \
../LwIP/src/core/ipv6/nd6.c 

OBJS += \
./LwIP/src/core/ipv6/dhcp6.o \
./LwIP/src/core/ipv6/ethip6.o \
./LwIP/src/core/ipv6/icmp6.o \
./LwIP/src/core/ipv6/inet6.o \
./LwIP/src/core/ipv6/ip6.o \
./LwIP/src/core/ipv6/ip6_addr.o \
./LwIP/src/core/ipv6/ip6_frag.o \
./LwIP/src/core/ipv6/mld6.o \
./LwIP/src/core/ipv6/nd6.o 

C_DEPS += \
./LwIP/src/core/ipv6/dhcp6.d \
./LwIP/src/core/ipv6/ethip6.d \
./LwIP/src/core/ipv6/icmp6.d \
./LwIP/src/core/ipv6/inet6.d \
./LwIP/src/core/ipv6/ip6.d \
./LwIP/src/core/ipv6/ip6_addr.d \
./LwIP/src/core/ipv6/ip6_frag.d \
./LwIP/src/core/ipv6/mld6.d \
./LwIP/src/core/ipv6/nd6.d 


# Each subdirectory must supply rules for building sources it contributes
LwIP/src/core/ipv6/%.o LwIP/src/core/ipv6/%.su LwIP/src/core/ipv6/%.cyclo: ../LwIP/src/core/ipv6/%.c LwIP/src/core/ipv6/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L433xx -c -I"C:/Users/Sowa/Desktop/Elektronika/SOFTWARE/_GIT/HomeIO/HomeIOv2/LwIP/src/include" -I"C:/Users/Sowa/Desktop/Elektronika/SOFTWARE/_GIT/HomeIO/HomeIOv2/ethernet/Inc" -I"C:/Users/Sowa/Desktop/Elektronika/SOFTWARE/_GIT/HomeIO/HomeIOv2/ethernet/Src" -I"C:/Users/Sowa/Desktop/Elektronika/SOFTWARE/_GIT/HomeIO/HomeIOv2/ethernet/arch" -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LwIP-2f-src-2f-core-2f-ipv6

clean-LwIP-2f-src-2f-core-2f-ipv6:
	-$(RM) ./LwIP/src/core/ipv6/dhcp6.cyclo ./LwIP/src/core/ipv6/dhcp6.d ./LwIP/src/core/ipv6/dhcp6.o ./LwIP/src/core/ipv6/dhcp6.su ./LwIP/src/core/ipv6/ethip6.cyclo ./LwIP/src/core/ipv6/ethip6.d ./LwIP/src/core/ipv6/ethip6.o ./LwIP/src/core/ipv6/ethip6.su ./LwIP/src/core/ipv6/icmp6.cyclo ./LwIP/src/core/ipv6/icmp6.d ./LwIP/src/core/ipv6/icmp6.o ./LwIP/src/core/ipv6/icmp6.su ./LwIP/src/core/ipv6/inet6.cyclo ./LwIP/src/core/ipv6/inet6.d ./LwIP/src/core/ipv6/inet6.o ./LwIP/src/core/ipv6/inet6.su ./LwIP/src/core/ipv6/ip6.cyclo ./LwIP/src/core/ipv6/ip6.d ./LwIP/src/core/ipv6/ip6.o ./LwIP/src/core/ipv6/ip6.su ./LwIP/src/core/ipv6/ip6_addr.cyclo ./LwIP/src/core/ipv6/ip6_addr.d ./LwIP/src/core/ipv6/ip6_addr.o ./LwIP/src/core/ipv6/ip6_addr.su ./LwIP/src/core/ipv6/ip6_frag.cyclo ./LwIP/src/core/ipv6/ip6_frag.d ./LwIP/src/core/ipv6/ip6_frag.o ./LwIP/src/core/ipv6/ip6_frag.su ./LwIP/src/core/ipv6/mld6.cyclo ./LwIP/src/core/ipv6/mld6.d ./LwIP/src/core/ipv6/mld6.o ./LwIP/src/core/ipv6/mld6.su ./LwIP/src/core/ipv6/nd6.cyclo ./LwIP/src/core/ipv6/nd6.d ./LwIP/src/core/ipv6/nd6.o ./LwIP/src/core/ipv6/nd6.su

.PHONY: clean-LwIP-2f-src-2f-core-2f-ipv6

