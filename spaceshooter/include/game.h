#pragma once

#include "window.h"
#include "renderer.h"

namespace spaceshooter {

class Game {
private:
    Window* window_;
    Renderer* renderer_;

public:
    Game();
    ~Game();

    void Run();
};

} // namespace spaceshooter
