#include "finite_animation.h"

namespace spaceshooter {

FiniteAnimation::FiniteAnimation(Easing* easing, std::function<void(float)> callback,
                                 float completion_time, float offset)
    : Animation{easing, callback, completion_time, offset} {}

FiniteAnimation::~FiniteAnimation() {}

void FiniteAnimation::Tick(const float& delta_time) {
    elapsed_time_ += delta_time;
    if (completion_time_ < elapsed_time_) {
        elapsed_time_ = completion_time_;
        if (on_complete_listener_) {
            on_complete_listener_();
        }
    }
    float progress = elapsed_time_ / completion_time_ + offset_;
    callback_((*easing_)(progress));
}

void FiniteAnimation::RegistOnCompleteListener(OnCompleteListener listener) {
    on_complete_listener_ = listener;
}

void FiniteAnimation::UnregistOnCompleteListener() { on_complete_listener_ = NULL; }

} // namespace spaceshooter