#include "../include/game.h"

#include <SDL.h>
#include <SDL_image.h>
#include <stdexcept>

#include "../include/input/im_playing.h"
#include "../include/level/stage1.h"

namespace spaceshooter {

Game::Game() : container_(NULL), asset_manager_(NULL), timer_(NULL), input_mapping_(NULL) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw std::runtime_error("Failed to initialize SDL.");
    }

    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        throw std::runtime_error("Failed to initialize SDL image.");
    }

    container_ = new GameContainer("Space Shooter", 640, 480);
    asset_manager_ = new AssetManager(container_->get_renderer()->sdl());
    timer_ = new Timer();
}

Game::~Game() {
    if (container_ != NULL) {
        delete container_;
        container_ = NULL;
    }

    if (asset_manager_ != NULL) {
        delete asset_manager_;
        asset_manager_ = NULL;
    }

    if (timer_ != NULL) {
        delete timer_;
        timer_ = NULL;
    }

    if (input_mapping_ != NULL) {
        delete input_mapping_;
        input_mapping_ = NULL;
    }

    IMG_Quit();
    SDL_Quit();
}

void Game::Run() {
    bool quit = false;
    SDL_Event event;
    Stage1 level(container_, asset_manager_, &input_mapping_);

    while (!quit) {
        timer_->UpdateTime();

        if (input_mapping_ != NULL) {
            // 全てのアクションをクリア
            input_mapping_->ClearInputActions();
            // 入力状態を更新
            input_mapping_->UpdateInputState();
        }

        // イベントループ
        while (SDL_PollEvent(&event) > 0) {
            switch (event.type) {
            case SDL_QUIT:
                quit = true;
                break;
            default:
                // 入力状態をイベントから取得
                if (input_mapping_ != NULL) {
                    input_mapping_->HandleInputEvent(event);
                }
                break;
            }
        }

        // 入力状態からアクションを生成
        auto actions = std::vector<InputAction*>();
        if (input_mapping_ != NULL) {
            actions = input_mapping_->GenerateInputAction();
        }

        level.Tick(actions, timer_->get_delta_time());

        SDL_SetRenderDrawColor(container_->get_renderer()->sdl(), 0, 0, 0, 0xFF);
        SDL_RenderClear(container_->get_renderer()->sdl());

        level.Render();

        SDL_RenderPresent(container_->get_renderer()->sdl());
    }
}

} // namespace spaceshooter