#pragma once

#include <SDL.h>
#include <string>
#include <vector>

#include "../game_container.h"
#include "../input/action/base/input_action.h"
#include "../texture/texture.h"

namespace spaceshooter {

class Player {

 private:
    GameContainer* container_;
    SDL_Texture* texture_;
    float width_;
    float height_;
    float pos_x_;
    float pos_y_;

    float speed_;

 public:
    Player(GameContainer* container, Texture*, float width = 64.f, float height = 64.f,
           float pos_x = 0.f, float pos_y = 0.f, float speed = 300);
    Player(const Player&) = delete;

    ~Player();

    void Tick(std::vector<InputAction*> actions, float delta_time);
    void Render();

    Player& operator=(const Player&) = delete;
};

} // namespace spaceshooter
