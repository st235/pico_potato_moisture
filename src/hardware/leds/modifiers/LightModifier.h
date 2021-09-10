#ifndef SRC_HARDWARE_LEDS_LIGHTMODIFIER_H
#define SRC_HARDWARE_LEDS_LIGHTMODIFIER_H

#include <cstdint>

namespace hardware {

class LedsStrip;

class LightModifier {
public:
    virtual void onUpdate(LedsStrip& strip,
                              uint16_t start,
                              uint16_t finish) = 0;

    virtual ~LightModifier() {
        // empty on purpose
    };
};

} // namespace hardware

#endif // SRC_HARDWARE_LEDS_LIGHTMODIFIER_H
