#pragma once

#include <SDL.h>
#include <vector>

#include "input_action.h"
#include "input_action_container.h"

namespace spaceshooter {

static const int kKeyNum = 512;
static const int kMouseButtonNum = 4;

class InputMapping {
 public:
    InputMapping();
    virtual ~InputMapping();

    void HandleInputEvent(const SDL_Event& event);
    void UpdateInputState();
    void ClearInputActions();

    virtual const InputActionContainer& GenerateInputAction() = 0;

 protected:
    Uint8 key_state_[kKeyNum];
    Uint8 mouse_button_state_[kMouseButtonNum];
    InputActionContainer action_container_;
};

} // namespace spaceshooter
