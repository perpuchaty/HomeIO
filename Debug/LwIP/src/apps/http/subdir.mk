################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LwIP/src/apps/http/altcp_proxyconnect.c \
../LwIP/src/apps/http/fs.c \
../LwIP/src/apps/http/fsdata.c \
../LwIP/src/apps/http/http_client.c \
../LwIP/src/apps/http/httpd.c 

OBJS += \
./LwIP/src/apps/http/altcp_proxyconnect.o \
./LwIP/src/apps/http/fs.o \
./LwIP/src/apps/http/fsdata.o \
./LwIP/src/apps/http/http_client.o \
./LwIP/src/apps/http/httpd.o 

C_DEPS += \
./LwIP/src/apps/http/altcp_proxyconnect.d \
./LwIP/src/apps/http/fs.d \
./LwIP/src/apps/http/fsdata.d \
./LwIP/src/apps/http/http_client.d \
./LwIP/src/apps/http/httpd.d 


# Each subdirectory must supply rules for building sources it contributes
LwIP/src/apps/http/%.o LwIP/src/apps/http/%.su LwIP/src/apps/http/%.cyclo: ../LwIP/src/apps/http/%.c LwIP/src/apps/http/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L433xx -c -I"C:/Users/Sowa/Desktop/homeiov2 custom libs/HomeIOv2/LwIP/src/include" -I"C:/Users/Sowa/Desktop/homeiov2 custom libs/HomeIOv2/ethernet/Inc" -I"C:/Users/Sowa/Desktop/homeiov2 custom libs/HomeIOv2/ethernet" -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LwIP-2f-src-2f-apps-2f-http

clean-LwIP-2f-src-2f-apps-2f-http:
	-$(RM) ./LwIP/src/apps/http/altcp_proxyconnect.cyclo ./LwIP/src/apps/http/altcp_proxyconnect.d ./LwIP/src/apps/http/altcp_proxyconnect.o ./LwIP/src/apps/http/altcp_proxyconnect.su ./LwIP/src/apps/http/fs.cyclo ./LwIP/src/apps/http/fs.d ./LwIP/src/apps/http/fs.o ./LwIP/src/apps/http/fs.su ./LwIP/src/apps/http/fsdata.cyclo ./LwIP/src/apps/http/fsdata.d ./LwIP/src/apps/http/fsdata.o ./LwIP/src/apps/http/fsdata.su ./LwIP/src/apps/http/http_client.cyclo ./LwIP/src/apps/http/http_client.d ./LwIP/src/apps/http/http_client.o ./LwIP/src/apps/http/http_client.su ./LwIP/src/apps/http/httpd.cyclo ./LwIP/src/apps/http/httpd.d ./LwIP/src/apps/http/httpd.o ./LwIP/src/apps/http/httpd.su

.PHONY: clean-LwIP-2f-src-2f-apps-2f-http

