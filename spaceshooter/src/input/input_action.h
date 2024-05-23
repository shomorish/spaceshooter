#pragma once

#include "../common/vector2.h"

namespace spaceshooter {

enum InputActionType { kMove, kRotate, kFire, kGoUp, kGoDown, kDecision };

struct InputAction {
    InputActionType type;

    union {
        Vector2 vec2_value;
        bool b_value;
    };
};

} // namespace spaceshooter
