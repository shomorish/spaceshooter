#include "machine_gun.h"

#include "straight_bullet.h"

namespace spaceshooter {

MachineGun::MachineGun(Vector2 pos, Vector2 direction, float firing_interval)
    : Weapon{pos, direction, firing_interval, 0.f} {}

MachineGun::~MachineGun() {}

Bullet* MachineGun::Fire() {
    interval_count_ = firing_interval_;
    return new StraightBullet(pos_, Vector2{8.f, 8.f}, direction_, 1000.f, 3.f, true,
                              Color::yellow);
}

} // namespace spaceshooter