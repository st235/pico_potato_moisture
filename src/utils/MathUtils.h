#ifndef SRC_UTILS_MATHUTILS_H
#define SRC_UTILS_MATHUTILS_H

namespace utils {

template <class T>
T min(T a, T b) {
    if (a < b) {
        return a;
    }

    return b;
}

template <class T>
T max(T a, T b) {
    if (a > b) {
        return a;
    }

    return b;
}

template <class T>
T clamp(T value, T min_value, T max_value) {
    return max(min(value, max_value), min_value);
}

template <class T>
T lerp(T a, T b, T fraction) {
    return a + fraction * (b - a);
}

template <class T, class R>
R floor(T num) {
    return (R) num - 0.5;
}

template <class T, class R>
R ceiling(T num) {
    return (R) num + 0.5;
}

} // namespace utils

#endif // SRC_UTILS_MATHUTILS_H
