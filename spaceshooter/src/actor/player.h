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

    float speed_;

    Weapon* weapon_;

 public:
    Player(Texture*, Vector2 pos = Vector2::zero, Vector2 size = Vector2{64.f, 64.f},
           float speed = 300);
    Player(const Player&) = delete;

    ~Player();

    void Move(Vector2 direction, Range x_limit, Range y_limit, float delta_time);
    void Render(SDL_Renderer* renderer);
    bool CanFire();
    void CountdownFiringInterval(float delta_time);
    Bullet* Fire();

    Player& operator=(const Player&) = delete;
};

} // namespace spaceshooter
