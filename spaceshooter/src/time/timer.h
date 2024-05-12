#pragma once

#include <chrono>

namespace spaceshooter {

class Timer {
 private:
    std::chrono::high_resolution_clock::time_point before_;
    float delta_time_;

 public:
    Timer();
    ~Timer();

    float get_delta_time();

    void UpdateTime();
};

} // namespace spaceshooter
