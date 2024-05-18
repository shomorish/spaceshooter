#pragma once

#include <SDL.h>

#include "../common/vector2.h"

namespace spaceshooter {

class Actor {
 public:
    Actor();
    Actor(Vector2 pos, Vector2 size);

    virtual ~Actor();

    Vector2 get_pos();
    void set_pos(Vector2 pos);
    Vector2 get_size();
    void set_size(Vector2 size);
    bool get_is_destroyed();

    virtual void Tick(const float& delta_time);
    virtual void Render(SDL_Renderer* renderer);
    void Destroy();

 protected:
    Vector2 pos_;
    Vector2 size_;
    bool is_destroyed_;
};

} // namespace spaceshooter
