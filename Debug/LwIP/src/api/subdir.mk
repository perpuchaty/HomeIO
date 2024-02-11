################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LwIP/src/api/api_lib.c \
../LwIP/src/api/api_msg.c \
../LwIP/src/api/err.c \
../LwIP/src/api/if_api.c \
../LwIP/src/api/netbuf.c \
../LwIP/src/api/netdb.c \
../LwIP/src/api/netifapi.c \
../LwIP/src/api/sockets.c \
../LwIP/src/api/tcpip.c 

OBJS += \
./LwIP/src/api/api_lib.o \
./LwIP/src/api/api_msg.o \
./LwIP/src/api/err.o \
./LwIP/src/api/if_api.o \
./LwIP/src/api/netbuf.o \
./LwIP/src/api/netdb.o \
./LwIP/src/api/netifapi.o \
./LwIP/src/api/sockets.o \
./LwIP/src/api/tcpip.o 

C_DEPS += \
./LwIP/src/api/api_lib.d \
./LwIP/src/api/api_msg.d \
./LwIP/src/api/err.d \
./LwIP/src/api/if_api.d \
./LwIP/src/api/netbuf.d \
./LwIP/src/api/netdb.d \
./LwIP/src/api/netifapi.d \
./LwIP/src/api/sockets.d \
./LwIP/src/api/tcpip.d 


# Each subdirectory must supply rules for building sources it contributes
LwIP/src/api/%.o LwIP/src/api/%.su LwIP/src/api/%.cyclo: ../LwIP/src/api/%.c LwIP/src/api/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L433xx -c -I"C:/Users/Sowa/Desktop/Elektronika/SOFTWARE/_GIT/HomeIO/HomeIOv2/LwIP/src/include" -I"C:/Users/Sowa/Desktop/Elektronika/SOFTWARE/_GIT/HomeIO/HomeIOv2/ethernet/Inc" -I"C:/Users/Sowa/Desktop/Elektronika/SOFTWARE/_GIT/HomeIO/HomeIOv2/ethernet/Src" -I"C:/Users/Sowa/Desktop/Elektronika/SOFTWARE/_GIT/HomeIO/HomeIOv2/ethernet/arch" -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LwIP-2f-src-2f-api

clean-LwIP-2f-src-2f-api:
	-$(RM) ./LwIP/src/api/api_lib.cyclo ./LwIP/src/api/api_lib.d ./LwIP/src/api/api_lib.o ./LwIP/src/api/api_lib.su ./LwIP/src/api/api_msg.cyclo ./LwIP/src/api/api_msg.d ./LwIP/src/api/api_msg.o ./LwIP/src/api/api_msg.su ./LwIP/src/api/err.cyclo ./LwIP/src/api/err.d ./LwIP/src/api/err.o ./LwIP/src/api/err.su ./LwIP/src/api/if_api.cyclo ./LwIP/src/api/if_api.d ./LwIP/src/api/if_api.o ./LwIP/src/api/if_api.su ./LwIP/src/api/netbuf.cyclo ./LwIP/src/api/netbuf.d ./LwIP/src/api/netbuf.o ./LwIP/src/api/netbuf.su ./LwIP/src/api/netdb.cyclo ./LwIP/src/api/netdb.d ./LwIP/src/api/netdb.o ./LwIP/src/api/netdb.su ./LwIP/src/api/netifapi.cyclo ./LwIP/src/api/netifapi.d ./LwIP/src/api/netifapi.o ./LwIP/src/api/netifapi.su ./LwIP/src/api/sockets.cyclo ./LwIP/src/api/sockets.d ./LwIP/src/api/sockets.o ./LwIP/src/api/sockets.su ./LwIP/src/api/tcpip.cyclo ./LwIP/src/api/tcpip.d ./LwIP/src/api/tcpip.o ./LwIP/src/api/tcpip.su

.PHONY: clean-LwIP-2f-src-2f-api

