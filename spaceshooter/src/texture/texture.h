#pragma once

#include <SDL.h>
#include <string>

#include "../font/font.h"

namespace spaceshooter {

class Texture {
 private:
    SDL_Texture* texture_;

 public:
    Texture(std::string path, SDL_Renderer* renderer);
    Texture(Font* font, std::string text, SDL_Color text_color, SDL_Renderer* renderer);
    Texture(const Texture&) = delete;

    ~Texture();

    SDL_Texture* sdl();

    Texture& operator=(const Texture&) = delete;
};

} // namespace spaceshooter
