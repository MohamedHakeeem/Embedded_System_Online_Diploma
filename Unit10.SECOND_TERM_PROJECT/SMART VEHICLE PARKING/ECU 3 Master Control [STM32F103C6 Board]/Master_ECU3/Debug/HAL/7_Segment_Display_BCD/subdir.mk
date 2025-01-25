################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/7_Segment_Display_BCD/7_Segment_Binary.c 

OBJS += \
./HAL/7_Segment_Display_BCD/7_Segment_Binary.o 

C_DEPS += \
./HAL/7_Segment_Display_BCD/7_Segment_Binary.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/7_Segment_Display_BCD/%.o HAL/7_Segment_Display_BCD/%.su HAL/7_Segment_Display_BCD/%.cyclo: ../HAL/7_Segment_Display_BCD/%.c HAL/7_Segment_Display_BCD/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"F:/Embedded Systems New/Diploma/Unit10. SECOND_TERM_PROJECT [ With AGILE SCRUM METHOD BY JIRA TOOL]/SMART VEHICLE PARKING/ECU 3 Master Control [STM32F103C6 Board]/Master_ECU3/HAL/Include" -I"F:/Embedded Systems New/Diploma/Unit10. SECOND_TERM_PROJECT [ With AGILE SCRUM METHOD BY JIRA TOOL]/SMART VEHICLE PARKING/ECU 3 Master Control [STM32F103C6 Board]/Master_ECU3/MCAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HAL-2f-7_Segment_Display_BCD

clean-HAL-2f-7_Segment_Display_BCD:
	-$(RM) ./HAL/7_Segment_Display_BCD/7_Segment_Binary.cyclo ./HAL/7_Segment_Display_BCD/7_Segment_Binary.d ./HAL/7_Segment_Display_BCD/7_Segment_Binary.o ./HAL/7_Segment_Display_BCD/7_Segment_Binary.su

.PHONY: clean-HAL-2f-7_Segment_Display_BCD

