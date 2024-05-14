#pragma once

#include <SDL.h>

namespace spaceshooter {

class Actor {
 public:
    Actor();

    virtual ~Actor();

    bool get_is_destroyed();

    virtual void Tick(const float& delta_time);
    virtual void Render(SDL_Renderer* renderer);
    void Destroy();

 protected:
    bool is_destroyed_;
};

} // namespace spaceshooter
