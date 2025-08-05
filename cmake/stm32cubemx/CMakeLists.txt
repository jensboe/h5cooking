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
    ../../Core/Inc
    ../../AZURE_RTOS/App
    ../../Drivers/BSP/STM32H5xx_Nucleo
)

target_sources(stm32cubemx INTERFACE
    ../../Core/Src/main.c
    ../../Core/Src/app_threadx.c
    ../../Core/Src/stm32h5xx_it.c
    ../../Core/Src/stm32h5xx_hal_msp.c
    ../../Core/Src/stm32h5xx_hal_timebase_tim.c
    ../../AZURE_RTOS/App/app_azure_rtos.c
    ../../Drivers/BSP/STM32H5xx_Nucleo/stm32h5xx_nucleo.c
    ../../Core/Src/system_stm32h5xx.c
    ../../Core/Src/sysmem.c
    ../../Core/Src/syscalls.c
    ../../startup_stm32h563xx.s
    ../../Core/Src/tx_initialize_low_level.S
)

target_link_directories(stm32cubemx INTERFACE
)

target_link_libraries(stm32cubemx INTERFACE
)

# Validate that STM32CubeMX code is compatible with C standard
if(CMAKE_C_STANDARD LESS 11)
    message(ERROR "Generated code requires C11 or higher")
endif()


