################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/22334/workspace_ccstheia/7_trail/Drivers/Ultrasonic_GPIO" -I"C:/Users/22334/workspace_ccstheia/7_trail/Drivers/Ultrasonic_Capture" -I"C:/Users/22334/workspace_ccstheia/7_trail/Drivers/Trail" -I"C:/Users/22334/workspace_ccstheia/7_trail/Drivers/OLED" -I"C:/Users/22334/workspace_ccstheia/7_trail/Drivers/UART" -I"C:/Users/22334/workspace_ccstheia/7_trail/Drivers/MPU6050" -I"C:/Users/22334/workspace_ccstheia/7_trail" -I"C:/Users/22334/workspace_ccstheia/7_trail/Debug" -I"C:/ti/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_04_00_06/source" -I"C:/Users/22334/workspace_ccstheia/7_trail/Drivers/MSPM0" -DMOTION_DRIVER_TARGET_MSPM0 -DMPU6050 -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-1951093071: ../main.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/ccs2011/ccs/utils/sysconfig_1.24.0/sysconfig_cli.bat" --script "C:/Users/22334/workspace_ccstheia/7_trail/main.syscfg" -o "." -s "C:/ti/mspm0_sdk_2_04_00_06/.metadata/product.json" --compiler ticlang
	@echo 'Finished building: "$<"'
	@echo ' '

device_linker.cmd: build-1951093071 ../main.syscfg
device.opt: build-1951093071
device.cmd.genlibs: build-1951093071
ti_msp_dl_config.c: build-1951093071
ti_msp_dl_config.h: build-1951093071
Event.dot: build-1951093071

%.o: ./%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/22334/workspace_ccstheia/7_trail/Drivers/Ultrasonic_GPIO" -I"C:/Users/22334/workspace_ccstheia/7_trail/Drivers/Ultrasonic_Capture" -I"C:/Users/22334/workspace_ccstheia/7_trail/Drivers/Trail" -I"C:/Users/22334/workspace_ccstheia/7_trail/Drivers/OLED" -I"C:/Users/22334/workspace_ccstheia/7_trail/Drivers/UART" -I"C:/Users/22334/workspace_ccstheia/7_trail/Drivers/MPU6050" -I"C:/Users/22334/workspace_ccstheia/7_trail" -I"C:/Users/22334/workspace_ccstheia/7_trail/Debug" -I"C:/ti/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_04_00_06/source" -I"C:/Users/22334/workspace_ccstheia/7_trail/Drivers/MSPM0" -DMOTION_DRIVER_TARGET_MSPM0 -DMPU6050 -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

startup_mspm0g350x_ticlang.o: C:/ti/mspm0_sdk_2_04_00_06/source/ti/devices/msp/m0p/startup_system_files/ticlang/startup_mspm0g350x_ticlang.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/22334/workspace_ccstheia/7_trail/Drivers/Ultrasonic_GPIO" -I"C:/Users/22334/workspace_ccstheia/7_trail/Drivers/Ultrasonic_Capture" -I"C:/Users/22334/workspace_ccstheia/7_trail/Drivers/Trail" -I"C:/Users/22334/workspace_ccstheia/7_trail/Drivers/OLED" -I"C:/Users/22334/workspace_ccstheia/7_trail/Drivers/UART" -I"C:/Users/22334/workspace_ccstheia/7_trail/Drivers/MPU6050" -I"C:/Users/22334/workspace_ccstheia/7_trail" -I"C:/Users/22334/workspace_ccstheia/7_trail/Debug" -I"C:/ti/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_04_00_06/source" -I"C:/Users/22334/workspace_ccstheia/7_trail/Drivers/MSPM0" -DMOTION_DRIVER_TARGET_MSPM0 -DMPU6050 -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


