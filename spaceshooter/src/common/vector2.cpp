#include "vector2.h"

#include <cmath>

namespace spaceshooter {

Vector2 Vector2::Normalize() {
    float length = std::sqrtf(x * x + y * y);
    return {x / length, y / length};
}

Vector2 Vector2::operator+(const Vector2& other) { return Vector2{x + other.x, y + other.y}; }

Vector2 Vector2::operator*(const float& f) { return Vector2{x * f, y * f}; }

Vector2& Vector2::operator+=(const Vector2& other) {
    x += other.x;
    y += other.y;
    return *this;
}

} // namespace spaceshooter