#include "camera.h"

#include <cfloat>
#include <stdio.h>

namespace spaceshooter {

Camera::Camera()
    : pos_(Vector2::zero), x_range_(Range{0.f, 0.f}), y_range_(Range{0.f, 0.f}),
      half_window_width_(0.f), half_window_height_(0.f) {}

Camera::~Camera() {}

Vector2 Camera::get_pos() const { return pos_; }

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

void Camera::Init(Range area_x_range, Range area_y_range, Window* window) {
    half_window_width_ = window->get_width() / 2.f;
    half_window_height_ = window->get_height() / 2.f;
    x_range_ = Range{area_x_range.min + half_window_width_, area_x_range.max - half_window_width_};
    y_range_ =
        Range{area_y_range.min + half_window_height_, area_y_range.max - half_window_height_};
}

bool Camera::ConvertToWindowCoords(Vector2 pos, Vector2* out) {
    // if (!(x_range_.withinRange(pos.x) && y_range_.withinRange(pos.y))) {
    // if (!((0 <= pos.x && pos.x <= 1600.f) && (0 <= pos.y && pos.y <= 1600.f))) {
    //    *out = Vector2{FLT_MIN, FLT_MIN};
    //    return false;
    //}

    Vector2 rel = pos - pos_;
    Vector2 half_window_size{half_window_width_, half_window_height_};
    *out = half_window_size + rel;
    return true;
}

} // namespace spaceshooter