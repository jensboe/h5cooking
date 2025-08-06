cmake_minimum_required(VERSION 3.22)

project(cmsisdeviceh5)
add_library(cmsisdeviceh5 INTERFACE)

target_include_directories(cmsisdeviceh5 INTERFACE
    ../../ext/cmsis-device-h5/Include
)