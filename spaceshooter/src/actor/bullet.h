#pragma once

#include <SDL.h>

namespace spaceshooter {

class Bullet {
 public:
    Bullet(const Bullet&) = delete;

    virtual ~Bullet();

    bool get_is_alive();
    void set_is_alive(bool is_alive);

    virtual void Tick(float delta_time) = 0;
    virtual void Render(SDL_Renderer* renderer) = 0;

    Bullet& operator=(const Bullet&) = delete;

 protected:
    bool is_alive_;
};

} // namespace spaceshooter
