#include "bullet.h"

namespace spaceshooter {

Bullet::Bullet()
    : Actor{Vector2::zero, Vector2::zero}, direction_(Vector2::zero), speed_(0.f), lifetime_(0.f),
      is_alive_(false), owner_type_(BulletOwnerType::kUnknown) {}

Bullet::Bullet(Vector2 pos, Vector2 size, Vector2 direction, float speed, float lifetime,
               bool is_alive, BulletOwnerType owner_type)
    : Actor{pos, size}, direction_(direction), speed_(speed), lifetime_(lifetime),
      is_alive_(is_alive), owner_type_(owner_type) {
    collider_ = new Collider(pos, size.x / 2.f, this);
}

Bullet::~Bullet() {}

bool Bullet::get_is_alive() { return is_alive_; }

void Bullet::set_is_alive(bool is_alive) { is_alive_ = is_alive; }

} // namespace spaceshooter