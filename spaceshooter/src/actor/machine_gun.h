#pragma once

#include "../common/vector2.h"
#include "bullet.h"
#include "weapon.h"

namespace spaceshooter {

class MachineGun : public Weapon {
 public:
    MachineGun(Vector2 pos, float firing_interval);

    ~MachineGun();

    Bullet* Fire() override;
};

} // namespace spaceshooter
