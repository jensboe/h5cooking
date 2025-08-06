cmake_minimum_required(VERSION 3.22)

project(blinky_red)
add_library(blinky_red)

enable_language(C)

target_include_directories(blinky_red PRIVATE
    inc
)

target_sources(blinky_red PRIVATE
    main.c
)

target_link_libraries(blinky_red PRIVATE
    BSP_NUCLEO_STM32H563
)