#pragma once

#include "input_mapping.h"

namespace spaceshooter {

class IM_Playing : public InputMapping {
 public:
    void HandleKeyboardState() override;
};

} // namespace spaceshooter
