#pragma once

#include "../common/vector2.h"
#include "bullet.h"
#include "weapon.h"

namespace spaceshooter {

class MachineGun : public Weapon {
 public:
    MachineGun(Vector2 pos, Vector2 direction, float firing_interval);

    ~MachineGun();

    Bullet* Fire() override;
};

} // namespace spaceshooter
