################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include MCAL/USART_DRIVER/subdir.mk
-include MCAL/SPI_DRIVER/subdir.mk
-include MCAL/Partial_RCC_DRIVER/subdir.mk
-include MCAL/GPIO_DRIVER/subdir.mk
-include MCAL/EXTI_DRIVER/subdir.mk
-include HAL/RFID_CARD_DRIVER/subdir.mk
-include HAL/LCD_DRIVER/subdir.mk
-include HAL/KEYPAD_DRIVER/subdir.mk
-include HAL/EEPROM_SPI/subdir.mk
-include HAL/7_Segment_Display_BCD/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Master_ECU3
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Master_ECU3.elf \

MAP_FILES += \
Master_ECU3.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Master_ECU3.list \


# All Target
all: main-build

# Main-build Target
main-build: Master_ECU3.elf secondary-outputs

# Tool invocations
Master_ECU3.elf Master_ECU3.map: $(OBJS) $(USER_OBJS) F:\Embedded\ Systems\ New\Diploma\Unit10.\ SECOND_TERM_PROJECT\ [\ With\ AGILE\ SCRUM\ METHOD\ BY\ JIRA\ TOOL]\SMART\ VEHICLE\ PARKING\ECU\ 3\ Master\ Control\ [STM32F103C6\ Board]\Master_ECU3\STM32F103C6TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc  -gdwarf-2 -o "Master_ECU3.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"F:\Embedded Systems New\Diploma\Unit10. SECOND_TERM_PROJECT [ With AGILE SCRUM METHOD BY JIRA TOOL]\SMART VEHICLE PARKING\ECU 3 Master Control [STM32F103C6 Board]\Master_ECU3\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Master_ECU3.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Master_ECU3.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Master_ECU3.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Master_ECU3.elf Master_ECU3.list Master_ECU3.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
