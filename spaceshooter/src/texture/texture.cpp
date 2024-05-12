#include "texture.h"

#include <SDL_image.h>
#include <stdexcept>

namespace spaceshooter {

Texture::Texture(std::string path, SDL_Renderer* renderer) : texture_(NULL) {
    SDL_Surface* surface = IMG_Load(path.c_str());
    if (surface == NULL) {
        throw std::runtime_error("Failed to load player png.");
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    surface = NULL;
    if (texture == NULL) {
        throw std::runtime_error("Failed to create player texture.");
    }

    texture_ = texture;
}

Texture::~Texture() {
    if (texture_ != NULL) {
        SDL_DestroyTexture(texture_);
        texture_ = NULL;
    }
}

SDL_Texture* Texture::sdl() { return texture_; }

} // namespace spaceshooter