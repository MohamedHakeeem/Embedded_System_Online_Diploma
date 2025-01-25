################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/USART_DRIVER/stm32f103x6_usart_driver.c 

OBJS += \
./MCAL/USART_DRIVER/stm32f103x6_usart_driver.o 

C_DEPS += \
./MCAL/USART_DRIVER/stm32f103x6_usart_driver.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/USART_DRIVER/%.o MCAL/USART_DRIVER/%.su MCAL/USART_DRIVER/%.cyclo: ../MCAL/USART_DRIVER/%.c MCAL/USART_DRIVER/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"F:/Embedded Systems New/Diploma/Unit10. SECOND_TERM_PROJECT [ With AGILE SCRUM METHOD BY JIRA TOOL]/SMART VEHICLE PARKING/ECU 3 Master Control [STM32F103C6 Board]/Master_ECU3/HAL/Include" -I"F:/Embedded Systems New/Diploma/Unit10. SECOND_TERM_PROJECT [ With AGILE SCRUM METHOD BY JIRA TOOL]/SMART VEHICLE PARKING/ECU 3 Master Control [STM32F103C6 Board]/Master_ECU3/MCAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MCAL-2f-USART_DRIVER

clean-MCAL-2f-USART_DRIVER:
	-$(RM) ./MCAL/USART_DRIVER/stm32f103x6_usart_driver.cyclo ./MCAL/USART_DRIVER/stm32f103x6_usart_driver.d ./MCAL/USART_DRIVER/stm32f103x6_usart_driver.o ./MCAL/USART_DRIVER/stm32f103x6_usart_driver.su

.PHONY: clean-MCAL-2f-USART_DRIVER

