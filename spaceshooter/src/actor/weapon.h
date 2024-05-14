#pragma once

#include "../common/vector2.h"
#include "bullet.h"

namespace spaceshooter {

class Weapon {
 public:
    Weapon(Vector2 pos, Vector2 direction, float firing_interval, float interval_count);

    virtual ~Weapon();

    Vector2 get_pos();
    void set_pos(Vector2 pos);
    Vector2 get_direction();
    void set_direction(Vector2 direction);

    bool CanFire();
    void CountdownInterval(float delta_time);
    virtual Bullet* Fire() = 0;

 protected:
    Vector2 pos_;
    Vector2 direction_;
    float firing_interval_;
    float interval_count_;
};

} // namespace spaceshooter
