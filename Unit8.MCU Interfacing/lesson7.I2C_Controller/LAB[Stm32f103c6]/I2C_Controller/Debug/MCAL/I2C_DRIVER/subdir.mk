################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/I2C_DRIVER/stm32f103x8_i2c_driver.c 

OBJS += \
./MCAL/I2C_DRIVER/stm32f103x8_i2c_driver.o 

C_DEPS += \
./MCAL/I2C_DRIVER/stm32f103x8_i2c_driver.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/I2C_DRIVER/%.o MCAL/I2C_DRIVER/%.su MCAL/I2C_DRIVER/%.cyclo: ../MCAL/I2C_DRIVER/%.c MCAL/I2C_DRIVER/subdir.mk
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"F:/Embedded Systems New/Diploma/Unit8.MCU Interfacing/lesson7.I2C_Controller/LAB[Stm32f103c6]/I2C_Controller/HAL/Includes" -I"F:/Embedded Systems New/Diploma/Unit8.MCU Interfacing/lesson7.I2C_Controller/LAB[Stm32f103c6]/I2C_Controller/MCAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MCAL-2f-I2C_DRIVER

clean-MCAL-2f-I2C_DRIVER:
	-$(RM) ./MCAL/I2C_DRIVER/stm32f103x8_i2c_driver.cyclo ./MCAL/I2C_DRIVER/stm32f103x8_i2c_driver.d ./MCAL/I2C_DRIVER/stm32f103x8_i2c_driver.o ./MCAL/I2C_DRIVER/stm32f103x8_i2c_driver.su

.PHONY: clean-MCAL-2f-I2C_DRIVER

