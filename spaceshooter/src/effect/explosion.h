#pragma once

#include <SDL.h>

#include "../actor/actor.h"
#include "../actor/camera.h"
#include "../common/vector2.h"
#include "../texture/sprite_sheet_texture.h"

namespace spaceshooter {

class Explosion : public Actor {
 public:
    Explosion(Vector2 pos, Vector2 size, SpriteSheetTexture* texture);

    ~Explosion();

    void Tick(const float& delta_time) override;
    void Render(SDL_Renderer* renderer, Camera* camera) override;

 private:
    Vector2 pos_;
    Vector2 size_;
    SpriteSheetTexture* texture_;
    int sprite_index_;
    float update_duration_;
    float elapsed_time_;
};

} // namespace spaceshooter
