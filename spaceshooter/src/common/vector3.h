#pragma once

#include "vector2.h"

namespace spaceshooter {

struct Vector3 {
    float x, y, z;

    Vector3 Cross(const Vector3& v);
    Vector3 Normalize();
};

} // namespace spaceshooter
