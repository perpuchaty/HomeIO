################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LwIP/src/apps/altcp_tls/altcp_tls_mbedtls.c \
../LwIP/src/apps/altcp_tls/altcp_tls_mbedtls_mem.c 

OBJS += \
./LwIP/src/apps/altcp_tls/altcp_tls_mbedtls.o \
./LwIP/src/apps/altcp_tls/altcp_tls_mbedtls_mem.o 

C_DEPS += \
./LwIP/src/apps/altcp_tls/altcp_tls_mbedtls.d \
./LwIP/src/apps/altcp_tls/altcp_tls_mbedtls_mem.d 


# Each subdirectory must supply rules for building sources it contributes
LwIP/src/apps/altcp_tls/%.o LwIP/src/apps/altcp_tls/%.su LwIP/src/apps/altcp_tls/%.cyclo: ../LwIP/src/apps/altcp_tls/%.c LwIP/src/apps/altcp_tls/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L433xx -c -I"C:/Users/Sowa/Desktop/Elektronika/SOFTWARE/_GIT/HomeIO/HomeIOv2/LwIP/src/include" -I"C:/Users/Sowa/Desktop/Elektronika/SOFTWARE/_GIT/HomeIO/HomeIOv2/ethernet/Inc" -I"C:/Users/Sowa/Desktop/Elektronika/SOFTWARE/_GIT/HomeIO/HomeIOv2/ethernet/Src" -I"C:/Users/Sowa/Desktop/Elektronika/SOFTWARE/_GIT/HomeIO/HomeIOv2/ethernet/arch" -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LwIP-2f-src-2f-apps-2f-altcp_tls

clean-LwIP-2f-src-2f-apps-2f-altcp_tls:
	-$(RM) ./LwIP/src/apps/altcp_tls/altcp_tls_mbedtls.cyclo ./LwIP/src/apps/altcp_tls/altcp_tls_mbedtls.d ./LwIP/src/apps/altcp_tls/altcp_tls_mbedtls.o ./LwIP/src/apps/altcp_tls/altcp_tls_mbedtls.su ./LwIP/src/apps/altcp_tls/altcp_tls_mbedtls_mem.cyclo ./LwIP/src/apps/altcp_tls/altcp_tls_mbedtls_mem.d ./LwIP/src/apps/altcp_tls/altcp_tls_mbedtls_mem.o ./LwIP/src/apps/altcp_tls/altcp_tls_mbedtls_mem.su

.PHONY: clean-LwIP-2f-src-2f-apps-2f-altcp_tls

