#pragma once

#include "game_container.h"
#include "input/input_mapping.h"
#include "time/timer.h"

namespace spaceshooter {

class Game {
 private:
    GameContainer* container_;
    InputMapping* input_mapping_;
    Timer* timer_;

 public:
    Game();
    ~Game();

    void Run();
};

} // namespace spaceshooter
