#include "player.h"

#include <cmath>

#include "../common/cast.h"
#include "../common/matrix2x2.h"
#include "../common/vector3.h"
#include "asteroid.h"
#include "machine_gun.h"

namespace spaceshooter {

Player::Player(Controller* owner, Texture* texture, Vector2 pos, Vector2 size, Vector2 direction,
               float speed, float angle, float rotation_speed)
    : Character{pos, size, direction, texture->sdl(), owner}, speed_(speed),
      rotation_speed_(rotation_speed) {
    collider_ = new Collider(pos_ + size.x / 2.f, size.x / 2.f, this);
    collider_->RegistOnCollisionListener([this](Actor* other) {
        const Asteroid* asteroid = SafeCast<Actor, Asteroid>(other);
        if (asteroid != NULL) {
            // printf("Collision the player and asteroid\n");
        } else {
            const Bullet* b = SafeCast<Actor, Bullet>(other);
            if (b != NULL) {
                // printf("Collision the bullet and asteroid\n");
            }
        }
    });
    weapon_ = new MachineGun(pos_, direction, 0.1f, BulletOwnerType::kPlayer);
}

Player::~Player() {
    texture_ = NULL;

    if (weapon_ != NULL) {
        delete weapon_;
        weapon_ = NULL;
    }
}

void Player::set_pos(Vector2 pos) {
    Actor::set_pos(pos);
    collider_->set_pos(pos);
    weapon_->set_pos(pos);
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