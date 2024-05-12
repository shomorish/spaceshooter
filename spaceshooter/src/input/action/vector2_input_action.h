#pragma once

#include "../../common/vector2.h"
#include "input_action.h"

namespace spaceshooter {

class Vector2InputAction : public InputAction {
 protected:
    Vector2 value_;

 public:
    Vector2InputAction(Vector2 value);
    virtual ~Vector2InputAction();
    Vector2 get_value();
};

} // namespace spaceshooter
