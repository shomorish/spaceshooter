#pragma once

#include <SDL.h>
#include <string>
#include <vector>

#include "../common/range.h"
#include "../common/vector2.h"
#include "../input/input_action.h"
#include "../texture/texture.h"
#include "bullet.h"
#include "weapon.h"

namespace spaceshooter {

class Player {

 private:
    SDL_Texture* texture_;
    Vector2 pos_;
    Vector2 size_;
    Vector2 direction_;

    float speed_;
    float angle_;
    float rotation_speed_;

    Weapon* weapon_;

 public:
    Player(Texture*, Vector2 pos = Vector2::zero, Vector2 size = Vector2{64.f, 64.f},
           Vector2 direction = Vector2::up, float speed = 300, float angle_ = 0.f,
           float rotation_speed = 120.f);
    Player(const Player&) = delete;

    ~Player();

    void Move(Range x_limit, Range y_limit, float delta_time);
    void Rotate(const Vector2& direction, float delta_time);
    void Render(SDL_Renderer* renderer);
    bool CanFire();
    void CountdownFiringInterval(float delta_time);
    Bullet* Fire();

    Player& operator=(const Player&) = delete;
};

} // namespace spaceshooter
