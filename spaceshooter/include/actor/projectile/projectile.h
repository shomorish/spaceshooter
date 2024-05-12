#pragma once

#include "../../common/vector2.h"
#include <SDL.h>
#include <functional>

namespace spaceshooter {

class Projectile {
 public:
    virtual ~Projectile();

    Vector2 get_pos();
    void set_pos(Vector2 pos);
    Vector2 get_direction();
    void set_direction(Vector2 direction);
    bool get_is_alive();
    void set_is_alive(bool is_alive);
    void set_on_death(void action());

    virtual void Tick(float delta_time) = 0;
    virtual void Render(SDL_Renderer* renderer) = 0;

 protected:
    Vector2 pos_;
    Vector2 size_;
    Vector2 direction_;
    float speed_;
    float lifetime_;
    bool is_alive_;
    SDL_Texture* texture_;

    std::function<void()> on_death_;
};

} // namespace spaceshooter
