#pragma once

#include "game_context.h"
#include "level/level.h"
#include "level/level_type.h"
#include "level/open_level_interface.h"
#include "time/timer.h"

namespace spaceshooter {

class Game : public OpenLevelInterface {
 public:
    Game();
    ~Game();

    void Run();
    void OpenLevel(LevelType level_type) override;

 private:
    GameContext game_context_;
    Timer* timer_;
    Level* level_;
};

} // namespace spaceshooter
