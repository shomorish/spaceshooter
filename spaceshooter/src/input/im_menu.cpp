#include "im_menu.h"

namespace spaceshooter {

void IM_Menu::GenerateInputAction(InputActionContainer* action_container) {
    if (key_state_[SDL_SCANCODE_UP] == 1) {
        auto action = new InputAction();
        action->type = InputActionType::kGoUp;
        action_container->Add(action);
    }

    if (key_state_[SDL_SCANCODE_DOWN] == 1) {
        auto action = new InputAction();
        action->type = InputActionType::kGoDown;
        action_container->Add(action);
    }

    if (key_state_[SDL_SCANCODE_RETURN] == 1) {
        auto action = new InputAction();
        action->type = InputActionType::kDecision;
        action_container->Add(action);
    }
}

} // namespace spaceshooter