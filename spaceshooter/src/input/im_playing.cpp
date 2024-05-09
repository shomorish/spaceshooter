#include "../../../include/input/im_playing.h"
#include "../../../include/input/action/ia_fire.h"
#include "../../../include/input/action/ia_move.h"

namespace spaceshooter {

void IM_Playing::HandleKeyboardState() {
    // 上下 
    if (keyboard_state_array_[SDL_SCANCODE_W] || keyboard_state_array_[SDL_SCANCODE_UP]) {
        actions_.insert(new IA_Move(Vector2{0.f, -1.f}));
    } else if (keyboard_state_array_[SDL_SCANCODE_S] || keyboard_state_array_[SDL_SCANCODE_DOWN]) {
        actions_.insert(new IA_Move(Vector2{0.f, 1.f}));
    }
    
    // 左右
    if (keyboard_state_array_[SDL_SCANCODE_A] || keyboard_state_array_[SDL_SCANCODE_LEFT]) {
        actions_.insert(new IA_Move(Vector2{-1.f, 0.f}));
    } else if (keyboard_state_array_[SDL_SCANCODE_D] || keyboard_state_array_[SDL_SCANCODE_RIGHT]) {
        actions_.insert(new IA_Move(Vector2{1.f, 0.f}));
    }

    // 攻撃
    if (keyboard_state_array_[SDL_SCANCODE_SPACE]) {
        actions_.insert(new IA_Fire(true));
    }
}

} // namespace spaceshooter