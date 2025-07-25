################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/22334/workspace_ccstheia/5_mpu6050_V3.0/BSP/MPU6050" -I"C:/Users/22334/workspace_ccstheia/5_mpu6050_V3.0/BSP/MPU6050/DMP" -I"C:/Users/22334/workspace_ccstheia/5_mpu6050_V3.0/Control" -I"C:/Users/22334/workspace_ccstheia/5_mpu6050_V3.0/HARDWARE" -I"C:/Users/22334/workspace_ccstheia/5_mpu6050_V3.0" -I"C:/Users/22334/workspace_ccstheia/5_mpu6050_V3.0/Debug" -I"C:/ti/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_04_00_06/source" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-2094050913: ../empty.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/sysconfig_1.21.1/sysconfig_cli.bat" --script "C:/Users/22334/workspace_ccstheia/5_mpu6050_V3.0/empty.syscfg" -o "." -s "C:/ti/mspm0_sdk_2_04_00_06/.metadata/product.json" --compiler ticlang
	@echo 'Finished building: "$<"'
	@echo ' '

device_linker.cmd: build-2094050913 ../empty.syscfg
device.opt: build-2094050913
device.cmd.genlibs: build-2094050913
ti_msp_dl_config.c: build-2094050913
ti_msp_dl_config.h: build-2094050913
Event.dot: build-2094050913

%.o: ./%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/22334/workspace_ccstheia/5_mpu6050_V3.0/BSP/MPU6050" -I"C:/Users/22334/workspace_ccstheia/5_mpu6050_V3.0/BSP/MPU6050/DMP" -I"C:/Users/22334/workspace_ccstheia/5_mpu6050_V3.0/Control" -I"C:/Users/22334/workspace_ccstheia/5_mpu6050_V3.0/HARDWARE" -I"C:/Users/22334/workspace_ccstheia/5_mpu6050_V3.0" -I"C:/Users/22334/workspace_ccstheia/5_mpu6050_V3.0/Debug" -I"C:/ti/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_04_00_06/source" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

startup_mspm0g350x_ticlang.o: C:/ti/mspm0_sdk_2_04_00_06/source/ti/devices/msp/m0p/startup_system_files/ticlang/startup_mspm0g350x_ticlang.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/22334/workspace_ccstheia/5_mpu6050_V3.0/BSP/MPU6050" -I"C:/Users/22334/workspace_ccstheia/5_mpu6050_V3.0/BSP/MPU6050/DMP" -I"C:/Users/22334/workspace_ccstheia/5_mpu6050_V3.0/Control" -I"C:/Users/22334/workspace_ccstheia/5_mpu6050_V3.0/HARDWARE" -I"C:/Users/22334/workspace_ccstheia/5_mpu6050_V3.0" -I"C:/Users/22334/workspace_ccstheia/5_mpu6050_V3.0/Debug" -I"C:/ti/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_04_00_06/source" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


