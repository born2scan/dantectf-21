cmake_minimum_required(VERSION 3.13)
set(PICO_SDK_FETCH_FROM_GIT on)
include(pico_sdk_import.cmake)

project(pio_morse)

pico_sdk_init()

add_executable(pio_morse)
pico_generate_pio_header(pio_morse ${CMAKE_CURRENT_LIST_DIR}/morse.pio)
target_sources(pio_morse PRIVATE morse.c)
target_link_libraries(pio_morse PRIVATE pico_stdlib hardware_pio)
pico_add_extra_outputs(pio_morse)

#pico_enable_stdio_usb(pio_morse 1)
#pico_enable_stdio_uart(pio_morse 1)