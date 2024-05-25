#pragma once

#include "../animation/infinity_animation.h"
#include "../gui/text_view.h"
#include "level.h"

namespace spaceshooter {

enum class TitleState {
    kEnter,
    kPlay,
    kExit,
};

class Title : public Level {
 public:
    Title(GameContext* game_context, OpenLevelInterface* open_level_interface);

    ~Title();

    void Tick(float delta_time) override;
    void Render();

 private:
    TitleState state_;
    InfinityAnimation* enter_text_animation_;
    TextView title_text_view_;
    TextView enter_text_view_;
};

} // namespace spaceshooter
