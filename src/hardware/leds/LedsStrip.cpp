#include "./LedsStrip.h"

#include <cmath>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"

#include <stdio.h>

// autogenerated header
#include "ws2812.pio.h"

#define DEFAULT_PIO pio0
#define STATE_MACHINE 0
#define WORKING_FREQ 800000
#define IS_32BIT_ALIGNMENT false

namespace {

inline void PutPixel(uint32_t rgb_pixel) {
    pio_sm_put_blocking(DEFAULT_PIO, 0, rgb_pixel << 8u);
}

inline uint16_t GetStartFromInterval(uint32_t interval) {
    return (uint16_t) (interval >> 16);
}

inline uint16_t GetFinishFromInterval(uint32_t interval) {
    return (uint16_t) (interval & 0x0000FFFF);
}

inline uint32_t CombineIntervals(uint16_t start, uint16_t finish) {
    return (((uint32_t) start) << 16) | finish;
}

} // namespace

namespace hardware {

LedsStrip::LedsStrip(uint8_t pin, uint16_t stripe_size): _pin(pin),
                                                        _stripe_size(stripe_size),
                                                        _enabled(new bool[stripe_size]),
                                                        _colors(new uint32_t[stripe_size]) {
    uint32_t offset = pio_add_program(DEFAULT_PIO, &ws2812_program);
    ws2812_program_init(DEFAULT_PIO, STATE_MACHINE, offset, pin, WORKING_FREQ, IS_32BIT_ALIGNMENT);

    for(int i = 0; i < size(); i++) {
        _enabled[i] = true;
        _colors[i] = LedColor::BLACK;
    }
}

void LedsStrip::setEnabled(uint16_t led, bool enabled) {
    if (!checkIndex(led)) {
        return;
    }

    _enabled[led] = enabled;
}

void LedsStrip::setColor(uint16_t led, LedColor const& color) {
    if (!checkIndex(led)) {
        return;
    }

    _colors[led] = (uint32_t) color;
}

void LedsStrip::addModifier(LightModifier* modifier,
                    uint16_t starting_led) {
    if (!checkIndex(starting_led)) {
        return;
    }
    
    uint16_t last_led = this->size() - 1;
    this->addModifier(modifier, starting_led, last_led);
}

void LedsStrip::addModifier(LightModifier* modifier,
                    uint16_t starting_led,
                    uint16_t finished_led) {
    if (!checkInterval(starting_led, finished_led)) {
        return;
    }

    uint32_t interval = CombineIntervals(starting_led, finished_led);

    _modifiers.push_back(modifier);
    _modifiers_interval.push_back(interval);
}

void LedsStrip::update() {
    clear();

    for (uint32_t i = 0; i < _modifiers.size(); i++) {
        LightModifier* modifier = _modifiers[i];
        uint32_t interval = _modifiers_interval[i];

        uint16_t start = GetStartFromInterval(interval);
        uint16_t finish = GetFinishFromInterval(interval);
        modifier->onUpdate(*this, start, finish);
    }

    for (uint32_t i = 0; i < this->size(); i++) {
        if (!_enabled[i]) {
            _colors[i] = LedColor::BLACK;
        }
    }

    /**
     * This loop should be as fast as possible,
     * because delays more than 400 milliseconds will
     * reset the whole sensor
     */
    for (uint32_t i = 0; i < this->size(); i++) {
        PutPixel(_colors[i]);
    }

    sleep_us(400);
}

void LedsStrip::clear() {
    for(int i = 0; i < size(); i++) {
        _enabled[i] = true;
        _colors[i] = LedColor::BLACK;
        PutPixel(_colors[i]);
    }

    sleep_us(400);
}

uint16_t LedsStrip::size() const {
    return _stripe_size;
}

bool LedsStrip::checkInterval(uint16_t starting_led, uint16_t finished_led) const {
    if (finished_led < starting_led) {
        return false;
    }

    if (!checkIndex(starting_led) || !checkIndex(finished_led)) {
        return false;
    }

    return true;
}

bool LedsStrip::checkIndex(uint16_t led) const {
    return led >= 0 && led < this->size();
}

LedsStrip::~LedsStrip() {
    delete[] _colors;
    delete[] _enabled;
}

} // namespace hardware
