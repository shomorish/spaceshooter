#include "alien.h"

namespace spaceshooter {

Alien::Alien(Controller* owner, Texture* texture, Vector2 pos, Vector2 size, float speed,
             Vector2 direction, float rotation_speed, float hp)
    : Character{pos, size, direction, texture->sdl(), owner}, speed_(speed),
      rotation_speed_(rotation_speed), hp_(hp) {
    collider_ = new Collider(pos, size.x / 2.f, this);
}

Alien::~Alien() { texture_ = NULL; }

float Alien::get_speed() { return speed_; }

float Alien::get_rotation_speed() { return rotation_speed_; }

void Alien::ApplyDamage(float damage) {
    hp_ -= damage;
    if (hp_ <= 0.f) {
        owner_->DestroyCharacter();
    }
}

} // namespace spaceshooter