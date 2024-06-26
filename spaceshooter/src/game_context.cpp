#include "game_context.h"

namespace spaceshooter {

GameContext::GameContext() : window_(NULL), renderer_(NULL), asset_manager_(NULL) {}

GameContext::~GameContext() { Release(); }

Window* GameContext::get_window() { return window_; }

Renderer* GameContext::get_renderer() { return renderer_; }

AssetManager* GameContext::get_asset_manager() { return asset_manager_; }

void GameContext::Init() {
    window_ = new Window("Space Shooter", 800, 600);
    renderer_ = new Renderer(window_);
    asset_manager_ = new AssetManager(renderer_->sdl());
}

void GameContext::Release() {
    if (renderer_ != NULL) {
        delete renderer_;
        renderer_ = NULL;
    }

    if (window_ != NULL) {
        delete window_;
        window_ = NULL;
    }

    if (asset_manager_ != NULL) {
        delete asset_manager_;
        asset_manager_ = NULL;
    }
}

} // namespace spaceshooter