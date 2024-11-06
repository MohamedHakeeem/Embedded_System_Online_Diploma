################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Partial_RCC_DRIVER/stm32f103x6_rcc_driver.c 

OBJS += \
./MCAL/Partial_RCC_DRIVER/stm32f103x6_rcc_driver.o 

C_DEPS += \
./MCAL/Partial_RCC_DRIVER/stm32f103x6_rcc_driver.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Partial_RCC_DRIVER/%.o MCAL/Partial_RCC_DRIVER/%.su MCAL/Partial_RCC_DRIVER/%.cyclo: ../MCAL/Partial_RCC_DRIVER/%.c MCAL/Partial_RCC_DRIVER/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"F:/Embedded Systems New/Diploma/Unit8.MCU Interfacing/lesson3.UART[Part 2]/LAB[Stm32f103c6]/UART_DRIVER/MCAL/Inc" -I"F:/Embedded Systems New/Diploma/Unit8.MCU Interfacing/lesson3.UART[Part 2]/LAB[Stm32f103c6]/UART_DRIVER/HAL/Includes" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MCAL-2f-Partial_RCC_DRIVER

clean-MCAL-2f-Partial_RCC_DRIVER:
	-$(RM) ./MCAL/Partial_RCC_DRIVER/stm32f103x6_rcc_driver.cyclo ./MCAL/Partial_RCC_DRIVER/stm32f103x6_rcc_driver.d ./MCAL/Partial_RCC_DRIVER/stm32f103x6_rcc_driver.o ./MCAL/Partial_RCC_DRIVER/stm32f103x6_rcc_driver.su

.PHONY: clean-MCAL-2f-Partial_RCC_DRIVER

