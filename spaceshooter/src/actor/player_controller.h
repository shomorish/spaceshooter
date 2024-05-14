#pragma once

#include <vector>

#include "../input/input_action.h"
#include "../level/level.h"
#include "../window.h"
#include "player.h"

namespace spaceshooter {

class PlayerController : public Actor {
 public:
    PlayerController(Level* level, Window* window);
    ~PlayerController();

    void Tick(const std::vector<InputAction>& actions, const float& delta_time);
    void AttachPlayer(Player** player);
    void DetachPlayer();

 private:
    Level* level_;
    Window* window_;
    Player** player_;
};

} // namespace spaceshooter
