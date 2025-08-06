cmake_minimum_required(VERSION 3.22)

project(stm32cubemx)
add_library(stm32cubemx INTERFACE)

# Enable CMake support for ASM and C languages
enable_language(C ASM)

target_compile_definitions(stm32cubemx INTERFACE 
	USE_HAL_DRIVER 
	STM32H563xx
    $<$<CONFIG:Debug>:DEBUG>
)

target_include_directories(stm32cubemx INTERFACE
    ../../bsp/inc
    ../../AZURE_RTOS/App
    ../../ext/stm32h5xx-hal-driver/Inc
    ../../ext/stm32h5xx-hal-driver/Inc/Legacy
    ../../Drivers/BSP/STM32H5xx_Nucleo
    ../../ext/cmsis-device-h5/Include
    ../../ext/CMSIS_6/CMSIS/Core/Include
)

target_sources(stm32cubemx INTERFACE
    ../../bsp/Src/main.c
    ../../bsp/Src/app_threadx.c
    ../../bsp/Src/stm32h5xx_it.c
    ../../bsp/Src/stm32h5xx_hal_msp.c
    ../../bsp/Src/stm32h5xx_hal_timebase_tim.c
    ../../AZURE_RTOS/App/app_azure_rtos.c
    ../../Drivers/BSP/STM32H5xx_Nucleo/stm32h5xx_nucleo.c
    ../../ext/stm32h5xx-hal-driver/Src/stm32h5xx_hal_cortex.c
    ../../ext/stm32h5xx-hal-driver/Src/stm32h5xx_hal_rcc.c
    ../../ext/stm32h5xx-hal-driver/Src/stm32h5xx_hal_rcc_ex.c
    ../../ext/stm32h5xx-hal-driver/Src/stm32h5xx_hal_flash.c
    ../../ext/stm32h5xx-hal-driver/Src/stm32h5xx_hal_flash_ex.c
    ../../ext/stm32h5xx-hal-driver/Src/stm32h5xx_hal_gpio.c
    ../../ext/stm32h5xx-hal-driver/Src/stm32h5xx_hal_dma.c
    ../../ext/stm32h5xx-hal-driver/Src/stm32h5xx_hal_dma_ex.c
    ../../ext/stm32h5xx-hal-driver/Src/stm32h5xx_hal_pwr.c
    ../../ext/stm32h5xx-hal-driver/Src/stm32h5xx_hal_pwr_ex.c
    ../../ext/stm32h5xx-hal-driver/Src/stm32h5xx_hal.c
    ../../ext/stm32h5xx-hal-driver/Src/stm32h5xx_hal_exti.c
    ../../ext/stm32h5xx-hal-driver/Src/stm32h5xx_hal_tim.c
    ../../ext/stm32h5xx-hal-driver/Src/stm32h5xx_hal_tim_ex.c
    ../../ext/stm32h5xx-hal-driver/Src/stm32h5xx_hal_usart.c
    ../../ext/stm32h5xx-hal-driver/Src/stm32h5xx_hal_usart_ex.c
    ../../ext/stm32h5xx-hal-driver/Src/stm32h5xx_hal_uart_ex.c
    ../../ext/stm32h5xx-hal-driver/Src/stm32h5xx_hal_uart.c
    ../../bsp/src/system_stm32h5xx.c
    ../../bsp/src/sysmem.c
    ../../bsp/src/syscalls.c
    ../../startup_stm32h563xx.s
    ../../bsp/src/tx_initialize_low_level.S
)

target_link_directories(stm32cubemx INTERFACE
)

target_link_libraries(stm32cubemx INTERFACE
)

# Validate that STM32CubeMX code is compatible with C standard
if(CMAKE_C_STANDARD LESS 11)
    message(ERROR "Generated code requires C11 or higher")
endif()


