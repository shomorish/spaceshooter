#include "../include/renderer.h"

#include <stdexcept>

namespace spaceshooter {

Renderer::Renderer(Window* window) : renderer_(NULL) {
    renderer_ = SDL_CreateRenderer(window->sdl(), -1, SDL_RENDERER_ACCELERATED);
    if (renderer_ == NULL) throw std::runtime_error("Failed to create renderer.");
}

Renderer::~Renderer() {
    if (renderer_ != NULL) {
        SDL_DestroyRenderer(renderer_);
        renderer_ = NULL;
    }
}

SDL_Renderer* Renderer::sdl() { return renderer_; }

}; // namespace spaceshooter