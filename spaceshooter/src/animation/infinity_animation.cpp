#include "infinity_animation.h"

namespace spaceshooter {

InfinityAnimation::InfinityAnimation(Easing* easing, std::function<void(float)> callback,
                                     float lap_time)
    : Animation{easing, callback, lap_time} {}

InfinityAnimation::~InfinityAnimation() {}

void InfinityAnimation::Tick(const float& delta_time) {
    elapsed_time_ += delta_time;
    float progress = elapsed_time_ / completion_time_;
    callback_((*easing_)(progress));
}

} // namespace spaceshooter