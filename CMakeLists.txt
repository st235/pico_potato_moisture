cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(potato_moisture)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(potato_moisture)

pico_generate_pio_header(potato_moisture ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio)

pico_enable_stdio_usb(potato_moisture 1)
pico_enable_stdio_uart(potato_moisture 1)

target_sources(potato_moisture 
               PRIVATE src/app.cpp

                       src/hardware/moisture/MoistureSensor.h
                       src/hardware/moisture/MoistureSensor.cpp

                       src/hardware/leds/NeoPixelSensor.h
                       src/hardware/leds/NeoPixelSensor.cpp

                       src/utils/MathUtils.h
                       src/utils/MathUtils.cpp)

target_link_libraries(potato_moisture PRIVATE pico_stdlib hardware_pio pico_multicore hardware_adc)
pico_add_extra_outputs(potato_moisture)

