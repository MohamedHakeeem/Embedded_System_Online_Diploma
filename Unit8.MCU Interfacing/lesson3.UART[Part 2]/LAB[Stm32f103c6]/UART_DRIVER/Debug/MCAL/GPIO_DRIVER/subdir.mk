################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/GPIO_DRIVER/stm32f103x6_gpio_driver.c 

OBJS += \
./MCAL/GPIO_DRIVER/stm32f103x6_gpio_driver.o 

C_DEPS += \
./MCAL/GPIO_DRIVER/stm32f103x6_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/GPIO_DRIVER/%.o MCAL/GPIO_DRIVER/%.su MCAL/GPIO_DRIVER/%.cyclo: ../MCAL/GPIO_DRIVER/%.c MCAL/GPIO_DRIVER/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"F:/Embedded Systems New/Diploma/Unit8.MCU Interfacing/lesson3.UART[Part 2]/LAB[Stm32f103c6]/UART_DRIVER/MCAL/Inc" -I"F:/Embedded Systems New/Diploma/Unit8.MCU Interfacing/lesson3.UART[Part 2]/LAB[Stm32f103c6]/UART_DRIVER/HAL/Includes" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MCAL-2f-GPIO_DRIVER

clean-MCAL-2f-GPIO_DRIVER:
	-$(RM) ./MCAL/GPIO_DRIVER/stm32f103x6_gpio_driver.cyclo ./MCAL/GPIO_DRIVER/stm32f103x6_gpio_driver.d ./MCAL/GPIO_DRIVER/stm32f103x6_gpio_driver.o ./MCAL/GPIO_DRIVER/stm32f103x6_gpio_driver.su

.PHONY: clean-MCAL-2f-GPIO_DRIVER

