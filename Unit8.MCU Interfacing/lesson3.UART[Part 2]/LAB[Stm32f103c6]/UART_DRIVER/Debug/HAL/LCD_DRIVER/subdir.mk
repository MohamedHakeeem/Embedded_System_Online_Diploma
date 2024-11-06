################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/LCD_DRIVER/lcd.c 

OBJS += \
./HAL/LCD_DRIVER/lcd.o 

C_DEPS += \
./HAL/LCD_DRIVER/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/LCD_DRIVER/%.o HAL/LCD_DRIVER/%.su HAL/LCD_DRIVER/%.cyclo: ../HAL/LCD_DRIVER/%.c HAL/LCD_DRIVER/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"F:/Embedded Systems New/Diploma/Unit8.MCU Interfacing/lesson3.UART[Part 2]/LAB[Stm32f103c6]/UART_DRIVER/MCAL/Inc" -I"F:/Embedded Systems New/Diploma/Unit8.MCU Interfacing/lesson3.UART[Part 2]/LAB[Stm32f103c6]/UART_DRIVER/HAL/Includes" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HAL-2f-LCD_DRIVER

clean-HAL-2f-LCD_DRIVER:
	-$(RM) ./HAL/LCD_DRIVER/lcd.cyclo ./HAL/LCD_DRIVER/lcd.d ./HAL/LCD_DRIVER/lcd.o ./HAL/LCD_DRIVER/lcd.su

.PHONY: clean-HAL-2f-LCD_DRIVER

