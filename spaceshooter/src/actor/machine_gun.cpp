#include "machine_gun.h"

#include "straight_bullet.h"

namespace spaceshooter {

MachineGun::MachineGun(Vector2 pos, float firing_interval)
    : pos_(pos), firing_interval_(firing_interval), interval_count_(0.f) {}

MachineGun::~MachineGun() {}

Vector2 MachineGun::get_pos() { return pos_; }

void MachineGun::set_pos(Vector2 pos) { pos_ = pos; }

Bullet* MachineGun::Fire() {
    interval_count_ = firing_interval_;
    // 弾はBulletContainerで管理される。
    return new StraightBullet(pos_, Vector2{8.f, 8.f}, Vector2::up, 1000.f, 3.f, true,
                              Color::yellow);
}

bool MachineGun::CanFire() { return interval_count_ <= 0.f; }

void MachineGun::CountdownInterval(float delta_time) { interval_count_ -= delta_time; }

} // namespace spaceshooter