#ifndef SRC_HARDWARE_LEDS_NEOPUXELSENSOR_H
#define SRC_HARDWARE_LEDS_NEOPUXELSENSOR_H

#include <cstdint>

namespace hardware {

class NeoPixelSensor {
private:
    uint8_t const _pin;
    uint32_t const _leds_count;
    uint32_t const _starting_led;
    uint32_t const* _colors;

    uint32_t _selected_color;
    uint32_t _active_color;

public:
    NeoPixelSensor(uint8_t pin, uint32_t leds_count, uint32_t starting_led, uint32_t colors[]);

    uint32_t pixelAt(uint32_t pixel);

    void setProgress(double progress);

    uint32_t size();

    void start();
};

} // namespace hardware

#endif // SRC_HARDWARE_LEDS_NEOPUXELSENSOR_H
