#include "alien.h"

namespace spaceshooter {

Alien::Alien(Texture* texture, Vector2 pos, Vector2 size, float speed, Vector2 direction,
             float rotation_speed, float hp)
    : Character{pos, size, direction, texture->sdl()}, speed_(speed),
      rotation_speed_(rotation_speed), hp_(hp) {}

Alien::~Alien() { texture_ = NULL; }

float Alien::get_speed() { return speed_; }

float Alien::get_rotation_speed() { return rotation_speed_; }

} // namespace spaceshooter