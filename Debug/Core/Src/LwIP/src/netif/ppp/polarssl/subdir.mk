################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/LwIP/src/netif/ppp/polarssl/arc4.c \
../Core/Src/LwIP/src/netif/ppp/polarssl/des.c \
../Core/Src/LwIP/src/netif/ppp/polarssl/md4.c \
../Core/Src/LwIP/src/netif/ppp/polarssl/md5.c \
../Core/Src/LwIP/src/netif/ppp/polarssl/sha1.c 

OBJS += \
./Core/Src/LwIP/src/netif/ppp/polarssl/arc4.o \
./Core/Src/LwIP/src/netif/ppp/polarssl/des.o \
./Core/Src/LwIP/src/netif/ppp/polarssl/md4.o \
./Core/Src/LwIP/src/netif/ppp/polarssl/md5.o \
./Core/Src/LwIP/src/netif/ppp/polarssl/sha1.o 

C_DEPS += \
./Core/Src/LwIP/src/netif/ppp/polarssl/arc4.d \
./Core/Src/LwIP/src/netif/ppp/polarssl/des.d \
./Core/Src/LwIP/src/netif/ppp/polarssl/md4.d \
./Core/Src/LwIP/src/netif/ppp/polarssl/md5.d \
./Core/Src/LwIP/src/netif/ppp/polarssl/sha1.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/LwIP/src/netif/ppp/polarssl/%.o Core/Src/LwIP/src/netif/ppp/polarssl/%.su Core/Src/LwIP/src/netif/ppp/polarssl/%.cyclo: ../Core/Src/LwIP/src/netif/ppp/polarssl/%.c Core/Src/LwIP/src/netif/ppp/polarssl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L433xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-LwIP-2f-src-2f-netif-2f-ppp-2f-polarssl

clean-Core-2f-Src-2f-LwIP-2f-src-2f-netif-2f-ppp-2f-polarssl:
	-$(RM) ./Core/Src/LwIP/src/netif/ppp/polarssl/arc4.cyclo ./Core/Src/LwIP/src/netif/ppp/polarssl/arc4.d ./Core/Src/LwIP/src/netif/ppp/polarssl/arc4.o ./Core/Src/LwIP/src/netif/ppp/polarssl/arc4.su ./Core/Src/LwIP/src/netif/ppp/polarssl/des.cyclo ./Core/Src/LwIP/src/netif/ppp/polarssl/des.d ./Core/Src/LwIP/src/netif/ppp/polarssl/des.o ./Core/Src/LwIP/src/netif/ppp/polarssl/des.su ./Core/Src/LwIP/src/netif/ppp/polarssl/md4.cyclo ./Core/Src/LwIP/src/netif/ppp/polarssl/md4.d ./Core/Src/LwIP/src/netif/ppp/polarssl/md4.o ./Core/Src/LwIP/src/netif/ppp/polarssl/md4.su ./Core/Src/LwIP/src/netif/ppp/polarssl/md5.cyclo ./Core/Src/LwIP/src/netif/ppp/polarssl/md5.d ./Core/Src/LwIP/src/netif/ppp/polarssl/md5.o ./Core/Src/LwIP/src/netif/ppp/polarssl/md5.su ./Core/Src/LwIP/src/netif/ppp/polarssl/sha1.cyclo ./Core/Src/LwIP/src/netif/ppp/polarssl/sha1.d ./Core/Src/LwIP/src/netif/ppp/polarssl/sha1.o ./Core/Src/LwIP/src/netif/ppp/polarssl/sha1.su

.PHONY: clean-Core-2f-Src-2f-LwIP-2f-src-2f-netif-2f-ppp-2f-polarssl

