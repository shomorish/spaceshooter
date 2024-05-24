#pragma once

#include "input_mapping.h"

namespace spaceshooter {

class IM_Playing : public InputMapping {
 public:
    const InputActionContainer& GenerateInputAction() override;
};

} // namespace spaceshooter
