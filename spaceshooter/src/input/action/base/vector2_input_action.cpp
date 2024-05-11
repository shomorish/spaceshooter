#include "../../../../include/input/action/base/vector2_input_action.h"

namespace spaceshooter {

Vector2InputAction::Vector2InputAction(Vector2 value) : value_(value) {}

Vector2InputAction::~Vector2InputAction() {}

Vector2 Vector2InputAction::get_value() { return value_; }

} // namespace spaceshooter