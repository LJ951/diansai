################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
modules/src/%.o: ../modules/src/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/22334/workspace_ccstheia/9_car_V2.1/BSP/MPU6050" -I"C:/Users/22334/workspace_ccstheia/9_car_V2.1/BSP/MPU6050/DMP" -I"C:/Users/22334/workspace_ccstheia/9_car_V2.1/Control" -I"C:/Users/22334/workspace_ccstheia/9_car_V2.1/HARDWARE" -I"C:/Users/22334/workspace_ccstheia/9_car_V2.1/modules/src" -I"C:/Users/22334/workspace_ccstheia/9_car_V2.1/modules/inc" -I"C:/Users/22334/workspace_ccstheia/9_car_V2.1" -I"C:/Users/22334/workspace_ccstheia/9_car_V2.1/Debug" -I"C:/ti/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_04_00_06/source" -gdwarf-3 -MMD -MP -MF"modules/src/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


