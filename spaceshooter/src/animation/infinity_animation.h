#pragma once

#include "animation.h"

namespace spaceshooter {

class InfinityAnimation : public Animation {
 public:
    InfinityAnimation(Easing* easing, std::function<void(float)> callback, float lap_time);

    ~InfinityAnimation();

    void Tick(const float& delta_time) override;
};

} // namespace spaceshooter
