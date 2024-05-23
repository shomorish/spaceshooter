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
    InputMapping* get_input_mapping();
    void set_input_mapping(InputMapping* input_mapping);

    void Init();
    void Release();

 private:
    Window* window_;
    Renderer* renderer_;
    AssetManager* asset_manager_;
    InputMapping* input_mapping_;
};

} // namespace spaceshooter
