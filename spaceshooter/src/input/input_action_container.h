#pragma once

#include "input_action.h"

namespace spaceshooter {

class InputActionContainer {
 public:
    InputActionContainer();

    ~InputActionContainer();

    const InputAction* GetActionOrNull(InputActionType type) const;
    void Add(InputAction* action);
    void Clear();

 private:
    InputAction** actions_;
};

} // namespace spaceshooter
