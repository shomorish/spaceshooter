#pragma once

#include <SDL.h>

#include "../common/color.h"
#include "bullet.h"

namespace spaceshooter {

class StraightBullet : public Bullet {
 public:
    StraightBullet(Vector2 pos, Vector2 size, Vector2 direction, float speed, float lifetime,
                   bool is_alive, Color color);

    ~StraightBullet();

    void Tick(const float& delta_time) override;
    void Render(SDL_Renderer* renderer, Camera* camera) override;

 private:
    Color color_;
};

} // namespace spaceshooter
