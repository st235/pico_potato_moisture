#ifndef SRC_HARDWARE_LEDS_LEDCOLOR_H
#define SRC_HARDWARE_LEDS_LEDCOLOR_H

#include <stdint.h>

namespace hardware {

class LedColor {
private:
    uint8_t _red;
    uint8_t _green;
    uint8_t _blue;

    LedColor(uint8_t red, uint8_t green, uint8_t blue);

public:
    static LedColor BLACK;
    static LedColor RED;
    static LedColor GREEN;
    static LedColor BLUE;
    static LedColor YELLOW;
    static LedColor ORANGE;
    static LedColor CORAL;
    static LedColor TOMATO;
    static LedColor SILVER;
    static LedColor GRAY;
    static LedColor OLIVE;
    static LedColor AQUA;
    static LedColor TEAL;
    static LedColor FUCHSIA;
    static LedColor PURPLE;
    static LedColor WHITE;

    LedColor(LedColor const& color);
    LedColor operator=(LedColor const& color);

    operator uint32_t() const;

    LedColor withBrigthness(float brightness);

    static LedColor Lerp(LedColor const& a, LedColor const& b, float fraction);

    static LedColor FromRGB(uint8_t red, uint8_t green, uint8_t blue);
    static LedColor FromRGB(uint8_t brightness, uint8_t red, uint8_t green, uint8_t blue);

    ~LedColor() = default;
};

} // namespace hardware

#endif // SRC_HARDWARE_LEDS_LEDCOLOR_H
