#pragma once

#include <vector>

#include "../input/input_action.h"
#include "../level/level.h"
#include "controller.h"
#include "player.h"

namespace spaceshooter {

class PlayerController : public Controller {
 public:
    PlayerController(Level* level);

    ~PlayerController();

    void Tick(const std::vector<InputAction>& actions, const float& delta_time) override;

 private:
    Level* level_;

    void Move(Range x_limit, Range y_limit, float delta_time);
    void Rotate(const Vector2& direction, float delta_time);
    bool CanFire();
    void CountdownFiringInterval(float delta_time);
    Bullet* Fire();
};

} // namespace spaceshooter
