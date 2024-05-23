#pragma once

#include "../actor/player.h"
#include "../actor/player_controller.h"
#include "../asset/asset_manager.h"
#include "../collision/collision_list.h"
#include "../collision/linear_quadtree.h"
#include "../count/enemy_counter.h"
#include "../gamestate/stage1_state.h"
#include "../gui/text_view.h"
#include "../input/input_mapping.h"
#include "level.h"

namespace spaceshooter {

class Stage1 : public Level {
 public:
    Stage1(GameContext* game_context);

    ~Stage1();

    void Tick(std::vector<InputAction> actions, float delta_time) override;
    void Render() override;
    int CalcScore();

 private:
    PlayerController* player_controller_;
    LinearQuadtree quadtree_;
    CollisionList* collision_list_;
    EnemyCounter enemy_counter_;
    TextView enemies_text_view_;
    TextView score_text_view_;
    TextView hp_text_view_;
};

} // namespace spaceshooter
