#pragma once

#include "../animation/infinity_animation.h"
#include "../gui/text_view.h"
#include "level.h"

namespace spaceshooter {

class Title : public Level {
 public:
    Title(GameContext* game_context);

    ~Title();

    void Tick(std::vector<InputAction> actions, float delta_time);
    void Render();

 private:
    InfinityAnimation* enter_text_animation_;
    TextView title_text_view_;
    TextView enter_text_view_;
};

} // namespace spaceshooter
