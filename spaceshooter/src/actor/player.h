#pragma once

#include <SDL.h>
#include <string>
#include <vector>

#include "../input/action/input_action.h"
#include "../texture/texture.h"
#include "../common/range.h"

namespace spaceshooter {

class Player {

 private:
    SDL_Texture* texture_;
    float width_;
    float height_;
    float pos_x_;
    float pos_y_;

    float speed_;

 public:
    Player(Texture*, float width = 64.f, float height = 64.f, float pos_x = 0.f, float pos_y = 0.f,
           float speed = 300);
    Player(const Player&) = delete;

    ~Player();

    void Tick(std::vector<InputAction*> actions, Range screen_width_limit, Range screen_height_limit, float delta_time);
    void Render(SDL_Renderer* renderer);

    Player& operator=(const Player&) = delete;
};

} // namespace spaceshooter
