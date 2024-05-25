#include "infinity_animation.h"

namespace spaceshooter {

InfinityAnimation::InfinityAnimation(Easing* easing, std::function<void(float)> callback,
                                     float lap_time, float offset)
    : Animation{easing, callback, lap_time, offset} {}

InfinityAnimation::~InfinityAnimation() {}

void InfinityAnimation::Tick(const float& delta_time) {
    elapsed_time_ += delta_time;
    float progress = elapsed_time_ / completion_time_ + offset_;
    callback_((*easing_)(progress));
}

} // namespace spaceshooter