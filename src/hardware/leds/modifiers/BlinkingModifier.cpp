#include "./BlinkingModifier.h"

#include "pico/time.h"

#include "../LedsStrip.h"

namespace {

uint64_t GetCurrentTime() {
    return to_us_since_boot(get_absolute_time());
}

}

namespace hardware {

BlinkingModifier::BlinkingModifier(uint64_t delta_ms): _idle_delta_us(delta_ms * US_TO_MS_MULTIPLIER),
                                                       _enabled_delta_us(delta_ms * US_TO_MS_MULTIPLIER),
                                                       _current_delta_us(0),
                                                       _lastknown_timestamp(GetCurrentTime()),
                                                       _is_enabled(false) {
    // empty on purpose
}

BlinkingModifier::BlinkingModifier(uint64_t idle_delta_ms, uint64_t enabled_delta_ms): _idle_delta_us(idle_delta_ms * US_TO_MS_MULTIPLIER), 
                                                                              _enabled_delta_us(enabled_delta_ms * US_TO_MS_MULTIPLIER),
                                                                              _current_delta_us(0),
                                                                              _lastknown_timestamp(GetCurrentTime()),
                                                                              _is_enabled(false) {
    // empty on purpose
}

void BlinkingModifier::onUpdate(LedsStrip& strip,
                                  uint16_t start,
                                  uint16_t finish) {
    for (uint16_t i = start; i <= finish; i++) {
        strip.setEnabled(i, _is_enabled);
    }

    uint64_t current_timestamp = GetCurrentTime();
    uint64_t diff = current_timestamp - _lastknown_timestamp;
    _current_delta_us += diff;
    _lastknown_timestamp = current_timestamp;

    if (_is_enabled && _current_delta_us >= _enabled_delta_us) {
        _is_enabled = false;
        _current_delta_us = 0;
    } else if (!_is_enabled && _current_delta_us >= _idle_delta_us) {
        _is_enabled = true;
        _current_delta_us = 0;
    }
}

}
