#include "alien.h"

namespace spaceshooter {

Alien::Alien(Texture* texture, Vector2 pos, Vector2 size = Vector2{64.f, 64.f}, float speed = 60.f,
             Vector2 direction, float rotation_speed = 120.f, float hp = 25.f)
    : Character{pos, size, direction, texture->sdl()}, speed_(speed),
      rotation_speed_(rotation_speed), hp_(hp) {}

Alien::~Alien() { texture_ = NULL; }

float Alien::get_speed() { return speed_; }

float Alien::get_rotation_speed() { return rotation_speed_; }

} // namespace spaceshooter