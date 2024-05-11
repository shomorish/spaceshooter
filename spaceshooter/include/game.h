#pragma once

#include "asset/asset_manager.h"
#include "game_container.h"
#include "input/input_mapping.h"
#include "time/timer.h"

namespace spaceshooter {

class Game {
 private:
    GameContainer* container_;
    AssetManager* asset_manager_;
    Timer* timer_;
    InputMapping* input_mapping_;

 public:
    Game();
    ~Game();

    void Run();
};

} // namespace spaceshooter
