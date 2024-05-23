#pragma once

#include <functional>

#include "easing.h"

namespace spaceshooter {

class InfinityAnimation {
 public:
    InfinityAnimation(Easing* easing, std::function<void(float)> callback);

    ~InfinityAnimation();

    void Tick(const float& delta_time);

 private:
    Easing* easing_;
    std::function<void(float)> callback_;
    float value_;
};

} // namespace spaceshooter
