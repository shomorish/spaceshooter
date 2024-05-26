#pragma once

#include <SDL.h>
#include <string>

#include "../font/font.h"

namespace spaceshooter {

class Texture {
 public:
    Texture(std::string path, SDL_Renderer* renderer);
    Texture(Font* font, std::string text, SDL_Color text_color, SDL_Renderer* renderer);
    Texture(const Texture&) = delete;

    ~Texture();

    float get_width();
    float get_height();

    SDL_Texture* sdl();

    void SetAlpha(Uint8 alpha);

    Texture& operator=(const Texture&) = delete;

 private:
    SDL_Texture* texture_;
    float width_;
    float height_;
};

} // namespace spaceshooter
