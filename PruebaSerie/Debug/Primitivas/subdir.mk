################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Primitivas/PR_7Seg.c \
../Primitivas/PR_Leds.c \
../Primitivas/PR_TImers.c \
../Primitivas/PR_Teclado.c 

OBJS += \
./Primitivas/PR_7Seg.o \
./Primitivas/PR_Leds.o \
./Primitivas/PR_TImers.o \
./Primitivas/PR_Teclado.o 

C_DEPS += \
./Primitivas/PR_7Seg.d \
./Primitivas/PR_Leds.d \
./Primitivas/PR_TImers.d \
./Primitivas/PR_Teclado.d 


# Each subdirectory must supply rules for building sources it contributes
Primitivas/%.o: ../Primitivas/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_DISABLE -D__MTB_BUFFER_SIZE=256 -D__LPC84X__ -D__REDLIB__ -I"/home/chor/Documents/Facu/2021/MCUXpresso/workspace/PruebaSerie/Primitivas" -I"/home/chor/Documents/Facu/2021/MCUXpresso/workspace/PruebaSerie/Aplicacion" -I"/home/chor/Documents/Facu/2021/MCUXpresso/workspace/PruebaSerie/Drivers" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


