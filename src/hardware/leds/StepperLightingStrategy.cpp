#include "./StepperLightingStrategy.h"

namespace hardware {

StepperLightingStrategy::StepperLightingStrategy(uint32_t start_led, 
                                                 uint32_t last_led,
                                                 double data_step,
                                                 uint32_t const* colors,
                                                 uint32_t blink_threshold): _start_led(start_led), _last_led(last_led), _data_step(data_step), _colors(colors), _blink_threshold(blink_threshold) {
    _is_blinking = false;
}

uint32_t StepperLightingStrategy::getPixelColor(uint32_t const pixel) const {
    if (pixel < _start_led || pixel > _last_led) {
        return LightingStrategy::COLOR_BLACK;
    }

    if (pixel > _max_available_pixel) {
        return LightingStrategy::COLOR_BLACK;
    }

    if (_current_progress < _blink_threshold && !_is_blinking) {
        return LightingStrategy::COLOR_BLACK;
    }

    return _colors[_current_progress];
}

void StepperLightingStrategy::onTick(const double progress) {
    double step = progress / _data_step;
    this->_current_progress = (uint32_t) step;

    double interval = _last_led - _start_led + 1;
    _max_available_pixel = _start_led + (uint32_t) (interval * progress);
    _is_blinking = !_is_blinking;
}

StepperLightingStrategy::~StepperLightingStrategy() {
    delete[] _colors;
}

} // namespace hardware
