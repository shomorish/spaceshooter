#include "window.h"

#include <stdexcept>

namespace spaceshooter {

Window::Window(const char* title, int width, int height)
    : window_(NULL), width_(width), height_(height) {
    window_ = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width,
                               height, SDL_WINDOW_SHOWN);
    if (window_ == NULL) throw std::runtime_error("Failed to create window.");
}

Window::~Window() {
    if (window_ != NULL) {
        SDL_DestroyWindow(window_);
        window_ = NULL;
    }
    width_ = 0;
    height_ = 0;
}

SDL_Window* Window::sdl() { return window_; }

int Window::get_width() { return width_; }

int Window::get_height() { return height_; }

}; // namespace spaceshooter
