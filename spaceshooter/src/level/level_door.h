#pragma once

#include <SDL.h>

#include "../animation/finite_animation.h"
#include "../texture/texture.h"

namespace spaceshooter {

class LevelDoor {
 public:
    LevelDoor();

    ~LevelDoor();

    void set_texture(Texture* texture);

    void Init(OnCompleteListener on_open_listener, OnCompleteListener on_close_listener);
    void OpenTick(const float& delta_time);
    void ResetOpenAnimation();
    void CloseTick(const float& delta_time);
    void ResetCloseAnimation();
    void Render(SDL_Renderer* renderer);

 private:
    Texture* texture_;
    Uint8 alpha_;
    FiniteAnimation* open_animation_;
    FiniteAnimation* close_animation_;
};

} // namespace spaceshooter
