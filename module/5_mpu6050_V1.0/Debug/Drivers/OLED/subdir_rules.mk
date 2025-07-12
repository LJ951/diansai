################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Drivers/OLED/%.o: ../Drivers/OLED/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/22334/workspace_ccstheia/5_mpu6050_V1.0/Drivers/Ultrasonic_GPIO" -I"C:/Users/22334/workspace_ccstheia/5_mpu6050_V1.0/Drivers/Ultrasonic_Capture" -I"C:/Users/22334/workspace_ccstheia/5_mpu6050_V1.0/Drivers/OLED" -I"C:/Users/22334/workspace_ccstheia/5_mpu6050_V1.0/Drivers/MPU6050" -I"C:/Users/22334/workspace_ccstheia/5_mpu6050_V1.0" -I"C:/Users/22334/workspace_ccstheia/5_mpu6050_V1.0/Debug" -I"C:/ti/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_04_00_06/source" -I"C:/Users/22334/workspace_ccstheia/5_mpu6050_V1.0/Drivers/MSPM0" -DMOTION_DRIVER_TARGET_MSPM0 -DMPU6050 -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"Drivers/OLED/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


