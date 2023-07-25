cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(urange C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(urange
	main.c
)

pico_enable_stdio_usb(urange 1)
pico_enable_stdio_uart(urange 1)

pico_add_extra_outputs(urange)

target_link_libraries(urange pico_stdlib)
