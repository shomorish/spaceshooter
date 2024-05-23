#include "infinity_animation.h"

#include <SDL.h>
#include <cmath>

namespace spaceshooter {

InfinityAnimation::InfinityAnimation(Easing* easing, std::function<void(float)> callback)
    : easing_(easing), callback_(callback), value_(0.f) {}

InfinityAnimation::~InfinityAnimation() {
    if (easing_) {
        delete easing_;
        easing_ = NULL;
    }
    callback_ = NULL;
}

void InfinityAnimation::Tick(const float& delta_time) {
    value_ += delta_time;
    callback_(std::sinf(value_ * (float)M_PI / 2.f));
}

} // namespace spaceshooter