#pragma once

#include <vector>

#include "../input/input_action.h"
#include "../input/input_action_container.h"
#include "../level/level.h"
#include "actor.h"
#include "character.h"

namespace spaceshooter {

class Character;

class Controller : public Actor {
 public:
    Controller(Level* level);

    virtual ~Controller();

    Character* get_character();

    virtual void Tick(const InputActionContainer* action_container, const float& delta_time);
    Character** GetCharacterRef();
    virtual void DestroyCharacter();

 protected:
    Level* level_;
    Character* character_;
};

} // namespace spaceshooter
