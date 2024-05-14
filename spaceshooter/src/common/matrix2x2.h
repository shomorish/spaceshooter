#pragma once

#include "vector2.h"

namespace spaceshooter {

class Matrix2x2 {
 public:
    Matrix2x2(float a, float b, float c, float d);

    ~Matrix2x2();

    Vector2 operator*(const Vector2& v);

 private:
    float a_, b_, c_, d_;
};

} // namespace spaceshooter
