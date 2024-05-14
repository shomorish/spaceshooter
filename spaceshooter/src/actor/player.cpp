#include "player.h"

#include <cmath>

#include "../common/matrix2x2.h"
#include "../common/vector3.h"
#include "machine_gun.h"

namespace spaceshooter {

Player::Player(Texture* texture, Vector2 pos, Vector2 size, Vector2 direction, float speed,
               float angle, float rotation_speed)
    : Character{pos, size, direction, texture->sdl()}, speed_(speed),
      rotation_speed_(rotation_speed) {
    weapon_ = new MachineGun(Vector2::zero, 0.1f);
}

Player::~Player() {
    texture_ = NULL;

    if (weapon_ != NULL) {
        delete weapon_;
        weapon_ = NULL;
    }
}

float Player::get_speed() { return speed_; }

void Player::set_speed(float speed) { speed_ = speed; }

float Player::get_angle() { return angle_; }

void Player::set_angle(float angle) { angle_ = angle; }

float Player::get_rotation_speed() { return rotation_speed_; }

void Player::set_rotation_speed(float rotation_speed) { rotation_speed_ = rotation_speed; }

Weapon* Player::get_weapon() { return weapon_; }

void Player::set_weapon(Weapon* weapon) { weapon_ = weapon; }

} // namespace spaceshooter