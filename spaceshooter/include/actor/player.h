#pragma once

#include <SDL.h>
#include <string>

#include "../game_container.h"

namespace spaceshooter {

class Player {

 private:
    GameContainer* container_;
    SDL_Texture* texture_;
    int width_;
    int height_;
    int pos_x_;
    int pos_y_;

 public:
    Player(std::string texture_path, int width, int height, int pos_x, int pos_y,
           GameContainer* container);
    ~Player();
    void Render();
};

} // namespace spaceshooter
