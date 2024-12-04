################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/EEPROM/EEPROM.c 

OBJS += \
./HAL/EEPROM/EEPROM.o 

C_DEPS += \
./HAL/EEPROM/EEPROM.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/EEPROM/%.o HAL/EEPROM/%.su HAL/EEPROM/%.cyclo: ../HAL/EEPROM/%.c HAL/EEPROM/subdir.mk
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"F:/Embedded Systems New/Diploma/Unit8.MCU Interfacing/lesson7.I2C_Controller/LAB[Stm32f103c6]/I2C_Controller/HAL/Includes" -I"F:/Embedded Systems New/Diploma/Unit8.MCU Interfacing/lesson7.I2C_Controller/LAB[Stm32f103c6]/I2C_Controller/MCAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HAL-2f-EEPROM

clean-HAL-2f-EEPROM:
	-$(RM) ./HAL/EEPROM/EEPROM.cyclo ./HAL/EEPROM/EEPROM.d ./HAL/EEPROM/EEPROM.o ./HAL/EEPROM/EEPROM.su

.PHONY: clean-HAL-2f-EEPROM

