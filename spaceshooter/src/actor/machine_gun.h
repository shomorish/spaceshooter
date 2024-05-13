#pragma once

#include "../common/vector2.h"
#include "bullet.h"

namespace spaceshooter {

class MachineGun {
 public:
    MachineGun(Vector2 pos, float firing_interval);

    ~MachineGun();

    Vector2 get_pos();
    void set_pos(Vector2 pos);

    Bullet* Fire();
    bool CanFire();
    void CountdownInterval(float delta_time);

 private:
    Vector2 pos_;
    float firing_interval_;
    float interval_count_;
};

} // namespace spaceshooter
