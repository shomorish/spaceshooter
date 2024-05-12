#pragma once

#include "asset/asset_manager.h"
#include "input/input_mapping.h"
#include "renderer.h"
#include "time/timer.h"
#include "window.h"

namespace spaceshooter {

class Game {
 private:
    Window* window_;
    Renderer* renderer_;
    AssetManager* asset_manager_;
    Timer* timer_;
    InputMapping* input_mapping_;

 public:
    Game();
    ~Game();

    void Run();
};

} // namespace spaceshooter
