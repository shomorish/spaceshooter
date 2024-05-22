#include "texture.h"

#include <SDL_image.h>
#include <stdexcept>

namespace spaceshooter {

Texture::Texture(std::string path, SDL_Renderer* renderer) : texture_(NULL) {
    SDL_Surface* surface = IMG_Load(path.c_str());
    if (surface == NULL) {
        throw std::runtime_error("Failed to load png.\n");
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    surface = NULL;
    if (texture == NULL) {
        throw std::runtime_error("Failed to create texture.\n");
    }

    texture_ = texture;
}

Texture::Texture(Font* font, std::string text, SDL_Color text_color, SDL_Renderer* renderer) {
    SDL_Surface* surface = TTF_RenderText_Solid(font->sdl(), text.c_str(), text_color);
    if (surface == NULL) {
        throw std::runtime_error("Failed to load font.\n");
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    surface = NULL;
    if (texture == NULL) {
        throw std::runtime_error("Failed to create texture.\n");
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