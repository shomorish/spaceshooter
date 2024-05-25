#include "game.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdexcept>

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
    level_ = new Title(&game_context_, this);
}

Game::~Game() {
    if (level_) {
        delete level_;
        level_ = NULL;
    }

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

    while (!quit) {
        timer_->UpdateTime();

        // 入力アクションをクリア
        level_->ClearInputActions();

        // 入力状態を更新
        level_->UpdateInputState();

        // イベントループ
        while (SDL_PollEvent(&event) > 0) {
            switch (event.type) {
            case SDL_QUIT:
                quit = true;
                break;
            default:
                // 入力状態をイベントから取得
                level_->HandleInputEvent(event);
                break;
            }
        }

        // レベルの更新
        level_->Tick(timer_->get_delta_time());

        auto renderer = game_context_.get_renderer()->sdl();
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
        SDL_RenderClear(renderer);

        // レベルの描画
        level_->Render();

        SDL_RenderPresent(renderer);
    }
}

void Game::OpenLevel(LevelType level_type) {
    if (level_) {
        delete level_;
        level_ = NULL;
    }
    switch (level_type) {
    case LevelType::kTitle:
        level_ = new Title(&game_context_, this);
        break;
    case LevelType::kStage1:
        level_ = new Stage1(&game_context_, this);
        break;
    }
}

} // namespace spaceshooter