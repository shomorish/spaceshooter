#pragma once

#include "game_container.h"

namespace spaceshooter {

class Game {
 private:
    GameContainer* container_;

 public:
    Game();
    ~Game();

    void Run();
};

} // namespace spaceshooter
