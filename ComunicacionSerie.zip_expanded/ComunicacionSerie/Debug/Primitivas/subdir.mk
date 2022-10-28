################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Primitivas/PR_7Seg.c \
../Primitivas/Pr_Tecla.c \
../Primitivas/Pr_serie.c 

OBJS += \
./Primitivas/PR_7Seg.o \
./Primitivas/Pr_Tecla.o \
./Primitivas/Pr_serie.o 

C_DEPS += \
./Primitivas/PR_7Seg.d \
./Primitivas/Pr_Tecla.d \
./Primitivas/Pr_serie.d 


# Each subdirectory must supply rules for building sources it contributes
Primitivas/%.o: ../Primitivas/%.c Primitivas/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -D__LPC84X__ -D__REDLIB__ -I"/home/chor/Documents/EjemplosMCU2022/ComunicacionSerie.zip_expanded/ComunicacionSerie/Drivers" -I"/home/chor/Documents/EjemplosMCU2022/ComunicacionSerie.zip_expanded/ComunicacionSerie/Primitivas" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


