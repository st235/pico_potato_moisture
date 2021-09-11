#ifndef SRC_HARDWARE_TIMER_SYSTEMTIMER_H
#define SRC_HARDWARE_TIMER_SYSTEMTIMER_H

#include <stdint.h>

namespace hardware {

class SystemTimer {
private:
    int8_t _timezone;
    uint64_t _build_time;

    uint64_t getCurrentTimestamp();

public:
    SystemTimer(int8_t timezone, uint64_t build_time);

    uint8_t getHours();
    uint8_t getMinutes();
    uint8_t getSeconds();

    ~SystemTimer() = default;

};

} // namespace hardware

#endif // SRC_HARDWARE_TIMER_SYSTEMTIMER_H
