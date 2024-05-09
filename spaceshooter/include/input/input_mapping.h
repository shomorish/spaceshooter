#pragma once

#include <SDL.h>
#include <set>
#include <stack>

#include "action/base/input_action.h"

namespace spaceshooter {

class InputMapping {
 protected:
    const Uint8* keyboard_state_array_;
    std::set<InputAction*> actions_;

 public:
    InputMapping();
    ~InputMapping();

    std::set<InputAction*> get_actions();

    void Clear();

    virtual void HandleKeyboardState() = 0;
};

} // namespace spaceshooter
