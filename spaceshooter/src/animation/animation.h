#pragma once

#include <functional>

#include "easing.h"

namespace spaceshooter {

class Animation {

 public:
    Animation(Easing* easing, std::function<void(float)> callback, float completion_time = 1.f,
              float offset = 0.f);

    virtual ~Animation();

    virtual void Tick(const float& delta_time) = 0;

 protected:
    Easing* easing_;
    std::function<void(float)> callback_;
    float completion_time_;
    float elapsed_time_;
    float offset_;
};

} // namespace spaceshooter
