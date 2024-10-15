################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32_F103C6_Drivers/MCAL_GPIO_DRIVER/stm32f103x6_gpio_driver.c 

OBJS += \
./STM32_F103C6_Drivers/MCAL_GPIO_DRIVER/stm32f103x6_gpio_driver.o 

C_DEPS += \
./STM32_F103C6_Drivers/MCAL_GPIO_DRIVER/stm32f103x6_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
STM32_F103C6_Drivers/MCAL_GPIO_DRIVER/%.o STM32_F103C6_Drivers/MCAL_GPIO_DRIVER/%.su STM32_F103C6_Drivers/MCAL_GPIO_DRIVER/%.cyclo: ../STM32_F103C6_Drivers/MCAL_GPIO_DRIVER/%.c STM32_F103C6_Drivers/MCAL_GPIO_DRIVER/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"F:/Embedded Systems New/Diploma/Unit7.MCU Essential Peripherals/lesson3.Section_GPIO[Part3]/LAB/LCD_KEYPAD_7SEGMENT_DRIVERS/STM32_F103C6_Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-STM32_F103C6_Drivers-2f-MCAL_GPIO_DRIVER

clean-STM32_F103C6_Drivers-2f-MCAL_GPIO_DRIVER:
	-$(RM) ./STM32_F103C6_Drivers/MCAL_GPIO_DRIVER/stm32f103x6_gpio_driver.cyclo ./STM32_F103C6_Drivers/MCAL_GPIO_DRIVER/stm32f103x6_gpio_driver.d ./STM32_F103C6_Drivers/MCAL_GPIO_DRIVER/stm32f103x6_gpio_driver.o ./STM32_F103C6_Drivers/MCAL_GPIO_DRIVER/stm32f103x6_gpio_driver.su

.PHONY: clean-STM32_F103C6_Drivers-2f-MCAL_GPIO_DRIVER

