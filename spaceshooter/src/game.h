#pragma once

#include "game_context.h"
#include "time/timer.h"

namespace spaceshooter {

class Game {
 private:
    GameContext game_context_;
    Timer* timer_;

 public:
    Game();
    ~Game();

    void Run();
};

} // namespace spaceshooter
