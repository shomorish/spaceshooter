#include "../../../include/actor/projectile/straight_bullet.h"

namespace spaceshooter {

StraightBullet::StraightBullet(Vector2 pos, Vector2 size, Vector2 direction, float speed,
                               float lifetime, SDL_Texture* texture, bool is_alive) {
    pos_ = pos;
    size_ = size;
    direction_ = direction;
    speed_ = speed;
    lifetime_ = lifetime;
    texture_ = texture_;
    is_alive_ = is_alive_;
    on_death_ = NULL;
}

StraightBullet::~StraightBullet() {
    texture_ = NULL;
    on_death_ = NULL;
}

void StraightBullet::Tick(float delta_time) {
    pos_ += direction_ * speed_ * delta_time;
    lifetime_ -= delta_time;
    if (lifetime_ <= 0) {
        is_alive_ = false;
        if (on_death_ != NULL) {
            on_death_();
        }
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