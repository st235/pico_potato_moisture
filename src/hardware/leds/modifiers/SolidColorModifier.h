#ifndef SRC_HARDWARE_LEDS_SOLIDCOLORMODIFIER_H
#define SRC_HARDWARE_LEDS_SOLIDCOLORMODIFIER_H

#include <cstdint>

#include "./LightModifier.h"
#include "../LedColor.h"

namespace hardware {

class LedsStrip;

class SolidColorModifier: public LightModifier {
private:
    LedColor _color;

public:
    explicit SolidColorModifier(LedColor const& color);

    void onUpdate(LedsStrip& strip,
                  uint16_t start,
                  uint16_t finish) override;

    ~SolidColorModifier() = default;
};

} // namespace hardware

#endif // SRC_HARDWARE_LEDS_SOLIDCOLORMODIFIER_H