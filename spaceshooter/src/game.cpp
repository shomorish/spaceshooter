#include "game.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdexcept>

#include "input/im_playing.h"
#include "level/stage1.h"
#include "level/title.h"

namespace spaceshooter {

Game::Game() : timer_(NULL) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw std::runtime_error("Failed to initialize SDL.");
    }

    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        throw std::runtime_error("Failed to initialize SDL image.");
    }

    if (TTF_Init() == -1) {
        throw std::runtime_error("Failed to initialize SDL TTF.");
    }

    game_context_.Init();
    timer_ = new Timer();
}

Game::~Game() {
    game_context_.Release();

    if (timer_ != NULL) {
        delete timer_;
        timer_ = NULL;
    }

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void Game::Run() {
    bool quit = false;
    SDL_Event event;
    Stage1 level(&game_context_);
    // Title level(&game_context_);

    while (!quit) {
        timer_->UpdateTime();

        // 入力アクションをクリア
        level.ClearInputActions();

        // 入力状態を更新
        level.UpdateInputState();

        // イベントループ
        while (SDL_PollEvent(&event) > 0) {
            switch (event.type) {
            case SDL_QUIT:
                quit = true;
                break;
            default:
                // 入力状態をイベントから取得
                level.HandleInputEvent(event);
                break;
            }
        }

        // レベルの更新
        level.Tick(timer_->get_delta_time());

        auto renderer = game_context_.get_renderer()->sdl();
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
        SDL_RenderClear(renderer);

        // レベルの描画
        level.Render();

        SDL_RenderPresent(renderer);
    }
}

} // namespace spaceshooter