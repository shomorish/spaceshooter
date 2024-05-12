#include "player.h"

#include <SDL_image.h>
#include <stdexcept>
#include <typeinfo>

namespace spaceshooter {

Player::Player(Texture* texture, float width, float height, float pos_x, float pos_y, float speed)
    : texture_(NULL), width_(width), height_(height), pos_x_(pos_x), pos_y_(pos_y), speed_(speed) {
    texture_ = texture->sdl();
}

Player::~Player() {
    texture_ = NULL;

    width_ = 0.f;
    height_ = 0.f;
    pos_x_ = 0.f;
    pos_y_ = 0.f;
    speed_ = 0.f;
}

void Player::Move(Vector2 direction, Range x_limit, Range y_limit, float delta_time) {
    pos_x_ += direction.x * speed_ * delta_time;
    pos_y_ += direction.y * speed_ * delta_time;

    // 画面外に出ないように位置を補正
    if (pos_x_ < 0.f) {
        pos_x_ = 0.f;
    } else if (pos_x_ >= x_limit.max - width_) {
        pos_x_ = x_limit.max - width_;
    }
    if (pos_y_ < 0.f) {
        pos_y_ = 0.f;
    } else if (pos_y_ >= y_limit.max - height_) {
        pos_y_ = y_limit.max - height_;
    }
}

void Player::Render(SDL_Renderer* renderer) {
    SDL_FRect rect;
    rect.x = pos_x_;
    rect.y = pos_y_;
    rect.w = width_;
    rect.h = height_;
    SDL_RenderCopyF(renderer, texture_, NULL, &rect);
}

} // namespace spaceshooter