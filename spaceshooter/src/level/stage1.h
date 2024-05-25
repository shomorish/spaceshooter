#pragma once

#include "../actor/player_controller.h"
#include "../collision/collision_list.h"
#include "../collision/linear_quadtree.h"
#include "../count/enemy_counter.h"
#include "../gui/text_view.h"
#include "level.h"

namespace spaceshooter {

enum class Stage1State {
    kEnter,
    kIntro,
    kPlay,
    kPause,
    kGameClear,
    kGameOver,
    kExit,
};

class Stage1 : public Level {
 public:
    Stage1(GameContext* game_context, OpenLevelInterface* open_level_interface);

    ~Stage1();

    void Tick(float delta_time) override;
    void Render() override;
    int CalcScore();

 private:
    Stage1State state_;
    PlayerController* player_controller_;
    LinearQuadtree quadtree_;
    CollisionList* collision_list_;
    EnemyCounter enemy_counter_;
    TextView enemies_text_view_;
    TextView score_text_view_;
    TextView hp_text_view_;

    void Enter(const float& delta_time);
    void Play(const float& delta_time);
    void Pause(const float& delta_time);
    void GameClear(const float& delta_time);
    void GameOver(const float& delta_time);
    void Exit(const float& delta_time);
};

} // namespace spaceshooter
