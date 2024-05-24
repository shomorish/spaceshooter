#pragma once

#include "asset/asset_manager.h"
#include "input/input_mapping.h"
#include "renderer.h"
#include "window.h"

namespace spaceshooter {

class GameContext {
 public:
    GameContext();

    ~GameContext();

    Window* get_window();
    Renderer* get_renderer();
    AssetManager* get_asset_manager();

    void Init();
    void Release();

 private:
    Window* window_;
    Renderer* renderer_;
    AssetManager* asset_manager_;
};

} // namespace spaceshooter
