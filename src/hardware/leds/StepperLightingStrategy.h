#ifndef SRC_HARDWARE_LEDS_STEPPERLIGHTING_STRATEGY_H
#define SRC_HARDWARE_LEDS_STEPPERLIGHTING_STRATEGY_H

#include <cstdint>

#include "./LightingStrategy.h"

namespace hardware {

class StepperLightingStrategy: public LightingStrategy {
private:
    uint32_t const* _colors;

    uint32_t const _start_led;
    uint32_t const _last_led;
    double const _data_step;
    uint32_t const _blink_threshold;

    // [0..1]
    uint32_t _current_progress;
    uint32_t _max_available_pixel;
    bool _is_blinking;

public:
    StepperLightingStrategy(uint32_t start_led, 
                            uint32_t last_led,
                            double data_step,
                            uint32_t const* colors,
                            uint32_t blink_threshold = 0);

    StepperLightingStrategy(StepperLightingStrategy const& strategy) = delete;

    StepperLightingStrategy& operator=(StepperLightingStrategy const& strategy) = delete;

    uint32_t getPixelColor(uint32_t pixel) const override;

    void onTick(const double progress);

    ~StepperLightingStrategy() override;

};

}

#endif // SRC_HARDWARE_LEDS_STEPPERLIGHTING_STRATEGY_H
