#include "./SystemTimer.h"

#include "pico/time.h"

namespace hardware {

SystemTimer::SystemTimer(int8_t timezone, uint64_t build_time): _timezone(timezone), _build_time(build_time) {
    // empty on purpose
}

uint64_t SystemTimer::getCurrentTimestamp() {
    int32_t offset_sec = _timezone * 3600;
    uint64_t timestamp_since_launch = to_us_since_boot(get_absolute_time()) / 1000000;
    return timestamp_since_launch + offset_sec + _build_time;
}

uint8_t SystemTimer::getHours() {
    return (this->getCurrentTimestamp() / 3600) % 24;
}

uint8_t SystemTimer::getMinutes() {
    return (this->getCurrentTimestamp() / 60) % 60;
}

uint8_t SystemTimer::getSeconds() {
    return (this->getCurrentTimestamp()) % 60;
}

} // namespace hardware
