#pragma once

#include "../common/vector2.h"

namespace spaceshooter {

class Camera {
 public:
    Camera();

    ~Camera();

    Vector2 get_pos();
    void set_pos(Vector2 pos);

 private:
    Vector2 pos_;
};

} // namespace spaceshooter
