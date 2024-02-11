################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LwIP/src/netif/ppp/polarssl/arc4.c \
../LwIP/src/netif/ppp/polarssl/des.c \
../LwIP/src/netif/ppp/polarssl/md4.c \
../LwIP/src/netif/ppp/polarssl/md5.c \
../LwIP/src/netif/ppp/polarssl/sha1.c 

OBJS += \
./LwIP/src/netif/ppp/polarssl/arc4.o \
./LwIP/src/netif/ppp/polarssl/des.o \
./LwIP/src/netif/ppp/polarssl/md4.o \
./LwIP/src/netif/ppp/polarssl/md5.o \
./LwIP/src/netif/ppp/polarssl/sha1.o 

C_DEPS += \
./LwIP/src/netif/ppp/polarssl/arc4.d \
./LwIP/src/netif/ppp/polarssl/des.d \
./LwIP/src/netif/ppp/polarssl/md4.d \
./LwIP/src/netif/ppp/polarssl/md5.d \
./LwIP/src/netif/ppp/polarssl/sha1.d 


# Each subdirectory must supply rules for building sources it contributes
LwIP/src/netif/ppp/polarssl/%.o LwIP/src/netif/ppp/polarssl/%.su LwIP/src/netif/ppp/polarssl/%.cyclo: ../LwIP/src/netif/ppp/polarssl/%.c LwIP/src/netif/ppp/polarssl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L433xx -c -I"C:/Users/Sowa/Desktop/Elektronika/SOFTWARE/_GIT/HomeIO/HomeIOv2/LwIP/src/include" -I"C:/Users/Sowa/Desktop/Elektronika/SOFTWARE/_GIT/HomeIO/HomeIOv2/ethernet/Inc" -I"C:/Users/Sowa/Desktop/Elektronika/SOFTWARE/_GIT/HomeIO/HomeIOv2/ethernet/Src" -I"C:/Users/Sowa/Desktop/Elektronika/SOFTWARE/_GIT/HomeIO/HomeIOv2/ethernet/arch" -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LwIP-2f-src-2f-netif-2f-ppp-2f-polarssl

clean-LwIP-2f-src-2f-netif-2f-ppp-2f-polarssl:
	-$(RM) ./LwIP/src/netif/ppp/polarssl/arc4.cyclo ./LwIP/src/netif/ppp/polarssl/arc4.d ./LwIP/src/netif/ppp/polarssl/arc4.o ./LwIP/src/netif/ppp/polarssl/arc4.su ./LwIP/src/netif/ppp/polarssl/des.cyclo ./LwIP/src/netif/ppp/polarssl/des.d ./LwIP/src/netif/ppp/polarssl/des.o ./LwIP/src/netif/ppp/polarssl/des.su ./LwIP/src/netif/ppp/polarssl/md4.cyclo ./LwIP/src/netif/ppp/polarssl/md4.d ./LwIP/src/netif/ppp/polarssl/md4.o ./LwIP/src/netif/ppp/polarssl/md4.su ./LwIP/src/netif/ppp/polarssl/md5.cyclo ./LwIP/src/netif/ppp/polarssl/md5.d ./LwIP/src/netif/ppp/polarssl/md5.o ./LwIP/src/netif/ppp/polarssl/md5.su ./LwIP/src/netif/ppp/polarssl/sha1.cyclo ./LwIP/src/netif/ppp/polarssl/sha1.d ./LwIP/src/netif/ppp/polarssl/sha1.o ./LwIP/src/netif/ppp/polarssl/sha1.su

.PHONY: clean-LwIP-2f-src-2f-netif-2f-ppp-2f-polarssl

