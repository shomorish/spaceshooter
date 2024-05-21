#pragma once

#include "../common/range.h"
#include "../common/vector2.h"
#include "../window.h"

namespace spaceshooter {

class Camera {
 public:
    Camera();

    ~Camera();

    Vector2 get_pos() const;
    void set_pos(Vector2 pos);

    void Init(Range area_x_range, Range area_y_range, Window* window);
    bool ConvertToWindowCoords(Vector2 pos, Vector2* out);

 private:
    Vector2 pos_;
    Range x_range_;
    Range y_range_;
    float half_window_width_;
    float half_window_height_;
};

} // namespace spaceshooter
