#pragma once

#include "../common/vector2.h"
#include "../texture/texture.h"
#include "actor.h"

namespace spaceshooter {

class Asteroid : public Actor {
 public:
    Asteroid(Texture* texture, Vector2 pos, Vector2 size, float angle, float rotation_speed);
    Asteroid(Texture* texture);

    ~Asteroid();

    void Tick(const float& delta_time) override;
    void Render(SDL_Renderer* renderer) override;

 private:
    Vector2 pos_;
    Vector2 size_;
    SDL_Texture* texture_;
    float angle_;
    float rotation_speed_;
};

} // namespace spaceshooter
