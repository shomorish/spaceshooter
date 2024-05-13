#include "player.h"

#include <SDL_image.h>
#include <stdexcept>
#include <typeinfo>

#include "machine_gun.h"

namespace spaceshooter {

Player::Player(Texture* texture, Vector2 pos, Vector2 size, float speed)
    : texture_(NULL), pos_(pos), size_(size), speed_(speed) {
    texture_ = texture->sdl();
    weapon_ = new MachineGun(Vector2::zero, 0.1f);
}

Player::~Player() {
    texture_ = NULL;

    if (weapon_ != NULL) {
        delete weapon_;
        weapon_ = NULL;
    }
}

void Player::Move(Vector2 direction, Range x_limit, Range y_limit, float delta_time) {
    pos_ += direction * speed_ * delta_time;

    // 画面外に出ないように位置を補正
    if (pos_.x < 0.f) {
        pos_.x = 0.f;
    } else if (pos_.x >= x_limit.max - size_.x) {
        pos_.x = x_limit.max - size_.x;
    }
    if (pos_.y < 0.f) {
        pos_.y = 0.f;
    } else if (pos_.y >= y_limit.max - size_.y) {
        pos_.y = y_limit.max - size_.y;
    }

    weapon_->set_pos(pos_ + size_ / 2.f);
}

void Player::Render(SDL_Renderer* renderer) {
    SDL_FRect rect;
    rect.x = pos_.x;
    rect.y = pos_.y;
    rect.w = size_.x;
    rect.h = size_.y;
    SDL_RenderCopyF(renderer, texture_, NULL, &rect);
}

bool Player::CanFire() { return weapon_->CanFire(); }

void Player::CountdownFiringInterval(float delta_time) { weapon_->CountdownInterval(delta_time); }

Bullet* Player::Fire() { return weapon_->Fire(); }

} // namespace spaceshooter