################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.c \
../Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.c \
../Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c \
../Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_exti.c \
../Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash.c \
../Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash_ex.c \
../Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.c \
../Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio_ex.c \
../Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pwr.c \
../Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc.c \
../Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc_ex.c \
../Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim.c \
../Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim_ex.c 

OBJS += \
./Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.o \
./Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.o \
./Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.o \
./Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_exti.o \
./Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash.o \
./Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash_ex.o \
./Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.o \
./Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio_ex.o \
./Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pwr.o \
./Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc.o \
./Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc_ex.o \
./Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim.o \
./Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim_ex.o 

C_DEPS += \
./Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.d \
./Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.d \
./Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.d \
./Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_exti.d \
./Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash.d \
./Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash_ex.d \
./Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.d \
./Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio_ex.d \
./Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pwr.d \
./Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc.d \
./Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc_ex.d \
./Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim.d \
./Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim_ex.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/%.o: ../Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/%.c Core/Startup/Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103x6 -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

