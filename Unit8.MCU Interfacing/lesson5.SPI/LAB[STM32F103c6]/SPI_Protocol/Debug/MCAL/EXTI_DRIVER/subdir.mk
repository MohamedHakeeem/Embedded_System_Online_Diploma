################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/EXTI_DRIVER/stm32f103x6_exti_driver.c 

OBJS += \
./MCAL/EXTI_DRIVER/stm32f103x6_exti_driver.o 

C_DEPS += \
./MCAL/EXTI_DRIVER/stm32f103x6_exti_driver.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/EXTI_DRIVER/%.o MCAL/EXTI_DRIVER/%.su MCAL/EXTI_DRIVER/%.cyclo: ../MCAL/EXTI_DRIVER/%.c MCAL/EXTI_DRIVER/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"F:/Embedded Systems New/Diploma/Unit8.MCU Interfacing/lesson5.SPI/LAB[STM32F103c6]/SPI_Protocol/MCAL/Inc" -I"F:/Embedded Systems New/Diploma/Unit8.MCU Interfacing/lesson5.SPI/LAB[STM32F103c6]/SPI_Protocol/HAL/Includes" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MCAL-2f-EXTI_DRIVER

clean-MCAL-2f-EXTI_DRIVER:
	-$(RM) ./MCAL/EXTI_DRIVER/stm32f103x6_exti_driver.cyclo ./MCAL/EXTI_DRIVER/stm32f103x6_exti_driver.d ./MCAL/EXTI_DRIVER/stm32f103x6_exti_driver.o ./MCAL/EXTI_DRIVER/stm32f103x6_exti_driver.su

.PHONY: clean-MCAL-2f-EXTI_DRIVER

