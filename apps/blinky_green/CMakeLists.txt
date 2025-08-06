cmake_minimum_required(VERSION 3.22)

project(blinky_green)
add_library(blinky_green)

enable_language(C)

target_include_directories(blinky_green PRIVATE
    inc
)

target_sources(blinky_green PRIVATE
    main.c
)

target_link_libraries(blinky_green PRIVATE
    BSP_NUCLEO_STM32H563
)