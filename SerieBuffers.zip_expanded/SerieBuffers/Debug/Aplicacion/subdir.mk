################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Aplicacion/aeabi_romdiv_patch.s 

C_SRCS += \
../Aplicacion/PruebaSerie.c \
../Aplicacion/cr_startup_lpc84x.c \
../Aplicacion/crp.c \
../Aplicacion/mtb.c 

OBJS += \
./Aplicacion/PruebaSerie.o \
./Aplicacion/aeabi_romdiv_patch.o \
./Aplicacion/cr_startup_lpc84x.o \
./Aplicacion/crp.o \
./Aplicacion/mtb.o 

C_DEPS += \
./Aplicacion/PruebaSerie.d \
./Aplicacion/cr_startup_lpc84x.d \
./Aplicacion/crp.d \
./Aplicacion/mtb.d 


# Each subdirectory must supply rules for building sources it contributes
Aplicacion/%.o: ../Aplicacion/%.c Aplicacion/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_DISABLE -D__MTB_BUFFER_SIZE=256 -D__LPC84X__ -D__REDLIB__ -I"/home/chor/Documents/EjemplosMCU2022/SerieBuffers.zip_expanded/SerieBuffers/Primitivas" -I"/home/chor/Documents/EjemplosMCU2022/SerieBuffers.zip_expanded/SerieBuffers/Aplicacion" -I"/home/chor/Documents/EjemplosMCU2022/SerieBuffers.zip_expanded/SerieBuffers/Drivers" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Aplicacion/%.o: ../Aplicacion/%.s Aplicacion/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU Assembler'
	arm-none-eabi-gcc -c -x assembler-with-cpp -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__LPC84X__ -D__REDLIB__ -g3 -mcpu=cortex-m0 -mthumb -specs=redlib.specs -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


