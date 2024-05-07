#include "../../include/actor/player.h"

#include <SDL_image.h>
#include <stdexcept>

namespace spaceshooter {

Player::Player(std::string texture_path, int width, int height, int pos_x, int pos_y,
               GameContainer* container)
    : texture_(NULL), width_(width), height_(height), pos_x_(pos_x), pos_y_(pos_y),
      container_(container) {

    SDL_Surface* surface = IMG_Load(texture_path.c_str());
    if (surface == NULL) {
        throw std::runtime_error("Failed to load player png.");
    }

    texture_ = SDL_CreateTextureFromSurface(container_->get_renderer()->sdl(), surface);
    if (texture_ == NULL) {
        SDL_FreeSurface(surface);
        surface = NULL;
        throw std::runtime_error("Failed to create player texture.");
    }

    SDL_FreeSurface(surface);
    surface = NULL;
}

Player::~Player() {
    container_ = NULL;

    if (texture_ != NULL) {
        SDL_DestroyTexture(texture_);
        texture_ = NULL;
    }

    width_ = 0;
    height_ = 0;
    pos_x_ = 0;
    pos_y_ = 0;
}

void Player::Render() {
    SDL_Rect rect;
    rect.x = pos_x_;
    rect.y = pos_y_;
    rect.w = width_;
    rect.h = height_;
    SDL_RenderCopy(container_->get_renderer()->sdl(), texture_, NULL, &rect);
}

} // namespace spaceshooter