#include "vector2.h"

#include <cmath>

namespace spaceshooter {

Vector2 Vector2::zero = Vector2{0.f, 0.f};

Vector2 Vector2::up = Vector2{0.f, -1.f};

Vector2 Vector2::down = Vector2{0.f, 1.f};

float Vector2::Length() { return std::sqrtf(x * x + y * y); }

Vector2 Vector2::Normalize() {
    float length = Length();
    return {x / length, y / length};
}

float Vector2::Dot(const Vector2& other) { return x * other.x + y * other.y; }

Vector2 Vector2::operator+(const Vector2& other) { return Vector2{x + other.x, y + other.y}; }

Vector2 Vector2::operator+(const float& f) { return Vector2{x + f, y + f}; }

Vector2 Vector2::operator-(const Vector2& other) { return Vector2{x - other.x, y - other.y}; }

Vector2 Vector2::operator-(const float& f) { return Vector2{x - f, y - f}; }

Vector2 Vector2::operator*(const float& f) { return Vector2{x * f, y * f}; }

Vector2 Vector2::operator/(const float& f) { return Vector2{x / f, y / f}; }

Vector2& Vector2::operator+=(const Vector2& other) {
    x += other.x;
    y += other.y;
    return *this;
}

} // namespace spaceshooter