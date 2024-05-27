#pragma once

#include "../common/vector2.h"
#include "../level/level.h"
#include "../texture/texture.h"
#include "actor.h"

namespace spaceshooter {

class Asteroid : public Actor {
 public:
    Asteroid(Level* level, Texture* texture, Vector2 pos, Vector2 size, float angle,
             float rotation_speed);

    ~Asteroid();

    void Tick(const float& delta_time) override;
    void Render(SDL_Renderer* renderer, Camera* camera) override;
    void ApplyDamage(float damage) override;

 private:
    Level* level_;
    SDL_Texture* texture_;
    float angle_;
    float rotation_speed_;
    float hp_;
};

} // namespace spaceshooter
