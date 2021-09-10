#ifndef SRC_HARDWARE_LEDS_PROGRESSIVEMODIFIER_H
#define SRC_HARDWARE_LEDS_PROGRESSIVEMODIFIER_H

#include <cstdint>

#include "../LedColor.h"
#include "./LightModifier.h"

namespace hardware {

class LedsStrip;

class ProgressiveModifier: public LightModifier {
private:
    LedColor _start;
    LedColor _finish;

    uint16_t getActiveLed(double progress, uint16_t start, uint16_t finish) const;
    LedColor getActiveColor(double progress) const;

public:
    ProgressiveModifier(LedColor const& start, LedColor const& finish);

    virtual double getProgress() const = 0;

    void onUpdate(LedsStrip& strip, uint16_t start, uint16_t finish) override;

    virtual ~ProgressiveModifier() = default;
};

} // namespace hardware

#endif // SRC_HARDWARE_LEDS_PROGRESSIVEMODIFIER_H
