#include "player.h"

#include <cmath>

#include "../common/matrix2x2.h"
#include "../common/vector3.h"
#include "machine_gun.h"

namespace spaceshooter {

Player::Player(Texture* texture, Vector2 pos, Vector2 size, Vector2 direction, float speed,
               float angle, float rotation_speed)
    : texture_(NULL), pos_(pos), size_(size), direction_(direction), speed_(speed), angle_(angle),
      rotation_speed_(rotation_speed) {
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

void Player::Move(Range x_limit, Range y_limit, float delta_time) {

    pos_ += direction_ * speed_ * delta_time;

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

void Player::Rotate(const Vector2& direction, float delta_time) {
    // 回転量（単位は度数法）の計算
    float radian = std::acosf(direction_.Dot(direction));
    float angle = radian * 180.f / (float)M_PI;
    float rotation_amount = rotation_speed_ * delta_time;
    if (rotation_amount > angle) {
        rotation_amount = angle;
    }

    // 回転の方向を外積で求める
    Vector3 a = Vector3{direction_.x, direction_.y, 0.f};
    Vector3 b = Vector3{direction.x, direction.y, 0.f};
    Vector3 cross = a.Cross(b);
    if (cross.z > 0.f) {
        // 右回りで回転
        angle_ += rotation_amount;
        Matrix2x2 m(std::cosf(rotation_amount * (float)M_PI / 180.f),
                    -std::sinf(rotation_amount * (float)M_PI / 180.f),
                    std::sinf(rotation_amount * (float)M_PI / 180.f),
                    std::cosf(rotation_amount * (float)M_PI / 180.f));
        // 誤差？で単位ベクトルにならないので、正規化して単位ベクトルにする
        direction_ = (m * direction_).Normalize();
    } else {
        // 左回りで回転
        angle_ -= rotation_amount;
        Matrix2x2 m(std::cosf(rotation_amount * (float)M_PI / 180.f),
                    std::sinf(rotation_amount * (float)M_PI / 180.f),
                    -std::sinf(rotation_amount * (float)M_PI / 180.f),
                    std::cosf(rotation_amount * (float)M_PI / 180.f));
        // 誤差？で単位ベクトルにならないので、正規化して単位ベクトルにする
        direction_ = (m * direction_).Normalize();
    }
}

void Player::Render(SDL_Renderer* renderer) {
    SDL_FRect rect;
    rect.x = pos_.x;
    rect.y = pos_.y;
    rect.w = size_.x;
    rect.h = size_.y;
    SDL_RenderCopyExF(renderer, texture_, NULL, &rect, angle_, NULL, SDL_FLIP_NONE);
}

bool Player::CanFire() { return weapon_->CanFire(); }

void Player::CountdownFiringInterval(float delta_time) { weapon_->CountdownInterval(delta_time); }

Bullet* Player::Fire() { return weapon_->Fire(); }

} // namespace spaceshooter