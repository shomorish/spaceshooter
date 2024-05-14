#include "vector3.h"

#include <cmath>

namespace spaceshooter {

Vector3 Vector3::Cross(const Vector3& v) {
    return Vector3{y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x};
}

Vector3 Vector3::Normalize() {
    float length = std::sqrtf(x * x + y * y + z * z);
    return Vector3{x / length, y / length, z / length};
}

} // namespace spaceshooter