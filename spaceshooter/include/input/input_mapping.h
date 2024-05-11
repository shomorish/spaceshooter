#pragma once

#include <SDL.h>
#include <vector>

#include "action/base/input_action.h"

namespace spaceshooter {

static const int kKeyNum = 512;

class InputMapping {
 protected:
    Uint8 key_state_[kKeyNum];
    std::vector<InputAction*> actions_;

 public:
    InputMapping();
    virtual ~InputMapping();

    void HandleInputEvent(const SDL_Event& event);
    void UpdateInputState();
    void ClearInputActions();

    virtual std::vector<InputAction*> GenerateInputAction() = 0;
};

} // namespace spaceshooter
