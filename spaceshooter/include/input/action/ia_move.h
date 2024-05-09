#pragma once

#include "base/vector2_input_action.h"

namespace spaceshooter {

class IA_Move : public Vector2InputAction {
 public:
    IA_Move(Vector2 value);
    ~IA_Move();
};

} // namespace spaceshooter
