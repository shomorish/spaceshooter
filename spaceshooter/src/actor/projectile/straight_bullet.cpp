#include "../../../include/actor/projectile/straight_bullet.h"

namespace spaceshooter {

StraightBullet::StraightBullet() {
    pos_ = Vector2{0.f, 0.f};
    size_ = Vector2{0.f, 0.f};
    direction_ = Vector2{0.f, 0.f};
    speed_ = 0.f;
    lifetime_ = 0.f;
    texture_ = NULL;
    is_alive_ = false;
}

StraightBullet::StraightBullet(Vector2 pos, Vector2 size, Vector2 direction, float speed,
                               float lifetime, SDL_Texture* texture, bool is_alive) {
    pos_ = pos;
    size_ = size;
    direction_ = direction;
    speed_ = speed;
    lifetime_ = lifetime;
    texture_ = texture_;
    is_alive_ = is_alive_;
}

StraightBullet::~StraightBullet() { texture_ = NULL; }

void StraightBullet::Tick(float delta_time) {
    pos_ += direction_ * speed_ * delta_time;
    lifetime_ -= delta_time;
    if (lifetime_ <= 0) {
        is_alive_ = false;
    }
}

void StraightBullet::Render(SDL_Renderer* renderer) {
    SDL_FRect rect;
    rect.x = pos_.x - size_.x / 2.f;
    rect.y = pos_.y - size_.y / 2.f;
    rect.w = size_.x;
    rect.h = size_.y;
    SDL_RenderCopyF(renderer, texture_, NULL, &rect);
}

} // namespace spaceshooter