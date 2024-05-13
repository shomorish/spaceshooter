#pragma once

namespace spaceshooter {

struct Vector2 {
    float x;
    float y;

    static Vector2 zero;
    static Vector2 up;
    static Vector2 down;

    Vector2 Normalize();

    Vector2 operator+(const Vector2& other);
    Vector2 operator*(const float& f);
    Vector2 operator/(const float& f);
    Vector2& operator+=(const Vector2& other);
};

} // namespace spaceshooter
