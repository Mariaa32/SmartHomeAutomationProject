################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Project3.c \
../adc.c \
../buzzer.c \
../flame_sensor.c \
../gpio.c \
../lcd.c \
../ldr_sensor.c \
../led.c \
../lm35_sensor.c \
../motor.c \
../pwm.c 

OBJS += \
./Project3.o \
./adc.o \
./buzzer.o \
./flame_sensor.o \
./gpio.o \
./lcd.o \
./ldr_sensor.o \
./led.o \
./lm35_sensor.o \
./motor.o \
./pwm.o 

C_DEPS += \
./Project3.d \
./adc.d \
./buzzer.d \
./flame_sensor.d \
./gpio.d \
./lcd.d \
./ldr_sensor.d \
./led.d \
./lm35_sensor.d \
./motor.d \
./pwm.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


