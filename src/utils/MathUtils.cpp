#include "./MathUtils.h"

namespace utils {

uint32_t min(uint32_t a, uint32_t b) {
    if (a < b) {
        return a;
    }

    return b;
}

uint32_t max(uint32_t a, uint32_t b) {
    if (a > b) {
        return a;
    }

    return b;
}

uint32_t clamp(uint32_t value, uint32_t min_value, uint32_t max_value) {
    return max(min(value, max_value), min_value);
}

} // namespace utils
