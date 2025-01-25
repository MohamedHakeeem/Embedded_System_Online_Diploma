################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/EEPROM_SPI/EEPROM.c 

OBJS += \
./HAL/EEPROM_SPI/EEPROM.o 

C_DEPS += \
./HAL/EEPROM_SPI/EEPROM.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/EEPROM_SPI/%.o HAL/EEPROM_SPI/%.su HAL/EEPROM_SPI/%.cyclo: ../HAL/EEPROM_SPI/%.c HAL/EEPROM_SPI/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"F:/Embedded Systems New/Diploma/Unit10. SECOND_TERM_PROJECT [ With AGILE SCRUM METHOD BY JIRA TOOL]/SMART VEHICLE PARKING/ECU 3 Master Control [STM32F103C6 Board]/Master_ECU3/HAL/Include" -I"F:/Embedded Systems New/Diploma/Unit10. SECOND_TERM_PROJECT [ With AGILE SCRUM METHOD BY JIRA TOOL]/SMART VEHICLE PARKING/ECU 3 Master Control [STM32F103C6 Board]/Master_ECU3/MCAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HAL-2f-EEPROM_SPI

clean-HAL-2f-EEPROM_SPI:
	-$(RM) ./HAL/EEPROM_SPI/EEPROM.cyclo ./HAL/EEPROM_SPI/EEPROM.d ./HAL/EEPROM_SPI/EEPROM.o ./HAL/EEPROM_SPI/EEPROM.su

.PHONY: clean-HAL-2f-EEPROM_SPI

