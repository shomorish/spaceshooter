#include "rush_ai_spawner.h"

#include "rush_ai_controller.h"

namespace spaceshooter {

int RushAiSpawner::max_spawn_num = 0;

int RushAiSpawner::num_of_spawned_ = 0;

RushAiSpawner::RushAiSpawner(Level* level, Vector2 pos, float duration, Character** target)
    : Actor{pos, Vector2::zero}, level_(level), duration_(duration), spawn_elapsed_time_(0.f),
      target_(target) {}

RushAiSpawner::~RushAiSpawner() {
    level_ = NULL;
    target_ = NULL;
}

int RushAiSpawner::get_num_of_spawned() { return num_of_spawned_; }

void RushAiSpawner::Tick(const float& delta_time) {
    if (*target_ == NULL) return;
    if (num_of_spawned_ >= max_spawn_num) return;

    if (spawn_elapsed_time_ <= 0.f) {
        Spawn();
        spawn_elapsed_time_ = duration_;
    } else {
        spawn_elapsed_time_ -= delta_time;
    }
}

void RushAiSpawner::Spawn() {
    level_->AddActor(new RushAiController(level_, pos_, target_));
    num_of_spawned_++;
}

} // namespace spaceshooter