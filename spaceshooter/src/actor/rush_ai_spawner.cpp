#include "rush_ai_spawner.h"

#include "rush_ai_controller.h"

namespace spaceshooter {

RushAiSpawner::RushAiSpawner(Level* level, Vector2 pos, float duration, Character** target,
                             EnemyCounter* enemy_counter)
    : Actor{pos, Vector2::zero}, level_(level), duration_(duration), spawn_elapsed_time_(0.f),
      target_(target), enemy_counter_(enemy_counter) {}

RushAiSpawner::~RushAiSpawner() {
    level_ = NULL;
    target_ = NULL;
    enemy_counter_ = NULL;
}

void RushAiSpawner::Tick(const float& delta_time) {
    if (*target_ == NULL) return;
    if (enemy_counter_->num_of_spawned_enemies >= enemy_counter_->max_spawn_enemies) return;

    if (spawn_elapsed_time_ <= 0.f) {
        Spawn();
        enemy_counter_->num_of_spawned_enemies++;
        spawn_elapsed_time_ = duration_;
    } else {
        spawn_elapsed_time_ -= delta_time;
    }
}

void RushAiSpawner::Spawn() {
    level_->AddActor(new RushAiController(level_, pos_, target_, enemy_counter_));
}

} // namespace spaceshooter