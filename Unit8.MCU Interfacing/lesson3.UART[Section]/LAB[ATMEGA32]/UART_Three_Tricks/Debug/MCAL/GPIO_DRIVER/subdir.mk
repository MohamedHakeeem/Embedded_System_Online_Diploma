################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/GPIO_DRIVER/atmega32_gpio_driver.c 

OBJS += \
./MCAL/GPIO_DRIVER/atmega32_gpio_driver.o 

C_DEPS += \
./MCAL/GPIO_DRIVER/atmega32_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/GPIO_DRIVER/%.o: ../MCAL/GPIO_DRIVER/%.c MCAL/GPIO_DRIVER/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"F:\Embedded Systems New\Diploma\Unit8.MCU Interfacing\lesson3.UART[Section]\LAB[ATMEGA32]\UART_Three_Tricks\HAL\Inc" -I"F:\Embedded Systems New\Diploma\Unit8.MCU Interfacing\lesson3.UART[Section]\LAB[ATMEGA32]\UART_Three_Tricks\MCAL\Inc" -Wall -g2 -gdwarf-2 -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


