#include "background.h"

namespace spaceshooter {

Background::Background(Texture* texture, Vector2 pos, Vector2 size)
    : pos_(pos), size_(size), texture_(texture->sdl()) {}

Background::~Background() { texture_ = NULL; }

void Background::Render(SDL_Renderer* renderer) {
    SDL_FRect rect{pos_.x, pos_.y, size_.x, size_.y};
    SDL_RenderCopyF(renderer, texture_, NULL, &rect);
}

} // namespace spaceshooter