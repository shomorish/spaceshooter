#pragma once

#include "../../common/vector2.h"
#include "projectile.h"
#include <SDL.h>
#include <functional>

namespace spaceshooter {

class StraightBullet : public Projectile {
 public:
    StraightBullet();
    StraightBullet(Vector2 pos, Vector2 size, Vector2 direction, float speed, float lifetime,
                   SDL_Texture* texture, bool is_alive = true);
    StraightBullet(const StraightBullet&) = delete;

    ~StraightBullet();

    void Tick(float delta_time) override;
    void Render(SDL_Renderer* renderer) override;

    StraightBullet& operator=(const StraightBullet&) = delete;
};

} // namespace spaceshooter
