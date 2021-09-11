#include <cstdint>
#include <stdlib.h>
#include <stdio.h>

#include "pico/stdlib.h"
#include "pico/time.h"
#include "hardware/adc.h"

#include "Constants.h"

#include "./hardware/moisture/MoistureModifier.h"
#include "./hardware/moisture/MoistureSensor.h"

#include "./hardware/leds/LedColor.h"
#include "./hardware/leds/LedsStrip.h"
#include "./hardware/leds/modifiers/BlinkingModifier.h"
#include "./hardware/leds/modifiers/SolidColorModifier.h"

#include "./hardware/timer/SystemTimer.h"

int main() {
	stdio_init_all();

	adc_init();

	hardware::SystemTimer system_timer(TIMEZONE, BUILD_TIMESTAMP);

	hardware::MoistureSensor moisture_sensor(
		26 /* pin */, 
		1400U /* min current, water */, 
		3500U /* max current, air */
	);

	hardware::LedsStrip leds_strip(
		0 /* pin */,
		7 /* stripe size */
	);

	hardware::MoistureModifier moisture_led_modifier(
		&moisture_sensor /* sensor */,
		hardware::LedColor::RED.withBrigthness(0.5) /* start color */,
		hardware::LedColor::GREEN.withBrigthness(0.5) /* finish color */
	);

	hardware::SolidColorModifier red_color_modifier(
		hardware::LedColor::RED.withBrigthness(0.1) /* color */
	);

	hardware::BlinkingModifier blink_modifier(
		5000 /* delay idle in ms */,
		1000 /* delay working in ms */
	);

	leds_strip.addModifier(&red_color_modifier, 0, 0);
	leds_strip.addModifier(&blink_modifier, 0, 0);

	leds_strip.addModifier(&moisture_led_modifier, 1);

	while (true) {
		uint8_t current_hour = system_timer.getHours();
		printf("Current time: %02u:%02u:%02u\n", system_timer.getHours(), system_timer.getMinutes(), system_timer.getSeconds());

		if (current_hour >= WORKING_MIN_HOUR && current_hour <= WORKING_MAX_HOUR) {
			leds_strip.update();
		} else {
			leds_strip.clear();
		}

		sleep_ms(300);
    }

	return 0;
}
