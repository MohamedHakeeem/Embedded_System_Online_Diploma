################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/LCD_DRIVER/lcd.c 

OBJS += \
./HAL/LCD_DRIVER/lcd.o 

C_DEPS += \
./HAL/LCD_DRIVER/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/LCD_DRIVER/%.o: ../HAL/LCD_DRIVER/%.c HAL/LCD_DRIVER/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"F:\Embedded Systems New\Diploma\Unit8.MCU Interfacing\lesson.2[Section 1]\LAB[ATMEGA32]\UART_PROTOCOL\HAL\Inc" -I"F:\Embedded Systems New\Diploma\Unit8.MCU Interfacing\lesson.2[Section 1]\LAB[ATMEGA32]\UART_PROTOCOL\MCAL\Inc" -Wall -g2 -gdwarf-2 -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

