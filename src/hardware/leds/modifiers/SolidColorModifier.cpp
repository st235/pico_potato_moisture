#include "./SolidColorModifier.h"

#include "../LedsStrip.h"

namespace hardware {

SolidColorModifier::SolidColorModifier(LedColor const& color): _color(color) {
    // empty on purpose
}

void SolidColorModifier::onUpdate(LedsStrip& strip,
                                  uint16_t start,
                                  uint16_t finish) {
    for (uint16_t i = start; i <= finish; i++) {
        strip.setColor(i, _color);
    }
}

}
