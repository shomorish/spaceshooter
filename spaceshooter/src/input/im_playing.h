#pragma once

#include "input_mapping.h"

namespace spaceshooter {

class IM_Playing : public InputMapping {
 public:
    std::vector<InputAction> GenerateInputAction() override;
};

} // namespace spaceshooter
