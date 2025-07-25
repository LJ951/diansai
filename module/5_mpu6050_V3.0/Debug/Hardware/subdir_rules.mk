################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Hardware/%.o: ../Hardware/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/22334/workspace_ccstheia/5_mpu6050_V3.0/BSP/MPU6050" -I"C:/Users/22334/workspace_ccstheia/5_mpu6050_V3.0/BSP/MPU6050/DMP" -I"C:/Users/22334/workspace_ccstheia/5_mpu6050_V3.0/Control" -I"C:/Users/22334/workspace_ccstheia/5_mpu6050_V3.0/HARDWARE" -I"C:/Users/22334/workspace_ccstheia/5_mpu6050_V3.0" -I"C:/Users/22334/workspace_ccstheia/5_mpu6050_V3.0/Debug" -I"C:/ti/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_04_00_06/source" -gdwarf-3 -MMD -MP -MF"Hardware/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


