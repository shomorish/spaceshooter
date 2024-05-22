#pragma once

#include <vector>

#include "../input/input_action.h"
#include "actor.h"
#include "character.h"

namespace spaceshooter {

class Character;

class Controller : public Actor {
 public:
    Controller();

    virtual ~Controller();

    Character* get_character();

    virtual void Tick(const std::vector<InputAction>& actions, const float& delta_time) = 0;
    Character** GetCharacterRef();
    virtual void DestroyCharacter();

 protected:
    Character* character_;
};

} // namespace spaceshooter
