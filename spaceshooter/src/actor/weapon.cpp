#include "weapon.h"

namespace spaceshooter {

Weapon::Weapon(Vector2 pos, Vector2 direction, float firing_interval, float interval_count)
    : pos_(pos), direction_(direction), firing_interval_(firing_interval),
      interval_count_(interval_count) {}

Weapon::~Weapon() {}

Vector2 Weapon::get_pos() { return pos_; }

void Weapon::set_pos(Vector2 pos) { pos_ = pos; }

Vector2 Weapon::get_direction() { return direction_; }

void Weapon::set_direction(Vector2 direction) { direction_ = direction; }

bool Weapon::CanFire() { return interval_count_ <= 0.f; }

void Weapon::CountdownInterval(float delta_time) { interval_count_ -= delta_time; }

} // namespace spaceshooter