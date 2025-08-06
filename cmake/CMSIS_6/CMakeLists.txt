cmake_minimum_required(VERSION 3.22)

project(cmsis_6)
add_library(cmsis_6 INTERFACE)

target_include_directories(cmsis_6 INTERFACE
    ../../ext/CMSIS_6/CMSIS/Core/Include
)