cmake_minimum_required(VERSION 3.22)

project(cmsisdeviceh5)
add_library(cmsisdeviceh5 INTERFACE)

# Enable CMake support for ASM and C languages
enable_language(C ASM)

target_compile_definitions(cmsisdeviceh5 INTERFACE 
	STM32H563xx
)

target_include_directories(cmsisdeviceh5 INTERFACE
    ../../ext/cmsis-device-h5/Include
    ../../ext/CMSIS_6/CMSIS/Core/Include
)

target_sources(cmsisdeviceh5 INTERFACE

)

target_link_directories(cmsisdeviceh5 INTERFACE
)

target_link_libraries(cmsisdeviceh5 INTERFACE
)

# Validate that cmsisdeviceh5 code is compatible with C standard
if(CMAKE_C_STANDARD LESS 11)
    message(ERROR "Generated code requires C11 or higher")
endif()


