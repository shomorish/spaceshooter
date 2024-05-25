#pragma once

#include <functional>

#include "animation.h"

namespace spaceshooter {

using OnCompleteListener = std::function<void(void)>;

class FiniteAnimation : public Animation {
 public:
    FiniteAnimation(Easing* easing, std::function<void(float)> callback,
                    float completion_time = 1.f, float offset = 0.f);

    ~FiniteAnimation();

    void Tick(const float& delta_time) override;
    void RegistOnCompleteListener(OnCompleteListener listener);
    void UnregistOnCompleteListener();

 private:
    OnCompleteListener on_complete_listener_;
};

} // namespace spaceshooter
