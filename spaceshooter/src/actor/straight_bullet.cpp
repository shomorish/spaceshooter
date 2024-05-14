#include "straight_bullet.h"

#include <stdio.h>

namespace spaceshooter {

StraightBullet::StraightBullet(Vector2 pos, Vector2 size, Vector2 direction, float speed,
                               float lifetime, bool is_alive, Color color)
    : Bullet{pos, size, direction, speed, lifetime, is_alive}, color_(color) {}

StraightBullet::~StraightBullet() { printf("~StraightBullet\n"); }

void StraightBullet::Tick(const float& delta_time) {
    pos_ += direction_ * speed_ * delta_time;
    lifetime_ -= delta_time;
    if (lifetime_ <= 0.f) {
        // is_alive_ = false;
        Destroy();
    }
}

void StraightBullet::Render(SDL_Renderer* renderer) {
    SDL_FRect rect;
    rect.x = pos_.x - size_.x / 2;
    rect.y = pos_.y - size_.y / 2;
    rect.w = size_.x;
    rect.h = size_.y;
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0, 0xFF);
    SDL_RenderFillRectF(renderer, &rect);
}

} // namespace spaceshooter