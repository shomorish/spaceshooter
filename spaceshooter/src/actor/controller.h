#pragma once

#include <vector>

#include "../input/input_action.h"
#include "actor.h"
#include "character.h"

namespace spaceshooter {

class Controller : public Actor {
 public:
    Controller();

    virtual ~Controller();

    Character* get_character();

    virtual void Tick(const std::vector<InputAction>& actions, const float& delta_time) = 0;
    Character** GetCharacterRef();

 protected:
    Character* character_;
};

} // namespace spaceshooter
