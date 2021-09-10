#include "./ProgressiveModifier.h"

#include "../../../utils/MathUtils.h"
#include "../LedsStrip.h"

namespace hardware {

uint16_t ProgressiveModifier::getActiveLed(double progress, uint16_t start, uint16_t finish) const {
    uint16_t length = finish - start + 1;
    uint16_t active_led = utils::ceiling<double, uint16_t>(progress * length);
    return start + active_led;
}

LedColor ProgressiveModifier::getActiveColor(double progress) const {
    return LedColor::Lerp(_start, _finish, progress);
}

ProgressiveModifier::ProgressiveModifier(LedColor const& start, LedColor const& finish): _start(start), _finish(finish) {
    // empty on purpose
}

void ProgressiveModifier::onUpdate(LedsStrip& strip, uint16_t start, uint16_t finish) {
    double progress = this->getProgress();

    uint16_t active_led = getActiveLed(progress, start, finish);
    LedColor color = getActiveColor(progress);

    for (uint16_t i = start; i <= active_led; i++) {
        strip.setColor(i, color);
    }

    for (uint16_t i = active_led + 1; i <= finish; i++) {
        strip.setEnabled(i, false);
    }
}

} // namespace hardware
