#include "animation.h"

#include <cassert>

namespace spaceshooter {

Animation::Animation(Easing* easing, std::function<void(float)> callback, float completion_time,
                     float offset)
    : easing_(easing), callback_(callback), completion_time_(completion_time), elapsed_time_(0.f),
      offset_(offset) {

    assert(easing_ != NULL);
    assert(callback_ != NULL);
    assert(completion_time_ > 0.f);
}

Animation::~Animation() {
    if (easing_) {
        delete easing_;
        easing_ = NULL;
    }

    callback_ = NULL;
}

} // namespace spaceshooter