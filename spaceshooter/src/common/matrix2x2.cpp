#include "matrix2x2.h"

namespace spaceshooter {

Matrix2x2::Matrix2x2(float a, float b, float c, float d) : a_(a), b_(b), c_(c), d_(d) {}

Matrix2x2::~Matrix2x2() {}

Vector2 Matrix2x2::operator*(const Vector2& v) {
    return Vector2{a_ * v.x + b_ * v.y, c_ * v.x + d_ * v.y};
}

} // namespace spaceshooter