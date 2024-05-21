#pragma once

#include "../common/vector2.h"
#include "../texture/texture.h"
#include "actor.h"

namespace spaceshooter {

class Background : public Actor {
 public:
    Background(Texture* texture, Vector2 pos, Vector2 size);

    ~Background();

    void Render(SDL_Renderer* renderer, Camera* camera) override;

 private:
    SDL_Texture* texture_;
};

} // namespace spaceshooter
