#include "character.h"

namespace spaceshooter {

Character::Character(Vector2 pos, Vector2 size, Vector2 direction, SDL_Texture* texture)
    : pos_(pos), size_(size), direction_(direction), texture_(texture), angle_(0.f) {}

Character::~Character() {}

Vector2 Character::get_pos() { return pos_; }

void Character::set_pos(Vector2 pos) { pos_ = pos; }

Vector2 Character::get_size() { return size_; }

void Character::set_size(Vector2 size) { size_ = size; }

Vector2 Character::get_direction() { return direction_; }

void Character::set_direction(Vector2 direction) { direction_ = direction; }

SDL_Texture* Character::get_texture() { return texture_; }

void Character::set_texture(SDL_Texture* texture) { texture_ = texture; }

void Character::Render(SDL_Renderer* renderer) {
    SDL_FRect rect{pos_.x, pos_.y, size_.x, size_.y};
    SDL_RenderCopyExF(renderer, texture_, NULL, &rect, angle_, NULL, SDL_FLIP_NONE);
}

} // namespace spaceshooter