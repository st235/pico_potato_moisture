#include "MoistureSensor.h"

#include "hardware/adc.h"

#include "../../utils/MathUtils.h"

namespace {

/**
 * GP26 - ADC0
 * GP27 - ADC1
 * GP28 - ADC2
 */
inline uint8_t GetAdxFromGp(uint8_t pin) {
    switch (pin) {
        case 26: return 0;
        case 27: return 1;
        case 28: return 2;
        default: return 0;
    }
}

} // namespace

namespace hardware {

MoistureSensor::MoistureSensor(uint8_t pin,
                               uint32_t min_current,
                               uint32_t max_current): _pin(pin), _min_current(min_current), _max_current(max_current) {
	adc_gpio_init(pin);
}

double MoistureSensor::normalisedValue() const {
    adc_select_input(GetAdxFromGp(_pin));
    uint32_t raw_value = adc_read();

    uint32_t interval_length = _max_current - _min_current;
    uint32_t clamped_value = utils::clamp(raw_value, _min_current, _max_current);
    uint32_t unbiased_value = clamped_value - _min_current;

    /**
     * we need to inverse value here as max current means less moisture
     * and is supposed to mean open air
     */
    return 1.0 - ((double) unbiased_value) / ((double) interval_length);
}

} // namespace hardware
