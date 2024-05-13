#pragma once

#include <SDL.h>

#include "../common/vector2.h"

namespace spaceshooter {

class Bullet {
 public:
    Bullet();
    Bullet(Vector2 pos, Vector2 size, Vector2 direction, float speed, float lifetime,
           bool is_alive);
    Bullet(const Bullet&) = delete;

    virtual ~Bullet();

    bool get_is_alive();
    void set_is_alive(bool is_alive);

    virtual void Tick(float delta_time) = 0;
    virtual void Render(SDL_Renderer* renderer) = 0;

    Bullet& operator=(const Bullet&) = delete;

 protected:
    Vector2 pos_;
    Vector2 size_;
    Vector2 direction_;
    float speed_;
    float lifetime_;
    bool is_alive_;
};

} // namespace spaceshooter
