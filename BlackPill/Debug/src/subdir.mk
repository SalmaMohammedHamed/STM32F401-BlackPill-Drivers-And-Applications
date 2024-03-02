################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/DMA_program.c \
../src/EXTI_program.c \
../src/GPIO_program.c \
../src/Lcd_Program.c \
../src/NVIC_program.c \
../src/OS_program.c \
../src/RCC_program.c \
../src/SYSCFG_program.c \
../src/SysTick_program.c \
../src/main.c 

OBJS += \
./src/DMA_program.o \
./src/EXTI_program.o \
./src/GPIO_program.o \
./src/Lcd_Program.o \
./src/NVIC_program.o \
./src/OS_program.o \
./src/RCC_program.o \
./src/SYSCFG_program.o \
./src/SysTick_program.o \
./src/main.o 

C_DEPS += \
./src/DMA_program.d \
./src/EXTI_program.d \
./src/GPIO_program.d \
./src/Lcd_Program.d \
./src/NVIC_program.d \
./src/OS_program.d \
./src/RCC_program.d \
./src/SYSCFG_program.d \
./src/SysTick_program.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=25000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


