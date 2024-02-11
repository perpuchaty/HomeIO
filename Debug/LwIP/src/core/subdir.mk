################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LwIP/src/core/altcp.c \
../LwIP/src/core/altcp_alloc.c \
../LwIP/src/core/altcp_tcp.c \
../LwIP/src/core/def.c \
../LwIP/src/core/dns.c \
../LwIP/src/core/inet_chksum.c \
../LwIP/src/core/init.c \
../LwIP/src/core/ip.c \
../LwIP/src/core/mem.c \
../LwIP/src/core/memp.c \
../LwIP/src/core/netif.c \
../LwIP/src/core/pbuf.c \
../LwIP/src/core/raw.c \
../LwIP/src/core/stats.c \
../LwIP/src/core/sys.c \
../LwIP/src/core/tcp.c \
../LwIP/src/core/tcp_in.c \
../LwIP/src/core/tcp_out.c \
../LwIP/src/core/timeouts.c \
../LwIP/src/core/udp.c 

OBJS += \
./LwIP/src/core/altcp.o \
./LwIP/src/core/altcp_alloc.o \
./LwIP/src/core/altcp_tcp.o \
./LwIP/src/core/def.o \
./LwIP/src/core/dns.o \
./LwIP/src/core/inet_chksum.o \
./LwIP/src/core/init.o \
./LwIP/src/core/ip.o \
./LwIP/src/core/mem.o \
./LwIP/src/core/memp.o \
./LwIP/src/core/netif.o \
./LwIP/src/core/pbuf.o \
./LwIP/src/core/raw.o \
./LwIP/src/core/stats.o \
./LwIP/src/core/sys.o \
./LwIP/src/core/tcp.o \
./LwIP/src/core/tcp_in.o \
./LwIP/src/core/tcp_out.o \
./LwIP/src/core/timeouts.o \
./LwIP/src/core/udp.o 

C_DEPS += \
./LwIP/src/core/altcp.d \
./LwIP/src/core/altcp_alloc.d \
./LwIP/src/core/altcp_tcp.d \
./LwIP/src/core/def.d \
./LwIP/src/core/dns.d \
./LwIP/src/core/inet_chksum.d \
./LwIP/src/core/init.d \
./LwIP/src/core/ip.d \
./LwIP/src/core/mem.d \
./LwIP/src/core/memp.d \
./LwIP/src/core/netif.d \
./LwIP/src/core/pbuf.d \
./LwIP/src/core/raw.d \
./LwIP/src/core/stats.d \
./LwIP/src/core/sys.d \
./LwIP/src/core/tcp.d \
./LwIP/src/core/tcp_in.d \
./LwIP/src/core/tcp_out.d \
./LwIP/src/core/timeouts.d \
./LwIP/src/core/udp.d 


# Each subdirectory must supply rules for building sources it contributes
LwIP/src/core/%.o LwIP/src/core/%.su LwIP/src/core/%.cyclo: ../LwIP/src/core/%.c LwIP/src/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L433xx -c -I"C:/Users/Sowa/Desktop/Elektronika/SOFTWARE/_GIT/HomeIO/HomeIOv2/LwIP/src/include" -I"C:/Users/Sowa/Desktop/Elektronika/SOFTWARE/_GIT/HomeIO/HomeIOv2/ethernet/Inc" -I"C:/Users/Sowa/Desktop/Elektronika/SOFTWARE/_GIT/HomeIO/HomeIOv2/ethernet/Src" -I"C:/Users/Sowa/Desktop/Elektronika/SOFTWARE/_GIT/HomeIO/HomeIOv2/ethernet/arch" -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LwIP-2f-src-2f-core

clean-LwIP-2f-src-2f-core:
	-$(RM) ./LwIP/src/core/altcp.cyclo ./LwIP/src/core/altcp.d ./LwIP/src/core/altcp.o ./LwIP/src/core/altcp.su ./LwIP/src/core/altcp_alloc.cyclo ./LwIP/src/core/altcp_alloc.d ./LwIP/src/core/altcp_alloc.o ./LwIP/src/core/altcp_alloc.su ./LwIP/src/core/altcp_tcp.cyclo ./LwIP/src/core/altcp_tcp.d ./LwIP/src/core/altcp_tcp.o ./LwIP/src/core/altcp_tcp.su ./LwIP/src/core/def.cyclo ./LwIP/src/core/def.d ./LwIP/src/core/def.o ./LwIP/src/core/def.su ./LwIP/src/core/dns.cyclo ./LwIP/src/core/dns.d ./LwIP/src/core/dns.o ./LwIP/src/core/dns.su ./LwIP/src/core/inet_chksum.cyclo ./LwIP/src/core/inet_chksum.d ./LwIP/src/core/inet_chksum.o ./LwIP/src/core/inet_chksum.su ./LwIP/src/core/init.cyclo ./LwIP/src/core/init.d ./LwIP/src/core/init.o ./LwIP/src/core/init.su ./LwIP/src/core/ip.cyclo ./LwIP/src/core/ip.d ./LwIP/src/core/ip.o ./LwIP/src/core/ip.su ./LwIP/src/core/mem.cyclo ./LwIP/src/core/mem.d ./LwIP/src/core/mem.o ./LwIP/src/core/mem.su ./LwIP/src/core/memp.cyclo ./LwIP/src/core/memp.d ./LwIP/src/core/memp.o ./LwIP/src/core/memp.su ./LwIP/src/core/netif.cyclo ./LwIP/src/core/netif.d ./LwIP/src/core/netif.o ./LwIP/src/core/netif.su ./LwIP/src/core/pbuf.cyclo ./LwIP/src/core/pbuf.d ./LwIP/src/core/pbuf.o ./LwIP/src/core/pbuf.su ./LwIP/src/core/raw.cyclo ./LwIP/src/core/raw.d ./LwIP/src/core/raw.o ./LwIP/src/core/raw.su ./LwIP/src/core/stats.cyclo ./LwIP/src/core/stats.d ./LwIP/src/core/stats.o ./LwIP/src/core/stats.su ./LwIP/src/core/sys.cyclo ./LwIP/src/core/sys.d ./LwIP/src/core/sys.o ./LwIP/src/core/sys.su ./LwIP/src/core/tcp.cyclo ./LwIP/src/core/tcp.d ./LwIP/src/core/tcp.o ./LwIP/src/core/tcp.su ./LwIP/src/core/tcp_in.cyclo ./LwIP/src/core/tcp_in.d ./LwIP/src/core/tcp_in.o ./LwIP/src/core/tcp_in.su ./LwIP/src/core/tcp_out.cyclo ./LwIP/src/core/tcp_out.d ./LwIP/src/core/tcp_out.o ./LwIP/src/core/tcp_out.su ./LwIP/src/core/timeouts.cyclo ./LwIP/src/core/timeouts.d ./LwIP/src/core/timeouts.o ./LwIP/src/core/timeouts.su ./LwIP/src/core/udp.cyclo ./LwIP/src/core/udp.d ./LwIP/src/core/udp.o ./LwIP/src/core/udp.su

.PHONY: clean-LwIP-2f-src-2f-core

