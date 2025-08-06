cmake_minimum_required(VERSION 3.22)

project(stm32cubemx)
add_library(stm32cubemx INTERFACE)

# Enable CMake support for ASM and C languages
enable_language(C ASM)

target_compile_definitions(stm32cubemx INTERFACE 
	STM32H563xx
)

target_include_directories(stm32cubemx INTERFACE
    ../../bsp/inc    
    ../../AZURE_RTOS/App
)

target_sources(stm32cubemx INTERFACE
    ../../AZURE_RTOS/App/app_azure_rtos.c
)

target_link_directories(stm32cubemx INTERFACE
)

target_link_libraries(stm32cubemx INTERFACE
)

# Validate that STM32CubeMX code is compatible with C standard
if(CMAKE_C_STANDARD LESS 11)
    message(ERROR "Generated code requires C11 or higher")
endif()


