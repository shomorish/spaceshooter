#pragma once

#include <SDL.h>

namespace spaceshooter {

class Window {
 private:
    SDL_Window* window_;
    int width_;
    int height_;

 public:
    Window(const char*, int, int);
    ~Window();

    SDL_Window* sdl();
};

}; // namespace spaceshooter
