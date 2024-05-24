#include "im_menu.h"

namespace spaceshooter {

const InputActionContainer& IM_Menu::GenerateInputAction() {
    if (key_state_[SDL_SCANCODE_UP] == 1) {
        auto action = new InputAction();
        action->type = InputActionType::kGoUp;
        action_container_.Add(action);
    }

    if (key_state_[SDL_SCANCODE_DOWN] == 1) {
        auto action = new InputAction();
        action->type = InputActionType::kGoDown;
        action_container_.Add(action);
    }

    if (key_state_[SDL_SCANCODE_RETURN] == 1) {
        auto action = new InputAction();
        action->type = InputActionType::kDecision;
        action_container_.Add(action);
    }

    return action_container_;
}

} // namespace spaceshooter