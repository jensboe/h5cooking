cmake_minimum_required(VERSION 3.22)

project(blinky_yellow)
add_library(blinky_yellow)

enable_language(C CXX)

target_include_directories(blinky_yellow PRIVATE
    inc
)

target_sources(blinky_yellow PRIVATE
    main.cpp
)

target_link_libraries(blinky_yellow PRIVATE
    BSP_NUCLEO_STM32H563
)