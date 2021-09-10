#ifndef SRC_HARDWARE_MOISTURE_MOISTUREMODIFIER_H
#define SRC_HARDWARE_MOISTURE_MOISTUREMODIFIER_H

#include <cstdint>

#include "../leds/modifiers/ProgressiveModifier.h"
#include "./MoistureSensor.h"

namespace hardware {

class LedsStrip;

class MoistureModifier: public ProgressiveModifier {
private:
    MoistureSensor const* const _sensor;

public:
    MoistureModifier(MoistureSensor const* sensor, LedColor const& start, LedColor const& finish);

    double getProgress() const override;

    ~MoistureModifier() = default;
};

}

#endif // SRC_HARDWARE_MOISTURE_MOISTUREMODIFIER_H
