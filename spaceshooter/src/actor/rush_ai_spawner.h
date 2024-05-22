#pragma once

#include "../level/level.h"
#include "actor.h"
#include "character.h"

namespace spaceshooter {

class RushAiSpawner : public Actor {
 public:
    static int max_spawn_num;

    RushAiSpawner(Level* level, Vector2 pos, float duration, Character** target);

    ~RushAiSpawner();

    int get_num_of_spawned();

    void Tick(const float& delta_time) override;
    void Spawn();

 private:
    Level* level_;
    float duration_;
    float spawn_elapsed_time_;
    Character** target_;

    static int num_of_spawned_;
};

} // namespace spaceshooter
