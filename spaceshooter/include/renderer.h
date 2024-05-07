#pragma once

#include <SDL.h>

#include "window.h"

namespace spaceshooter {

class Renderer {

 private:
    SDL_Renderer* renderer_;

 public:
    Renderer(Window*);
    ~Renderer();

    SDL_Renderer* get_renderer();
};

} // namespace spaceshooter
