#ifndef SRC_UTILS_MATHUTILS_H
#define SRC_UTILS_MATHUTILS_H

#include <cstdint>

namespace utils {

uint32_t min(uint32_t a, uint32_t b);

uint32_t max(uint32_t a, uint32_t b);

uint32_t clamp(uint32_t value, uint32_t min_value, uint32_t max_value);

} // namespace utils

#endif // SRC_UTILS_MATHUTILS_H
