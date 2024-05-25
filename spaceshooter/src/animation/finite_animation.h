#pragma once

#include "animation.h"

namespace spaceshooter {

class FiniteAnimation : public Animation {
 public:
    FiniteAnimation(Easing* easing, std::function<void(float)> callback,
                    float completion_time = 1.f, float offset = 0.f);

    ~FiniteAnimation();

    void Tick(const float& delta_time) override;
};

} // namespace spaceshooter
