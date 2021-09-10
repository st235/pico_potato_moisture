#include "LedColor.h"

#include "../../utils/MathUtils.h"

namespace hardware {

LedColor LedColor::BLACK = LedColor(0x00, 0x00, 0x00);
LedColor LedColor::RED = LedColor(0xFF, 0x00, 0x00);
LedColor LedColor::GREEN = LedColor(0x00, 0xFF, 0x00);
LedColor LedColor::BLUE = LedColor(0x00, 0x00, 0xFF);
LedColor LedColor::SILVER = LedColor(0xC0, 0xC0, 0xC0);
LedColor LedColor::GRAY = LedColor(0x80, 0x80, 0x80);
LedColor LedColor::YELLOW = LedColor(0xFF, 0xFF, 0x00);
LedColor LedColor::OLIVE = LedColor(0x80, 0x80, 0x00);
LedColor LedColor::AQUA = LedColor(0x00, 0xFF, 0xFF);
LedColor LedColor::TEAL = LedColor(0x00, 0x80, 0x80);
LedColor LedColor::FUCHSIA = LedColor(0xFF, 0x00, 0xFF);
LedColor LedColor::PURPLE = LedColor(0x80, 0x00, 0x80);
LedColor LedColor::ORANGE = LedColor(0xFF, 0xA5, 0x00);
LedColor LedColor::CORAL = LedColor(0xFF, 0x7F, 0x50);
LedColor LedColor::TOMATO = LedColor(0xFF, 0x63, 0x47);
LedColor LedColor::WHITE = LedColor(0xFF, 0xFF, 0xFF);

LedColor::LedColor(uint8_t red, uint8_t green, uint8_t blue): _red(red), _green(green), _blue(blue) {
    // empty on purpose;
}

LedColor::LedColor(LedColor const& color) {
    if (this != &color) {
        _red = color._red;
        _green = color._green;
        _blue = color._blue;
    }
}
LedColor LedColor::operator=(LedColor const& color) {
    if (this == &color) {
        return *this;
    }

    _red = color._red;
    _green = color._green;
    _blue = color._blue;
    return *this;
}

LedColor::operator uint32_t() const {
    return  ((uint32_t) (_red) << 8) | ((uint32_t) (_green) << 16) | (uint32_t) (_blue);
}

LedColor LedColor::withBrigthness(float brightness) {
    return LedColor(
        (uint8_t) (((float) _red) * brightness),
        (uint8_t) (((float) _green) * brightness),
        (uint8_t) (((float) _blue) * brightness)
    );
}

LedColor LedColor::Lerp(LedColor const& a, LedColor const& b, float fraction) {
    return LedColor(
        (uint8_t) utils::lerp((float) a._red, (float) b._red, fraction),
        (uint8_t) utils::lerp((float) a._green, (float) b._green, fraction),
        (uint8_t) utils::lerp((float) a._blue, (float) b._blue, fraction)
    );
}

LedColor LedColor::FromRGB(uint8_t red, uint8_t green, uint8_t blue) {
    return LedColor(red, green, blue);
}

LedColor LedColor::FromRGB(uint8_t brightness, uint8_t red, uint8_t green, uint8_t blue) {
    // brigthness is ignored on purpose
    return LedColor(red, green, blue);
}

}
