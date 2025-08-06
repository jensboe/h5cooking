cmake_minimum_required(VERSION 3.22)

project(stm32h5xxhaldriver)
add_library(stm32h5xxhaldriver)

# Enable CMake support for ASM and C languages
enable_language(C ASM)

target_compile_definitions(stm32h5xxhaldriver PUBLIC 
	USE_HAL_DRIVER 
	STM32H563xx
)

target_include_directories(stm32h5xxhaldriver
    PUBLIC
    ../../ext/stm32h5xx-hal-driver/Inc
    ../../ext/stm32h5xx-hal-driver/Inc/Legacy
    PRIVATE
    ../../bsp/NUCLEO_STM32H563/inc
)

target_sources(stm32h5xxhaldriver PUBLIC
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
)


target_link_libraries(stm32h5xxhaldriver PUBLIC
    cmsisdeviceh5
    cmsis_6
)
