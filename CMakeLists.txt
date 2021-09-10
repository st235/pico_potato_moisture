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

                       src/hardware/moisture/MoistureModifier.h
                       src/hardware/moisture/MoistureModifier.cpp

                       src/hardware/moisture/MoistureSensor.h
                       src/hardware/moisture/MoistureSensor.cpp

                       src/hardware/leds/LedColor.h
                       src/hardware/leds/LedColor.cpp

                       src/hardware/leds/LedsStrip.h
                       src/hardware/leds/LedsStrip.cpp

                       src/hardware/leds/modifiers/LightModifier.h

                       src/hardware/leds/modifiers/SolidColorModifier.h
                       src/hardware/leds/modifiers/SolidColorModifier.cpp

                       src/hardware/leds/modifiers/BlinkingModifier.h
                       src/hardware/leds/modifiers/BlinkingModifier.cpp

                       src/hardware/leds/modifiers/ProgressiveModifier.h
                       src/hardware/leds/modifiers/ProgressiveModifier.cpp

                       src/utils/MathUtils.h)

target_link_libraries(potato_moisture PRIVATE pico_stdlib hardware_pio pico_multicore pico_time hardware_adc)
pico_add_extra_outputs(potato_moisture)

