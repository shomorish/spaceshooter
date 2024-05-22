#pragma once

#include "../count/enemy_counter.h"
#include "../level/level.h"
#include "actor.h"
#include "character.h"

namespace spaceshooter {

class RushAiSpawner : public Actor {
 public:
    RushAiSpawner(Level* level, Vector2 pos, float duration, Character** target,
                  EnemyCounter* enemy_counter);

    ~RushAiSpawner();

    void Tick(const float& delta_time) override;
    void Spawn();

 private:
    Level* level_;
    float duration_;
    float spawn_elapsed_time_;
    Character** target_;
    EnemyCounter* enemy_counter_;
};

} // namespace spaceshooter
