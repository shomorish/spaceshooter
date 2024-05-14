#pragma once

#include "../common/vector2.h"
#include "actor.h"

namespace spaceshooter {

class Character : public Actor {
 public:
    Character(Vector2 pos, Vector2 size, Vector2 direction, SDL_Texture* texture);

    virtual ~Character();

 protected:
    Vector2 pos_;
    Vector2 size_;
    Vector2 direction_;
    SDL_Texture* texture_;
};
} // namespace spaceshooter
