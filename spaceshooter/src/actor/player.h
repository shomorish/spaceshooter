#pragma once

#include <SDL.h>
#include <string>
#include <vector>

#include "../common/range.h"
#include "../common/vector2.h"
#include "../input/input_action.h"
#include "../texture/texture.h"
#include "bullet.h"
#include "character.h"
#include "weapon.h"

namespace spaceshooter {

class Player : public Character {
 public:
    Player(Controller* owner, Texture* texture, Vector2 pos = Vector2::zero,
           Vector2 size = Vector2{64.f, 64.f}, Vector2 direction = Vector2::up, float speed = 200,
           float angle_ = 0.f, float rotation_speed = 120.f, float hp = 5.f);
    Player(const Player&) = delete;

    ~Player();

    void set_pos(Vector2 pos) override;
    float get_speed();
    void set_speed(float speed);
    float get_angle();
    void set_angle(float angle);
    float get_rotation_speed();
    void set_rotation_speed(float rotation_speed);
    float get_hp();
    Weapon* get_weapon();
    void set_weapon(Weapon* weapon);

    void ApplyDamage(float damage) override;

    Player& operator=(const Player&) = delete;

 private:
    float speed_;
    float rotation_speed_;
    float hp_;
    Weapon* weapon_;
};

} // namespace spaceshooter
