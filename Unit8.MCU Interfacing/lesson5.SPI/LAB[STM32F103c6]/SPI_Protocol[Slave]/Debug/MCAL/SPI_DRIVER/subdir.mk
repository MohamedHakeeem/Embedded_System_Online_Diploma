################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/SPI_DRIVER/stm32f103x6_spi_driver.c 

OBJS += \
./MCAL/SPI_DRIVER/stm32f103x6_spi_driver.o 

C_DEPS += \
./MCAL/SPI_DRIVER/stm32f103x6_spi_driver.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/SPI_DRIVER/%.o MCAL/SPI_DRIVER/%.su MCAL/SPI_DRIVER/%.cyclo: ../MCAL/SPI_DRIVER/%.c MCAL/SPI_DRIVER/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"F:/Embedded Systems New/Diploma/Unit8.MCU Interfacing/lesson5.SPI/LAB[STM32F103c6]/SPI_Protocol[Slave]/MCAL/Inc" -I"F:/Embedded Systems New/Diploma/Unit8.MCU Interfacing/lesson5.SPI/LAB[STM32F103c6]/SPI_Protocol[Slave]/HAL/Includes" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MCAL-2f-SPI_DRIVER

clean-MCAL-2f-SPI_DRIVER:
	-$(RM) ./MCAL/SPI_DRIVER/stm32f103x6_spi_driver.cyclo ./MCAL/SPI_DRIVER/stm32f103x6_spi_driver.d ./MCAL/SPI_DRIVER/stm32f103x6_spi_driver.o ./MCAL/SPI_DRIVER/stm32f103x6_spi_driver.su

.PHONY: clean-MCAL-2f-SPI_DRIVER

