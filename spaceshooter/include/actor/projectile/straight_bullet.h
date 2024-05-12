#pragma once

#include "../../common/vector2.h"
#include <SDL.h>
#include <functional>

namespace spaceshooter {

class StraightBullet {
 private:
    Vector2 pos_;
    Vector2 direction_;
    float speed_;
    float lifetime_;
    bool is_alive_;
    SDL_Texture* texture_;

    std::function<void()> on_death_;

 public:
    StraightBullet(Vector2 pos, Vector2 direction, float speed, float lifetime,
                   SDL_Texture* texture, bool is_alive = true);
    StraightBullet(const StraightBullet&) = delete;

    ~StraightBullet();

    bool get_is_alive();
    void set_is_alive(bool is_alive);

    void set_on_death(void action());

    void Tick(float delta_time);

    StraightBullet& operator=(const StraightBullet&) = delete;
};

} // namespace spaceshooter
