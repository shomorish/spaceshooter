#include "ease_in_out_sine.h"

#include <SDL.h>
#include <cmath>

namespace spaceshooter {

float EaseInOutSine::operator()(float x) { return -(std::cosf((float)M_PI * x) - 1) / 2.f; }

} // namespace spaceshooter