#ifndef SRC_HARDWARE_LEDS_BLINKINGMODIFIER_H
#define SRC_HARDWARE_LEDS_BLINKINGMODIFIER_H

#include <cstdint>

#include "./LightModifier.h"

namespace hardware {

class LedsStrip;

class BlinkingModifier: public LightModifier {
private:
    static const uint16_t US_TO_MS_MULTIPLIER = 1000;

    uint64_t _idle_delta_us;
    uint64_t _enabled_delta_us;

    uint64_t _current_delta_us;
    uint64_t _lastknown_timestamp;

    bool _is_enabled;

public:
    explicit BlinkingModifier(uint64_t delta_ms);
    explicit BlinkingModifier(uint64_t idle_delta_us, uint64_t enabled_delta_us);

    void onUpdate(LedsStrip& strip,
                  uint16_t start,
                  uint16_t finish) override;

    ~BlinkingModifier() = default;
};

} // namespace hardware

#endif // SRC_HARDWARE_LEDS_BLINKINGMODIFIER_H