cmake_minimum_required(VERSION 3.22)

project(BSP_NUCLEO_STM32H563)
add_library(BSP_NUCLEO_STM32H563)

enable_language(C ASM)

add_library(targetflags INTERFACE)
#generc flags for all targets
target_compile_options(targetflags
    INTERFACE
    -Wall
    -Wextra
    -Wpedantic
    -fdata-sections
    -ffunction-sections
    $<$<CONFIG:Debug>:-O0 -g3>
    $<$<CONFIG:Release>:-Os -g0>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti -fno-exceptions -fno-threadsafe-statics>
    $<$<COMPILE_LANGUAGE:ASM>:-x assembler-with-cpp -MMD -MP>
)

target_link_options(targetflags
    INTERFACE
    -T${CMAKE_SOURCE_DIR}/STM32H563xx_FLASH.ld
    --specs=nano.specs
    -Wl,-Map=${CMAKE_PROJECT_NAME}.map
    -Wl,--gc-sections
    -Wl,--start-group
    -lc
    -lm
    -Wl,--end-group
    -Wl,--print-memory-usage
    $<$<COMPILE_LANGUAGE:CXX>:-Wl,--start-group -lstdc++ -lsupc++ -Wl,--end-group>
)

# flags for cortex-m33
target_compile_options(targetflags
    INTERFACE
    -mcpu=cortex-m33
    -mfpu=fpv4-sp-d16
    -mfloat-abi=hard
)

target_link_options(targetflags
    INTERFACE
    -mcpu=cortex-m33
    -mfpu=fpv4-sp-d16
    -mfloat-abi=hard
)

target_compile_definitions(BSP_NUCLEO_STM32H563 INTERFACE 
	STM32H563xx
    $<$<CONFIG:Debug>:DEBUG>
)

target_include_directories(BSP_NUCLEO_STM32H563 PUBLIC
    inc
)


target_sources(BSP_NUCLEO_STM32H563 PUBLIC
    src/main.c
    src/stm32h5xx_it.c
    src/stm32h5xx_hal_msp.c
    src/stm32h5xx_hal_timebase_tim.c
    src/system_stm32h5xx.c
    src/sysmem.c
    src/syscalls.c
    src/startup_stm32h563xx.s
    src/stm32h5xx_nucleo.c
    src/tx_initialize_low_level.S
    src/tx_thread_secure_stack_initialize.S
)

target_link_directories(BSP_NUCLEO_STM32H563 INTERFACE
)

target_link_libraries(BSP_NUCLEO_STM32H563 PUBLIC
    stm32h5xxhaldriver
    cmsisdeviceh5
    targetflags
)

add_threadx_target(
    BSP_NUCLEO_STM32H563
    cortex_m33
    gnu
    ${CMAKE_CURRENT_LIST_DIR}/inc/tx_user.h
)

target_link_libraries(threadx PRIVATE
    targetflags
)
