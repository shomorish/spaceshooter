#include "../include/game.h"

#include <SDL.h>
#include <SDL_image.h>
#include <stdexcept>

#include "../include/input/im_playing.h"
#include "../include/level/stage1.h"

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
    InputMapping* input_mapping = NULL;
    Stage1 level(container_, &input_mapping);

    while (!quit) {
        if (input_mapping != NULL) {
            // 全てのアクションをクリア
            input_mapping->ClearInputActions();
            // 入力状態を更新
            input_mapping->UpdateInputState();
        }

        // イベントループ
        while (SDL_PollEvent(&event) > 0) {
            switch (event.type) {
            case SDL_QUIT:
                quit = true;
                break;
            default:
                // 入力状態をイベントから取得
                if (input_mapping != NULL) {
                    input_mapping->HandleInputEvent(event);
                }
                break;
            }
        }

        // 入力状態からアクションを生成
        auto actions = std::vector<InputAction*>();
        if (input_mapping != NULL) {
            actions = input_mapping->GenerateInputAction();
        }

        level.Tick(actions);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
        SDL_RenderClear(renderer);

        level.Render();

        SDL_RenderPresent(renderer);
    }
}

} // namespace spaceshooter