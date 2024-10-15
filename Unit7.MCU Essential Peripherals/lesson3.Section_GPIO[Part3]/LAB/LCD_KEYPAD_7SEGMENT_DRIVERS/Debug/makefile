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
-include STM32_F103C6_Drivers/MCAL_GPIO_DRIVER/subdir.mk
-include STM32_F103C6_Drivers/HAL_LCD_DRIVER/subdir.mk
-include STM32_F103C6_Drivers/HAL_KEYPAD_DRIVER/subdir.mk
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


BUILD_ARTIFACT_NAME := LCD_KEYPAD_7SEGMENT_DRIVERS
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
LCD_KEYPAD_7SEGMENT_DRIVERS.elf \

MAP_FILES += \
LCD_KEYPAD_7SEGMENT_DRIVERS.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
LCD_KEYPAD_7SEGMENT_DRIVERS.list \

OBJCOPY_HEX += \
LCD_KEYPAD_7SEGMENT_DRIVERS.hex \


# All Target
all: main-build

# Main-build Target
main-build: LCD_KEYPAD_7SEGMENT_DRIVERS.elf secondary-outputs

# Tool invocations
LCD_KEYPAD_7SEGMENT_DRIVERS.elf LCD_KEYPAD_7SEGMENT_DRIVERS.map: $(OBJS) $(USER_OBJS) F:\Embedded\ Systems\ New\Diploma\Unit7.MCU\ Essential\ Peripherals\lesson3.Section_GPIO[Part3]\LAB\LCD_KEYPAD_7SEGMENT_DRIVERS\STM32F103C6TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -gdwarf-2 -o "LCD_KEYPAD_7SEGMENT_DRIVERS.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"F:\Embedded Systems New\Diploma\Unit7.MCU Essential Peripherals\lesson3.Section_GPIO[Part3]\LAB\LCD_KEYPAD_7SEGMENT_DRIVERS\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="LCD_KEYPAD_7SEGMENT_DRIVERS.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

LCD_KEYPAD_7SEGMENT_DRIVERS.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "LCD_KEYPAD_7SEGMENT_DRIVERS.list"
	@echo 'Finished building: $@'
	@echo ' '

LCD_KEYPAD_7SEGMENT_DRIVERS.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "LCD_KEYPAD_7SEGMENT_DRIVERS.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) LCD_KEYPAD_7SEGMENT_DRIVERS.elf LCD_KEYPAD_7SEGMENT_DRIVERS.hex LCD_KEYPAD_7SEGMENT_DRIVERS.list LCD_KEYPAD_7SEGMENT_DRIVERS.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
