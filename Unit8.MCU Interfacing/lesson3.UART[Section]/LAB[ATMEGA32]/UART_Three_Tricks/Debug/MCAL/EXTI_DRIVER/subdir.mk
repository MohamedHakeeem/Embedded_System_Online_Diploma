################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/EXTI_DRIVER/atmega32_exti_driver.c 

OBJS += \
./MCAL/EXTI_DRIVER/atmega32_exti_driver.o 

C_DEPS += \
./MCAL/EXTI_DRIVER/atmega32_exti_driver.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/EXTI_DRIVER/%.o: ../MCAL/EXTI_DRIVER/%.c MCAL/EXTI_DRIVER/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"F:\Embedded Systems New\Diploma\Unit8.MCU Interfacing\lesson3.UART[Section]\LAB[ATMEGA32]\UART_Three_Tricks\HAL\Inc" -I"F:\Embedded Systems New\Diploma\Unit8.MCU Interfacing\lesson3.UART[Section]\LAB[ATMEGA32]\UART_Three_Tricks\MCAL\Inc" -Wall -g2 -gdwarf-2 -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

