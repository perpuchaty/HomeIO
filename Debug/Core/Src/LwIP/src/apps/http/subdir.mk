################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/LwIP/src/apps/http/altcp_proxyconnect.c \
../Core/Src/LwIP/src/apps/http/fs.c \
../Core/Src/LwIP/src/apps/http/fsdata.c \
../Core/Src/LwIP/src/apps/http/http_client.c \
../Core/Src/LwIP/src/apps/http/httpd.c 

OBJS += \
./Core/Src/LwIP/src/apps/http/altcp_proxyconnect.o \
./Core/Src/LwIP/src/apps/http/fs.o \
./Core/Src/LwIP/src/apps/http/fsdata.o \
./Core/Src/LwIP/src/apps/http/http_client.o \
./Core/Src/LwIP/src/apps/http/httpd.o 

C_DEPS += \
./Core/Src/LwIP/src/apps/http/altcp_proxyconnect.d \
./Core/Src/LwIP/src/apps/http/fs.d \
./Core/Src/LwIP/src/apps/http/fsdata.d \
./Core/Src/LwIP/src/apps/http/http_client.d \
./Core/Src/LwIP/src/apps/http/httpd.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/LwIP/src/apps/http/%.o Core/Src/LwIP/src/apps/http/%.su Core/Src/LwIP/src/apps/http/%.cyclo: ../Core/Src/LwIP/src/apps/http/%.c Core/Src/LwIP/src/apps/http/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L433xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-LwIP-2f-src-2f-apps-2f-http

clean-Core-2f-Src-2f-LwIP-2f-src-2f-apps-2f-http:
	-$(RM) ./Core/Src/LwIP/src/apps/http/altcp_proxyconnect.cyclo ./Core/Src/LwIP/src/apps/http/altcp_proxyconnect.d ./Core/Src/LwIP/src/apps/http/altcp_proxyconnect.o ./Core/Src/LwIP/src/apps/http/altcp_proxyconnect.su ./Core/Src/LwIP/src/apps/http/fs.cyclo ./Core/Src/LwIP/src/apps/http/fs.d ./Core/Src/LwIP/src/apps/http/fs.o ./Core/Src/LwIP/src/apps/http/fs.su ./Core/Src/LwIP/src/apps/http/fsdata.cyclo ./Core/Src/LwIP/src/apps/http/fsdata.d ./Core/Src/LwIP/src/apps/http/fsdata.o ./Core/Src/LwIP/src/apps/http/fsdata.su ./Core/Src/LwIP/src/apps/http/http_client.cyclo ./Core/Src/LwIP/src/apps/http/http_client.d ./Core/Src/LwIP/src/apps/http/http_client.o ./Core/Src/LwIP/src/apps/http/http_client.su ./Core/Src/LwIP/src/apps/http/httpd.cyclo ./Core/Src/LwIP/src/apps/http/httpd.d ./Core/Src/LwIP/src/apps/http/httpd.o ./Core/Src/LwIP/src/apps/http/httpd.su

.PHONY: clean-Core-2f-Src-2f-LwIP-2f-src-2f-apps-2f-http

