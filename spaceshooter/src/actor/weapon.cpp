#include "weapon.h"

namespace spaceshooter {

Weapon::Weapon(Vector2 pos, float firing_interval, float interval_count)
    : pos_(pos), firing_interval_(firing_interval), interval_count_(interval_count) {}

Weapon::~Weapon() {}

Vector2 Weapon::get_pos() { return pos_; }

void Weapon::set_pos(Vector2 pos) { pos_ = pos; }

bool Weapon::CanFire() { return interval_count_ <= 0.f; }

void Weapon::CountdownInterval(float delta_time) { interval_count_ -= delta_time; }

} // namespace spaceshooter