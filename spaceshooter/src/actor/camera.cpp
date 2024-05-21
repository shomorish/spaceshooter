#include "camera.h"

namespace spaceshooter {

Camera::Camera() : pos_(Vector2::zero) {}

Camera::~Camera() {}

Vector2 Camera::get_pos() { return pos_; }

void Camera::set_pos(Vector2 pos) { pos_ = pos; }

} // namespace spaceshooter