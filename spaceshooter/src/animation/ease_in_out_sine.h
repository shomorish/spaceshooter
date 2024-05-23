#pragma once

#include "easing.h"

namespace spaceshooter {

class EaseInOutSine : public Easing {
 public:
    float operator()(float x) override;
};

} // namespace spaceshooter
