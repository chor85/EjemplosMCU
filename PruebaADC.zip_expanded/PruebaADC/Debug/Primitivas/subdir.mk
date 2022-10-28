################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Primitivas/PR_7Seg.c \
../Primitivas/PR_ADC.c \
../Primitivas/PR_Leds.c \
../Primitivas/PR_TImers.c \
../Primitivas/PR_Teclado.c \
../Primitivas/PR_UART.c 

OBJS += \
./Primitivas/PR_7Seg.o \
./Primitivas/PR_ADC.o \
./Primitivas/PR_Leds.o \
./Primitivas/PR_TImers.o \
./Primitivas/PR_Teclado.o \
./Primitivas/PR_UART.o 

C_DEPS += \
./Primitivas/PR_7Seg.d \
./Primitivas/PR_ADC.d \
./Primitivas/PR_Leds.d \
./Primitivas/PR_TImers.d \
./Primitivas/PR_Teclado.d \
./Primitivas/PR_UART.d 


# Each subdirectory must supply rules for building sources it contributes
Primitivas/%.o: ../Primitivas/%.c Primitivas/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_DISABLE -D__MTB_BUFFER_SIZE=256 -D__LPC84X__ -D__REDLIB__ -I"/home/chor/Documents/EjemplosMCU2022/PruebaADC.zip_expanded/PruebaADC/Primitivas" -I"/home/chor/Documents/EjemplosMCU2022/PruebaADC.zip_expanded/PruebaADC/Aplicacion" -I"/home/chor/Documents/EjemplosMCU2022/PruebaADC.zip_expanded/PruebaADC/Drivers" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


