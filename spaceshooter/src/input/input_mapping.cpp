#include "../../include/input/input_mapping.h"

namespace spaceshooter {

InputMapping::InputMapping() : keyboard_state_array_(NULL) {
    keyboard_state_array_ = SDL_GetKeyboardState(NULL);
}

InputMapping::~InputMapping() {
    if (keyboard_state_array_ != NULL) {
        keyboard_state_array_ = NULL;
    }
    Clear();
}

std::set<InputAction*> InputMapping::get_actions() { return actions_; }

void InputMapping::Clear() {
    for (auto iter = actions_.begin(); iter != actions_.end(); iter++) {
        delete *iter;
    }
    actions_.clear();
}

} // namespace spaceshooter