cmake_minimum_required(VERSION 3.22)

project(BSP_NUCLEO_STM32H563)
add_library(BSP_NUCLEO_STM32H563)

# Enable CMake support for ASM and C languages
enable_language(C ASM)

target_compile_definitions(BSP_NUCLEO_STM32H563 INTERFACE 
	STM32H563xx
    $<$<CONFIG:Debug>:DEBUG>
)

target_include_directories(BSP_NUCLEO_STM32H563 PUBLIC
    inc
)

target_sources(BSP_NUCLEO_STM32H563 PUBLIC
    src/main.c
    src/app_threadx.c
    src/stm32h5xx_it.c
    src/stm32h5xx_hal_msp.c
    src/stm32h5xx_hal_timebase_tim.c
    src/system_stm32h5xx.c
    src/sysmem.c
    src/syscalls.c
    src/startup_stm32h563xx.s
    src/tx_initialize_low_level.S
)

target_link_directories(BSP_NUCLEO_STM32H563 INTERFACE
)

target_link_libraries(BSP_NUCLEO_STM32H563 PUBLIC
    stm32h5xxhaldriver
    cmsisdeviceh5
    stm32cubemx
    threadx
)