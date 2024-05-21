#pragma once

#include "../texture/texture.h"
#include "character.h"

namespace spaceshooter {

class Alien : public Character {
 public:
    Alien(Texture* texture, Vector2 pos, Vector2 size = Vector2{64.f, 64.f}, float speed = 60.f,
          Vector2 direction, float rotation_speed = 120.f, float hp = 25.f);
    ~Alien();

 private:
    float speed_;
    float rotation_speed_;
    float hp_;
};

} // namespace spaceshooter
