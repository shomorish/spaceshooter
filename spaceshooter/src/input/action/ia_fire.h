#pragma once

#include "bool_input_action.h"

namespace spaceshooter {

class IA_Fire : public BoolInputAction {
 public:
    IA_Fire(bool value);
    ~IA_Fire();
};

} // namespace spaceshooter
