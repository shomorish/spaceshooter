#include "../../include/time/timer.h"

namespace spaceshooter {

Timer::Timer() {
    before_ = std::chrono::high_resolution_clock::now();
    delta_time_ = 0.f;
}

Timer::~Timer() {}

float Timer::get_delta_time() { return delta_time_; }

void Timer::UpdateTime() {
    auto current = std::chrono::high_resolution_clock::now();
    auto delta = std::chrono::duration<float, std::milli>(current - before_);
    delta_time_ = delta.count() / 1000.f;
    before_ = current;
}

} // namespace spaceshooter
