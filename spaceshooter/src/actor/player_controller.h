#pragma once

#include <vector>

#include "../input/input_action.h"
#include "../level/level.h"
#include "controller.h"
#include "player.h"

namespace spaceshooter {

class PlayerController : public Controller {
 public:
    PlayerController(Level* level, Range area_x_range, Range area_y_range);

    ~PlayerController();

    virtual Collider* get_collider() override;

    void Tick(const InputActionContainer* action_container, const float& delta_time) override;
    void Render(SDL_Renderer* renderer, Camera* camera) override;
    virtual bool HasCollider() override;
    void DestroyCharacter() override;
    float GetPlayerHp();

 private:
    Level* level_;
    Range x_movable_range_;
    Range y_movable_range_;

    void Move(float delta_time);
    void Rotate(const Vector2& direction, float delta_time);
    bool CanFire();
    void CountdownFiringInterval(float delta_time);
    Bullet* Fire();
};

} // namespace spaceshooter
