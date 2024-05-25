#include "finite_animation.h"

namespace spaceshooter {

FiniteAnimation::FiniteAnimation(Easing* easing, std::function<void(float)> callback,
                                 float completion_time)
    : Animation{easing, callback, completion_time} {}

FiniteAnimation::~FiniteAnimation() {}

void FiniteAnimation::Tick(const float& delta_time) {
    elapsed_time_ += delta_time;
    if (completion_time_ < elapsed_time_) elapsed_time_ = completion_time_;
    float progress = elapsed_time_ / completion_time_;
    callback_((*easing_)(progress));
}

} // namespace spaceshooter