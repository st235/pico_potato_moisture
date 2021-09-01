#ifndef SRC_HARDWARE_MOISTURE_MOISTURESENSOR_H
#define SRC_HARDWARE_MOISTURE_MOISTURESENSOR_H

#include <cstdint>

namespace hardware {

class MoistureSensor {
private:
    uint8_t const _pin; 

    uint32_t const _min_current;
    uint32_t const _max_current;

public:
    MoistureSensor(uint8_t pin,
                   uint32_t min_current,
                   uint32_t max_current);

    double normalisedValue() const;

    // type is quite primitive to have default overrides for copy & destructor
    MoistureSensor(MoistureSensor const& sensor) = default;
    MoistureSensor& operator=(MoistureSensor const& sensor) = default;

    ~MoistureSensor() = default;
};

}

#endif // SRC_HARDWARE_MOISTURE_MOISTURESENSOR_H
