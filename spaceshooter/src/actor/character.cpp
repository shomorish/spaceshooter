#include "character.h"

namespace spaceshooter {

Character::Character(Vector2 pos, Vector2 size, Vector2 direction, SDL_Texture* texture,
                     Controller* owner)
    : Actor{pos, size}, direction_(direction), texture_(texture), angle_(0.f), owner_(owner) {}

Character::~Character() { owner_ = NULL; }

Vector2 Character::get_direction() { return direction_; }

void Character::set_direction(Vector2 direction) { direction_ = direction; }

SDL_Texture* Character::get_texture() { return texture_; }

void Character::set_texture(SDL_Texture* texture) { texture_ = texture; }

void Character::set_owner(Controller* owner) { owner_ = owner; }

void Character::Render(SDL_Renderer* renderer, Camera* camera) {
    Vector2 pos;
    bool result = camera->ConvertToWindowCoords(pos_, &pos);
    if (result) {
        SDL_FRect rect{pos.x - size_.x / 2.f, pos.y - size_.y / 2.f, size_.x, size_.y};
        SDL_RenderCopyExF(renderer, texture_, NULL, &rect, angle_, NULL, SDL_FLIP_NONE);
    }
}

void Character::Destroy() {
    Actor::Destroy();
    if (owner_) {
        owner_->DestroyCharacter();
        owner_ = NULL;
    }
}

} // namespace spaceshooter