#include "camera.h"

namespace spaceshooter {

Camera::Camera() : pos_(Vector2::zero), x_range_(Range{0.f, 0.f}), y_range_(Range{0.f, 0.f}) {}

Camera::~Camera() {}

Vector2 Camera::get_pos() { return pos_; }

float Clamp(float current, float min, float max) {
    if (current < min) {
        current = min;
    } else if (current > max) {
        current = max;
    }
    return current;
}

void Camera::set_pos(Vector2 pos) {
    pos.x = Clamp(pos.x, x_range_.min, x_range_.max);
    pos.y = Clamp(pos.y, y_range_.min, y_range_.max);
    pos_ = pos;
}

void Camera::Init(Range x_range, Range y_range) {
    x_range_ = x_range;
    y_range_ = y_range;
}

} // namespace spaceshooter