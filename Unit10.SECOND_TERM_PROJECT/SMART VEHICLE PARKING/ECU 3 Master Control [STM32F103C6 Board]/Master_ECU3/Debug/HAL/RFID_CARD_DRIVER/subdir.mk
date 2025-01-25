################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/RFID_CARD_DRIVER/RFID_CARD.c 

OBJS += \
./HAL/RFID_CARD_DRIVER/RFID_CARD.o 

C_DEPS += \
./HAL/RFID_CARD_DRIVER/RFID_CARD.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/RFID_CARD_DRIVER/%.o HAL/RFID_CARD_DRIVER/%.su HAL/RFID_CARD_DRIVER/%.cyclo: ../HAL/RFID_CARD_DRIVER/%.c HAL/RFID_CARD_DRIVER/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"F:/Embedded Systems New/Diploma/Unit10. SECOND_TERM_PROJECT [ With AGILE SCRUM METHOD BY JIRA TOOL]/SMART VEHICLE PARKING/ECU 3 Master Control [STM32F103C6 Board]/Master_ECU3/HAL/Include" -I"F:/Embedded Systems New/Diploma/Unit10. SECOND_TERM_PROJECT [ With AGILE SCRUM METHOD BY JIRA TOOL]/SMART VEHICLE PARKING/ECU 3 Master Control [STM32F103C6 Board]/Master_ECU3/MCAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HAL-2f-RFID_CARD_DRIVER

clean-HAL-2f-RFID_CARD_DRIVER:
	-$(RM) ./HAL/RFID_CARD_DRIVER/RFID_CARD.cyclo ./HAL/RFID_CARD_DRIVER/RFID_CARD.d ./HAL/RFID_CARD_DRIVER/RFID_CARD.o ./HAL/RFID_CARD_DRIVER/RFID_CARD.su

.PHONY: clean-HAL-2f-RFID_CARD_DRIVER

