#include "input_action_container.h"

namespace spaceshooter {

InputActionContainer::InputActionContainer() {
    actions_ = new InputAction* [InputActionType::kTypeNum] { 0 };
}

InputActionContainer::~InputActionContainer() {
    Clear();
    delete[] actions_;
    actions_ = 0;
}

const InputAction* InputActionContainer::GetActionOrNull(InputActionType type) const {
    return type == InputActionType::kTypeNum ? 0 : actions_[type];
}

void InputActionContainer::Add(InputAction* action) { actions_[action->type] = action; }

void InputActionContainer::Clear() {
    for (int i = 0; i < InputActionType::kTypeNum; i++) {
        if (actions_[i]) {
            delete actions_[i];
            actions_[i] = 0;
        }
    }
}

} // namespace spaceshooter