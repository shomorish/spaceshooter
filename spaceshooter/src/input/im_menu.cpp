#include "im_menu.h"

namespace spaceshooter {

std::vector<InputAction> IM_Menu::GenerateInputAction() {
    std::vector<InputAction> actions;

    if (key_state_[SDL_SCANCODE_UP] == 1) {
        auto action = InputAction();
        action.type = InputActionType::kGoUp;
        actions.push_back(action);
    }

    if (key_state_[SDL_SCANCODE_DOWN] == 1) {
        auto action = InputAction();
        action.type = InputActionType::kGoDown;
        actions.push_back(action);
    }

    if (key_state_[SDL_SCANCODE_RETURN] == 1) {
        auto action = InputAction();
        action.type = InputActionType::kDecision;
        actions.push_back(action);
    }

    return actions;
}

} // namespace spaceshooter