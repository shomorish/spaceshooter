#pragma once

#include "../count/enemy_counter.h"
#include "../level/level.h"
#include "character.h"
#include "controller.h"

namespace spaceshooter {

class RushAiController : public Controller {
 public:
    RushAiController(Level* level, Vector2 pos, Character** target, EnemyCounter* enemy_counter);

    ~RushAiController();

    Collider* get_collider() override;

    void Tick(const float& delta_time) override;
    void Tick(const std::vector<InputAction>& actions, const float& delta_time) override;
    void Render(SDL_Renderer* renderer, Camera* camera) override;
    bool HasCollider() override;
    void DestroyCharacter() override;

 private:
    Character** target_;
    EnemyCounter* enemy_counter_;

    void Move(const float& delta_time);
    void Rotate(const float& delta_time);
};

} // namespace spaceshooter
