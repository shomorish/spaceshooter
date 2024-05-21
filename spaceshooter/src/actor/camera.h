#pragma once

#include "../common/vector2.h"
#include "../common/range.h"

namespace spaceshooter {

class Camera {
 public:
    Camera();

    ~Camera();

    Vector2 get_pos();
    void set_pos(Vector2 pos);

    void Init(Range x_range, Range y_range);

 private:
    Vector2 pos_;
    Range x_range_;
    Range y_range_;
};

} // namespace spaceshooter
