#ifndef SRC_HARDWARE_LEDS_NEOPUXELSENSOR_H
#define SRC_HARDWARE_LEDS_NEOPUXELSENSOR_H

#include <cstdint>

namespace hardware {

namespace neopixel {

void Start(uint8_t pin, uint32_t leds_count, uint32_t starting_led, uint32_t colors[]);

void SetProgress(double progress);

} // namespace neopixel

} // namespace hardware

#endif // SRC_HARDWARE_LEDS_NEOPUXELSENSOR_H
