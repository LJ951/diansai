################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS

GEN_OPTS__FLAG := @"./device.opt" 
GEN_CMDS__FLAG := -Wl,-l"./device_linker.cmd" 

ORDERED_OBJS += \
"./empty.o" \
"./ti_msp_dl_config.o" \
"./startup_mspm0g350x_ticlang.o" \
"./Hardware/MPU6050.o" \
"./Hardware/bsp_iic.o" \
"./Hardware/bsp_printf.o" \
"./Hardware/bsp_systick.o" \
"./Hardware/inv_mpu.o" \
"./Hardware/inv_mpu_dmp_motion_driver.o" \
"./modules/src/74HC595.o" \
"./modules/src/Key.o" \
"./modules/src/OLED.o" \
"./modules/src/OLED_Data.o" \
"./modules/src/PID.o" \
"./modules/src/Trail.o" \
"./modules/src/car.o" \
"./modules/src/interrupt.o" \
"./modules/src/motor.o" \
$(GEN_CMDS__FLAG) \
-Wl,-ldevice.cmd.genlibs \
-Wl,-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include Hardware/subdir_vars.mk
-include modules/src/subdir_vars.mk
-include subdir_rules.mk
-include Hardware/subdir_rules.mk
-include modules/src/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
9_car_V2.1.out 

EXE_OUTPUTS__QUOTED += \
"9_car_V2.1.out" 

BIN_OUTPUTS += \
9_car_V2.1.hex 

BIN_OUTPUTS__QUOTED += \
"9_car_V2.1.hex" 


# All Target
all: $(OBJS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "9_car_V2.1.out" secondary-outputs

# Tool invocations
9_car_V2.1.out: $(OBJS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: Arm Linker'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -gdwarf-3 -Wl,-m"9_car_V2.1.map" -Wl,-i"C:/ti/mspm0_sdk_2_04_00_06/source" -Wl,-i"C:/Users/22334/workspace_ccstheia/9_car_V2.1" -Wl,-i"C:/Users/22334/workspace_ccstheia/9_car_V2.1/Debug/syscfg" -Wl,-i"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/lib" -Wl,--diag_wrap=off -Wl,--display_error_number -Wl,--warn_sections -Wl,--xml_link_info="9_car_V2.1_linkInfo.xml" -Wl,--rom_model -o "9_car_V2.1.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

9_car_V2.1.hex: $(EXE_OUTPUTS)
	@echo 'Building secondary target: "$@"'
	@echo 'Invoking: Arm Hex Utility'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmhex.exe" --byte --memwidth=8 --romwidth=8 --diag_wrap=off --intel -o "9_car_V2.1.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building secondary target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(GEN_MISC_FILES__QUOTED)$(BIN_OUTPUTS__QUOTED)$(GEN_FILES__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "empty.o" "ti_msp_dl_config.o" "startup_mspm0g350x_ticlang.o" "Hardware\MPU6050.o" "Hardware\bsp_iic.o" "Hardware\bsp_printf.o" "Hardware\bsp_systick.o" "Hardware\inv_mpu.o" "Hardware\inv_mpu_dmp_motion_driver.o" "modules\src\74HC595.o" "modules\src\Key.o" "modules\src\OLED.o" "modules\src\OLED_Data.o" "modules\src\PID.o" "modules\src\Trail.o" "modules\src\car.o" "modules\src\interrupt.o" "modules\src\motor.o" 
	-$(RM) "empty.d" "ti_msp_dl_config.d" "startup_mspm0g350x_ticlang.d" "Hardware\MPU6050.d" "Hardware\bsp_iic.d" "Hardware\bsp_printf.d" "Hardware\bsp_systick.d" "Hardware\inv_mpu.d" "Hardware\inv_mpu_dmp_motion_driver.d" "modules\src\74HC595.d" "modules\src\Key.d" "modules\src\OLED.d" "modules\src\OLED_Data.d" "modules\src\PID.d" "modules\src\Trail.d" "modules\src\car.d" "modules\src\interrupt.d" "modules\src\motor.d" 
	-@echo 'Finished clean'
	-@echo ' '

secondary-outputs: $(BIN_OUTPUTS)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

