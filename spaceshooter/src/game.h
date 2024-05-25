#pragma once

#include "game_context.h"
#include "level/level.h"
#include "time/timer.h"

namespace spaceshooter {

class Game {
 public:
    Game();
    ~Game();

    void Run();
    void OpenLevel(Level* level);

 private:
    GameContext game_context_;
    Timer* timer_;
    Level* level_;
};

} // namespace spaceshooter
