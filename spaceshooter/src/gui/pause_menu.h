#pragma once

#include <SDL.h>

#include "../animation/finite_animation.h"
#include "../input/input_action_container.h"
#include "../texture/texture.h"
#include "image_view.h"
#include "text_view.h"

namespace spaceshooter {

enum class PauseMenuAnimationState {
    kOpen,
    kClose,
    kNone,
};

enum class PauseMenuItem {
    kNo,
    kYes,
};

class PauseMenu {
 public:
    PauseMenu();

    ~PauseMenu();

    void Init(Texture* pause_menu_texture, Texture* cursor_texture, Window* window,
              SDL_Renderer* renderer);
    void Open();
    void Close();
    void MoveCursorUp();
    void MoveCursourDown();
    PauseMenuItem Determine();
    void Render(SDL_Renderer* renderer);
    bool IsOpen();
    bool IsDuringAnimation();
    void Animation(const float& delta_time);

 private:
    bool is_open_;
    PauseMenuAnimationState animation_state_;
    PauseMenuItem cursor_;
    FiniteAnimation* open_animation_;
    FiniteAnimation* close_animation_;
    ImageView frame_image_view_;
    ImageView cursor_image_view_;
    TextView message_text_view_;
    TextView yes_text_view_;
    TextView no_text_view_;
};

} // namespace spaceshooter
