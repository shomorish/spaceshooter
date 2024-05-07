#include "../include/game.h"

#include <SDL.h>
#include <SDL_image.h>
#include <stdexcept>

namespace spaceshooter {

Game::Game() : container_(NULL) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw std::runtime_error("Failed to initialize SDL.");
    }

    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        throw std::runtime_error("Failed to initialize SDL image.");
    }

    container_ = new GameContainer("Space Shooter", 640, 480);
}

Game::~Game() {
    if (container_ != NULL) {
        delete (container_);
        container_ = NULL;
    }

    IMG_Quit();
    SDL_Quit();
}

void Game::Run() {
    bool quit = false;
    SDL_Event event;
    SDL_Renderer* renderer = container_->get_renderer()->sdl();
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

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }
}

} // namespace spaceshooter