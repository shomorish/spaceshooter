#include "../include/game.h"

#include <SDL.h>
#include <stdexcept>

namespace spaceshooter {

Game::Game() : window_(NULL), renderer_(NULL) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw std::runtime_error("Failed to initialize SDL.");
    }
    window_ = new Window("Space Shooter", 640, 480);
    renderer_ = new Renderer(window_);
}

Game::~Game() {
    if (window_ != NULL) {
        delete (window_);
        window_ = NULL;
    }

    if (renderer_ != NULL) {
        delete (renderer_);
        renderer_ = NULL;
    }

    SDL_Quit();
}

void Game::Run() {
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        // イベントループ
        while (SDL_PollEvent(&event) > 0) {
            switch (event.type) {
            case SDL_QUIT:
                quit = true;
                break;
            default: // NOP
                break;
            }
        }

        SDL_SetRenderDrawColor(renderer_->get_renderer(), 0, 0, 0, 0xFF);
        SDL_RenderClear(renderer_->get_renderer());
        SDL_RenderPresent(renderer_->get_renderer());
    }
}

} // namespace spaceshooter