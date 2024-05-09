#include "../../../include/input/action/ia_move.h"

namespace spaceshooter {

IA_Move::IA_Move(Vector2 value) : Vector2InputAction(value) {}

IA_Move::~IA_Move() { value_ = Vector2{0.f, 0.f}; }

} // namespace spaceshooter