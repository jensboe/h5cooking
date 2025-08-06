cmake_minimum_required(VERSION 3.22)

#
# This file is generated only once,
# and is not re-generated if converter is called multiple times.
#
# User is free to modify the file as much as necessary
#

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

# Define the build type
if(NOT CMAKE_BUILD_TYPE)
set(CMAKE_BUILD_TYPE "Debug")
endif()

# Set the project name
set(CMAKE_PROJECT_NAME H5cocking)

# Include toolchain file
include("cmake/gcc-arm-none-eabi.cmake")
set(THREADX_ARCH cortex_m7)
set(THREADX_TOOLCHAIN gnu)
set(TX_USER_FILE ${CMAKE_CURRENT_LIST_DIR}/bsp/inc/tx_user.h)
add_subdirectory(ext/threadx)

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)



# Core project settings
project(${CMAKE_PROJECT_NAME})
message("Build type: " ${CMAKE_BUILD_TYPE})

# Enable CMake support for ASM and C languages
enable_language(C ASM CXX)


add_subdirectory(cmake/stm32h5xx-hal-driver)
add_subdirectory(cmake/cmsis-device-h5)
add_subdirectory(cmake/CMSIS_6)
add_subdirectory(bsp)

add_executable(${CMAKE_PROJECT_NAME})


target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
    BSP_NUCLEO_STM32H563
)
