################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/KEYPAD_DRIVER/Keypad.c 

OBJS += \
./HAL/KEYPAD_DRIVER/Keypad.o 

C_DEPS += \
./HAL/KEYPAD_DRIVER/Keypad.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/KEYPAD_DRIVER/%.o HAL/KEYPAD_DRIVER/%.su HAL/KEYPAD_DRIVER/%.cyclo: ../HAL/KEYPAD_DRIVER/%.c HAL/KEYPAD_DRIVER/subdir.mk
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"F:/Embedded Systems New/Diploma/Unit8.MCU Interfacing/lesson7.I2C_Controller/LAB[Stm32f103c6]/I2C_Controller/HAL/Includes" -I"F:/Embedded Systems New/Diploma/Unit8.MCU Interfacing/lesson7.I2C_Controller/LAB[Stm32f103c6]/I2C_Controller/MCAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HAL-2f-KEYPAD_DRIVER

clean-HAL-2f-KEYPAD_DRIVER:
	-$(RM) ./HAL/KEYPAD_DRIVER/Keypad.cyclo ./HAL/KEYPAD_DRIVER/Keypad.d ./HAL/KEYPAD_DRIVER/Keypad.o ./HAL/KEYPAD_DRIVER/Keypad.su

.PHONY: clean-HAL-2f-KEYPAD_DRIVER

