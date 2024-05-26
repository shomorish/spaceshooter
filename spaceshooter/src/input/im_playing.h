#pragma once

#include "input_mapping.h"

namespace spaceshooter {

class IM_Playing : public InputMapping {
 public:
    void GenerateInputAction(InputActionContainer* action_container) override;
};

} // namespace spaceshooter
