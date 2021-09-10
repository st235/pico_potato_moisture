#include "./MoistureModifier.h"

namespace hardware {

MoistureModifier::MoistureModifier(MoistureSensor const* sensor, LedColor const& start, LedColor const& finish): ProgressiveModifier(start, finish), _sensor(sensor) {
    // empty on purpose
}

double MoistureModifier::getProgress() const {
    return _sensor->normalisedValue();
}

} // namespace hardware
