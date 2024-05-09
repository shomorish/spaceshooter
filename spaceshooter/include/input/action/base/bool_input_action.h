#pragma once

#include "input_action.h"

namespace spaceshooter {

class BoolInputAction : public InputAction {
 protected:
    bool value_;

 public:
    BoolInputAction(bool value);
    bool get_value();
};

} // namespace spaceshooter
