#include "../../include/common/vector2.h"

#include <cmath>

namespace spaceshooter {

Vector2 Vector2::Normalize() {
    float length = std::sqrtf(x * x + y * y);
    return {x / length, y / length};
}

} // namespace spaceshooter