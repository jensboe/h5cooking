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


include("cmake/gcc-arm-none-eabi.cmake")


function(add_threadx_target TARGET ARCH TOOLCHAIN TX_USER_FILE)
    set(THREADX_ARCH ${ARCH} CACHE INTERNAL "")
    set(THREADX_TOOLCHAIN ${TOOLCHAIN} CACHE INTERNAL "")
    set(TX_USER_FILE ${TX_USER_FILE} CACHE INTERNAL "")

    add_subdirectory(
        ${CMAKE_SOURCE_DIR}/ext/threadx
        ${CMAKE_BINARY_DIR}/ext/threadx
    )
    target_link_libraries(${TARGET} PUBLIC threadx)
endfunction()


# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)



# Core project settings
project(${CMAKE_PROJECT_NAME})
message("Build type: " ${CMAKE_BUILD_TYPE})

# Enable CMake support for ASM and C languages
enable_language(C ASM CXX)


add_subdirectory(apps/blinky_yellow)
add_subdirectory(apps/blinky_red)
add_subdirectory(apps/blinky_green)
add_subdirectory(cmake/stm32h5xx-hal-driver)
add_subdirectory(cmake/cmsis-device-h5)
add_subdirectory(cmake/CMSIS_6)
add_subdirectory(bsp)

# Let's combine apps with BSPs

add_executable(blinky_yellow_h5)
target_link_libraries(blinky_yellow_h5 PRIVATE
    blinky_yellow
    BSP_NUCLEO_STM32H563
)

add_executable(blinky_red_h5)
target_link_libraries(blinky_red_h5 PRIVATE
    blinky_red
    BSP_NUCLEO_STM32H563
)

add_executable(blinky_green_h5)
target_link_libraries(blinky_green_h5 PRIVATE
    blinky_green
    BSP_NUCLEO_STM32H563
)

