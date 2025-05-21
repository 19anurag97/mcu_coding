################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ThirdParty/FreeRtos/portable/GCC/ARM_CM4F/port.c 

OBJS += \
./ThirdParty/FreeRtos/portable/GCC/ARM_CM4F/port.o 

C_DEPS += \
./ThirdParty/FreeRtos/portable/GCC/ARM_CM4F/port.d 


# Each subdirectory must supply rules for building sources it contributes
ThirdParty/FreeRtos/portable/GCC/ARM_CM4F/%.o ThirdParty/FreeRtos/portable/GCC/ARM_CM4F/%.su ThirdParty/FreeRtos/portable/GCC/ARM_CM4F/%.cyclo: ../ThirdParty/FreeRtos/portable/GCC/ARM_CM4F/%.c ThirdParty/FreeRtos/portable/GCC/ARM_CM4F/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"C:/Users/19anu/OneDrive/Desktop/Github_projects/mcu_coding/STM_RTOS/RTOS_Workspace/RTOS_Work/ThirdParty/FreeRtos" -I"C:/Users/19anu/OneDrive/Desktop/Github_projects/mcu_coding/STM_RTOS/RTOS_Workspace/RTOS_Work/ThirdParty/FreeRtos/include" -I"C:/Users/19anu/OneDrive/Desktop/Github_projects/mcu_coding/STM_RTOS/RTOS_Workspace/RTOS_Work/ThirdParty/FreeRtos/portable/GCC/ARM_CM4F" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ThirdParty-2f-FreeRtos-2f-portable-2f-GCC-2f-ARM_CM4F

clean-ThirdParty-2f-FreeRtos-2f-portable-2f-GCC-2f-ARM_CM4F:
	-$(RM) ./ThirdParty/FreeRtos/portable/GCC/ARM_CM4F/port.cyclo ./ThirdParty/FreeRtos/portable/GCC/ARM_CM4F/port.d ./ThirdParty/FreeRtos/portable/GCC/ARM_CM4F/port.o ./ThirdParty/FreeRtos/portable/GCC/ARM_CM4F/port.su

.PHONY: clean-ThirdParty-2f-FreeRtos-2f-portable-2f-GCC-2f-ARM_CM4F

