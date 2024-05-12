#include "player.h"

#include <SDL_image.h>
#include <stdexcept>
#include <typeinfo>

#include "../input/action/ia_fire.h"
#include "../input/action/ia_move.h"

namespace spaceshooter {

Player::Player(GameContainer* container, Texture* texture, float width, float height, float pos_x,
               float pos_y, float speed)
    : texture_(NULL), width_(width), height_(height), pos_x_(pos_x), pos_y_(pos_y), speed_(speed),
      container_(container) {
    texture_ = texture->sdl();
}

Player::~Player() {
    container_ = NULL;
    texture_ = NULL;

    width_ = 0.f;
    height_ = 0.f;
    pos_x_ = 0.f;
    pos_y_ = 0.f;
    speed_ = 0.f;
}

void Player::Tick(std::vector<InputAction*> actions, float delta_time) {
    auto iter = actions.begin();
    while (iter != actions.end()) {
        InputAction* action = *iter;
        if (typeid(*action) == typeid(IA_Move)) {
            auto move = dynamic_cast<IA_Move*>(action);
            auto normalized = move->get_value().Normalize();
            pos_x_ += normalized.x * speed_ * delta_time;
            pos_y_ += normalized.y * speed_ * delta_time;

            // 画面外に出ないように位置を補正
            if (pos_x_ < 0.f) {
                pos_x_ = 0.f;
            } else if (pos_x_ >= container_->get_window()->get_width() - width_) {
                pos_x_ = container_->get_window()->get_width() - width_;
            }
            if (pos_y_ < 0.f) {
                pos_y_ = 0.f;
            } else if (pos_y_ >= container_->get_window()->get_height() - height_) {
                pos_y_ = container_->get_window()->get_height() - height_;
            }
        } else if (typeid(*action) == typeid(IA_Fire)) {
            // TODO: 攻撃
        }
        iter++;
    }
}

void Player::Render() {
    SDL_FRect rect;
    rect.x = pos_x_;
    rect.y = pos_y_;
    rect.w = width_;
    rect.h = height_;
    SDL_RenderCopyF(container_->get_renderer()->sdl(), texture_, NULL, &rect);
}

} // namespace spaceshooter