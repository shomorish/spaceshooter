#pragma once

#include "../level/level.h"
#include "controller.h"

namespace spaceshooter {

class RushAiController : public Controller {
 public:
    RushAiController(Level* level);

    ~RushAiController();

    void Tick(const float& delta_time) override;

 private:
    void Move(const float& delta_time);
    void Rotate(const float& delta_time);
};

} // namespace spaceshooter
