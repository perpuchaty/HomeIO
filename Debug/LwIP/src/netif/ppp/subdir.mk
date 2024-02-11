################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LwIP/src/netif/ppp/auth.c \
../LwIP/src/netif/ppp/ccp.c \
../LwIP/src/netif/ppp/chap-md5.c \
../LwIP/src/netif/ppp/chap-new.c \
../LwIP/src/netif/ppp/chap_ms.c \
../LwIP/src/netif/ppp/demand.c \
../LwIP/src/netif/ppp/eap.c \
../LwIP/src/netif/ppp/ecp.c \
../LwIP/src/netif/ppp/eui64.c \
../LwIP/src/netif/ppp/fsm.c \
../LwIP/src/netif/ppp/ipcp.c \
../LwIP/src/netif/ppp/ipv6cp.c \
../LwIP/src/netif/ppp/lcp.c \
../LwIP/src/netif/ppp/magic.c \
../LwIP/src/netif/ppp/mppe.c \
../LwIP/src/netif/ppp/multilink.c \
../LwIP/src/netif/ppp/ppp.c \
../LwIP/src/netif/ppp/pppapi.c \
../LwIP/src/netif/ppp/pppcrypt.c \
../LwIP/src/netif/ppp/pppoe.c \
../LwIP/src/netif/ppp/pppol2tp.c \
../LwIP/src/netif/ppp/pppos.c \
../LwIP/src/netif/ppp/upap.c \
../LwIP/src/netif/ppp/utils.c \
../LwIP/src/netif/ppp/vj.c 

OBJS += \
./LwIP/src/netif/ppp/auth.o \
./LwIP/src/netif/ppp/ccp.o \
./LwIP/src/netif/ppp/chap-md5.o \
./LwIP/src/netif/ppp/chap-new.o \
./LwIP/src/netif/ppp/chap_ms.o \
./LwIP/src/netif/ppp/demand.o \
./LwIP/src/netif/ppp/eap.o \
./LwIP/src/netif/ppp/ecp.o \
./LwIP/src/netif/ppp/eui64.o \
./LwIP/src/netif/ppp/fsm.o \
./LwIP/src/netif/ppp/ipcp.o \
./LwIP/src/netif/ppp/ipv6cp.o \
./LwIP/src/netif/ppp/lcp.o \
./LwIP/src/netif/ppp/magic.o \
./LwIP/src/netif/ppp/mppe.o \
./LwIP/src/netif/ppp/multilink.o \
./LwIP/src/netif/ppp/ppp.o \
./LwIP/src/netif/ppp/pppapi.o \
./LwIP/src/netif/ppp/pppcrypt.o \
./LwIP/src/netif/ppp/pppoe.o \
./LwIP/src/netif/ppp/pppol2tp.o \
./LwIP/src/netif/ppp/pppos.o \
./LwIP/src/netif/ppp/upap.o \
./LwIP/src/netif/ppp/utils.o \
./LwIP/src/netif/ppp/vj.o 

C_DEPS += \
./LwIP/src/netif/ppp/auth.d \
./LwIP/src/netif/ppp/ccp.d \
./LwIP/src/netif/ppp/chap-md5.d \
./LwIP/src/netif/ppp/chap-new.d \
./LwIP/src/netif/ppp/chap_ms.d \
./LwIP/src/netif/ppp/demand.d \
./LwIP/src/netif/ppp/eap.d \
./LwIP/src/netif/ppp/ecp.d \
./LwIP/src/netif/ppp/eui64.d \
./LwIP/src/netif/ppp/fsm.d \
./LwIP/src/netif/ppp/ipcp.d \
./LwIP/src/netif/ppp/ipv6cp.d \
./LwIP/src/netif/ppp/lcp.d \
./LwIP/src/netif/ppp/magic.d \
./LwIP/src/netif/ppp/mppe.d \
./LwIP/src/netif/ppp/multilink.d \
./LwIP/src/netif/ppp/ppp.d \
./LwIP/src/netif/ppp/pppapi.d \
./LwIP/src/netif/ppp/pppcrypt.d \
./LwIP/src/netif/ppp/pppoe.d \
./LwIP/src/netif/ppp/pppol2tp.d \
./LwIP/src/netif/ppp/pppos.d \
./LwIP/src/netif/ppp/upap.d \
./LwIP/src/netif/ppp/utils.d \
./LwIP/src/netif/ppp/vj.d 


# Each subdirectory must supply rules for building sources it contributes
LwIP/src/netif/ppp/%.o LwIP/src/netif/ppp/%.su LwIP/src/netif/ppp/%.cyclo: ../LwIP/src/netif/ppp/%.c LwIP/src/netif/ppp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L433xx -c -I"C:/Users/Sowa/Desktop/Elektronika/SOFTWARE/_GIT/HomeIO/HomeIOv2/LwIP/src/include" -I"C:/Users/Sowa/Desktop/Elektronika/SOFTWARE/_GIT/HomeIO/HomeIOv2/ethernet/Inc" -I"C:/Users/Sowa/Desktop/Elektronika/SOFTWARE/_GIT/HomeIO/HomeIOv2/ethernet/Src" -I"C:/Users/Sowa/Desktop/Elektronika/SOFTWARE/_GIT/HomeIO/HomeIOv2/ethernet/arch" -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LwIP-2f-src-2f-netif-2f-ppp

clean-LwIP-2f-src-2f-netif-2f-ppp:
	-$(RM) ./LwIP/src/netif/ppp/auth.cyclo ./LwIP/src/netif/ppp/auth.d ./LwIP/src/netif/ppp/auth.o ./LwIP/src/netif/ppp/auth.su ./LwIP/src/netif/ppp/ccp.cyclo ./LwIP/src/netif/ppp/ccp.d ./LwIP/src/netif/ppp/ccp.o ./LwIP/src/netif/ppp/ccp.su ./LwIP/src/netif/ppp/chap-md5.cyclo ./LwIP/src/netif/ppp/chap-md5.d ./LwIP/src/netif/ppp/chap-md5.o ./LwIP/src/netif/ppp/chap-md5.su ./LwIP/src/netif/ppp/chap-new.cyclo ./LwIP/src/netif/ppp/chap-new.d ./LwIP/src/netif/ppp/chap-new.o ./LwIP/src/netif/ppp/chap-new.su ./LwIP/src/netif/ppp/chap_ms.cyclo ./LwIP/src/netif/ppp/chap_ms.d ./LwIP/src/netif/ppp/chap_ms.o ./LwIP/src/netif/ppp/chap_ms.su ./LwIP/src/netif/ppp/demand.cyclo ./LwIP/src/netif/ppp/demand.d ./LwIP/src/netif/ppp/demand.o ./LwIP/src/netif/ppp/demand.su ./LwIP/src/netif/ppp/eap.cyclo ./LwIP/src/netif/ppp/eap.d ./LwIP/src/netif/ppp/eap.o ./LwIP/src/netif/ppp/eap.su ./LwIP/src/netif/ppp/ecp.cyclo ./LwIP/src/netif/ppp/ecp.d ./LwIP/src/netif/ppp/ecp.o ./LwIP/src/netif/ppp/ecp.su ./LwIP/src/netif/ppp/eui64.cyclo ./LwIP/src/netif/ppp/eui64.d ./LwIP/src/netif/ppp/eui64.o ./LwIP/src/netif/ppp/eui64.su ./LwIP/src/netif/ppp/fsm.cyclo ./LwIP/src/netif/ppp/fsm.d ./LwIP/src/netif/ppp/fsm.o ./LwIP/src/netif/ppp/fsm.su ./LwIP/src/netif/ppp/ipcp.cyclo ./LwIP/src/netif/ppp/ipcp.d ./LwIP/src/netif/ppp/ipcp.o ./LwIP/src/netif/ppp/ipcp.su ./LwIP/src/netif/ppp/ipv6cp.cyclo ./LwIP/src/netif/ppp/ipv6cp.d ./LwIP/src/netif/ppp/ipv6cp.o ./LwIP/src/netif/ppp/ipv6cp.su ./LwIP/src/netif/ppp/lcp.cyclo ./LwIP/src/netif/ppp/lcp.d ./LwIP/src/netif/ppp/lcp.o ./LwIP/src/netif/ppp/lcp.su ./LwIP/src/netif/ppp/magic.cyclo ./LwIP/src/netif/ppp/magic.d ./LwIP/src/netif/ppp/magic.o ./LwIP/src/netif/ppp/magic.su ./LwIP/src/netif/ppp/mppe.cyclo ./LwIP/src/netif/ppp/mppe.d ./LwIP/src/netif/ppp/mppe.o ./LwIP/src/netif/ppp/mppe.su ./LwIP/src/netif/ppp/multilink.cyclo ./LwIP/src/netif/ppp/multilink.d ./LwIP/src/netif/ppp/multilink.o ./LwIP/src/netif/ppp/multilink.su ./LwIP/src/netif/ppp/ppp.cyclo ./LwIP/src/netif/ppp/ppp.d ./LwIP/src/netif/ppp/ppp.o ./LwIP/src/netif/ppp/ppp.su ./LwIP/src/netif/ppp/pppapi.cyclo ./LwIP/src/netif/ppp/pppapi.d ./LwIP/src/netif/ppp/pppapi.o ./LwIP/src/netif/ppp/pppapi.su ./LwIP/src/netif/ppp/pppcrypt.cyclo ./LwIP/src/netif/ppp/pppcrypt.d ./LwIP/src/netif/ppp/pppcrypt.o ./LwIP/src/netif/ppp/pppcrypt.su ./LwIP/src/netif/ppp/pppoe.cyclo ./LwIP/src/netif/ppp/pppoe.d ./LwIP/src/netif/ppp/pppoe.o ./LwIP/src/netif/ppp/pppoe.su ./LwIP/src/netif/ppp/pppol2tp.cyclo ./LwIP/src/netif/ppp/pppol2tp.d ./LwIP/src/netif/ppp/pppol2tp.o ./LwIP/src/netif/ppp/pppol2tp.su ./LwIP/src/netif/ppp/pppos.cyclo ./LwIP/src/netif/ppp/pppos.d ./LwIP/src/netif/ppp/pppos.o ./LwIP/src/netif/ppp/pppos.su ./LwIP/src/netif/ppp/upap.cyclo ./LwIP/src/netif/ppp/upap.d ./LwIP/src/netif/ppp/upap.o ./LwIP/src/netif/ppp/upap.su ./LwIP/src/netif/ppp/utils.cyclo ./LwIP/src/netif/ppp/utils.d ./LwIP/src/netif/ppp/utils.o ./LwIP/src/netif/ppp/utils.su ./LwIP/src/netif/ppp/vj.cyclo ./LwIP/src/netif/ppp/vj.d ./LwIP/src/netif/ppp/vj.o ./LwIP/src/netif/ppp/vj.su

.PHONY: clean-LwIP-2f-src-2f-netif-2f-ppp

