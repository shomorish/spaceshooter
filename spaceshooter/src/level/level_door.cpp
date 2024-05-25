#include "level_door.h"

#include "../animation/ease_in_out_sine.h"

namespace spaceshooter {

LevelDoor::LevelDoor() : texture_(NULL), alpha_(0xFF) {
    open_animation_ = new FiniteAnimation(
        new EaseInOutSine(),
        [this](float value) {
            alpha_ = (Uint8)(0xFF * value);
            if (alpha_ == 0.f) alpha_ = 1;
        },
        1.f, 1.f);

    close_animation_ = new FiniteAnimation(new EaseInOutSine(), [this](float value) {
        alpha_ = (Uint8)(0xFF * value);
        if (alpha_ == 0.f) alpha_ = 1.f;
    });
}

LevelDoor::~LevelDoor() {
    texture_ = NULL;

    if (open_animation_) {
        open_animation_->UnregistOnCompleteListener();
        delete open_animation_;
        open_animation_ = NULL;
    }

    if (close_animation_) {
        close_animation_->UnregistOnCompleteListener();
        delete close_animation_;
        close_animation_ = NULL;
    }
}

void LevelDoor::set_texture(Texture* texture) { texture_ = texture; }

void LevelDoor::Init(OnCompleteListener on_open_listener, OnCompleteListener on_close_listener) {
    open_animation_->RegistOnCompleteListener(on_open_listener);
    close_animation_->RegistOnCompleteListener(on_close_listener);
}

void LevelDoor::OpenTick(const float& delta_time) { open_animation_->Tick(delta_time); }

void LevelDoor::ResetOpenAnimation() { open_animation_->Reset(); }

void LevelDoor::CloseTick(const float& delta_time) { close_animation_->Tick(delta_time); }

void LevelDoor::ResetCloseAnimation() { close_animation_->Reset(); }

void LevelDoor::Render(SDL_Renderer* renderer) {
    SDL_SetTextureAlphaMod(texture_->sdl(), alpha_);
    SDL_RenderCopy(renderer, texture_->sdl(), NULL, NULL);
}

} // namespace spaceshooter