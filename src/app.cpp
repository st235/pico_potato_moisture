#include <cstdint>
#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "hardware/adc.h"

#include "./hardware/moisture/MoistureSensor.h"
#include "./hardware/leds/NeoPixelSensor.h"

namespace {

inline uint32_t ConvertToRgbPixel(uint8_t r, uint8_t g, uint8_t b) {
    return  ((uint32_t) (r) << 8) |
            ((uint32_t) (g) << 16) |
            (uint32_t) (b);
}

} // namespace

int main() {
	stdio_init_all();

	adc_init();

	hardware::MoistureSensor moisture_sensor(26 /* pin */, 1400U /* min current, water */, 3500U /* max current, air */);
	
	uint32_t colors[] = {
		ConvertToRgbPixel(0x44, 0x00, 0x00),
		ConvertToRgbPixel(0x88, 0x00, 0x00),
		ConvertToRgbPixel(0x44, 0x44, 0x00),
		ConvertToRgbPixel(0x88, 0x88, 0x00),
		ConvertToRgbPixel(0x00, 0x44, 0x00),
		ConvertToRgbPixel(0x00, 0x88, 0x00)
	};
	hardware::neopixel::Start(0 /* pin */, 7 /* leds_count */, 1 /* starting_led */, colors);

	while (true) {
		double progress = moisture_sensor.normalisedValue();
		printf("Moisture progress from sensor is: %.6f\n", progress);
		hardware::neopixel::SetProgress(progress);
		sleep_ms(400);
    }
}
