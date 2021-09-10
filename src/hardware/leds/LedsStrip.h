#ifndef SRC_HARDWARE_LEDS_LEDSSTRIP_H
#define SRC_HARDWARE_LEDS_LEDSSTRIP_H

#include <cstdint>
#include <vector>

#include "./LedColor.h"
#include "./modifiers/LightModifier.h"

namespace hardware {

class LedsStrip {
private:
    uint8_t const _pin;
    uint16_t const _stripe_size;

    bool* _enabled;
    uint32_t* _colors;

    std::vector<LightModifier*> _modifiers;
    std::vector<uint32_t> _modifiers_interval;

    bool checkInterval(uint16_t starting_led, uint16_t finished_led) const;

    bool checkIndex(uint16_t led) const;

public:
    LedsStrip(uint8_t pin, uint16_t stripe_size);

    LedsStrip(LedsStrip const& strip) = delete;
    LedsStrip operator=(LedsStrip const& strip) = delete;

    void setEnabled(uint16_t led, bool enabled);
    void setColor(uint16_t led, LedColor const& color);

    void addModifier(LightModifier* modifier,
                     uint16_t starting_led);

    void addModifier(LightModifier* modifier,
                     uint16_t starting_led,
                     uint16_t finished_led);

    void update();

    void clear();

    uint16_t size() const;

    ~LedsStrip();
};

} // namespace hardware

#endif // SRC_HARDWARE_LEDS_LEDSSTRIP_H
