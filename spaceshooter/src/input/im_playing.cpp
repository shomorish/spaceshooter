#include "im_playing.h"

namespace spaceshooter {

std::vector<InputAction> IM_Playing::GenerateInputAction() {
    std::vector<InputAction> actions;

    auto rotate = Vector2::zero;
    // 上へ回転
    if (key_state_[SDL_SCANCODE_W] > 0 || key_state_[SDL_SCANCODE_UP] > 0) {
        rotate.y -= 1.f;
    }
    // 下へ回転
    if (key_state_[SDL_SCANCODE_S] > 0 || key_state_[SDL_SCANCODE_DOWN] > 0) {
        rotate.y += 1.f;
    }
    // 左へ回転
    if (key_state_[SDL_SCANCODE_A] > 0 || key_state_[SDL_SCANCODE_LEFT] > 0) {
        rotate.x -= 1.f;
    }
    // 右へ回転
    if (key_state_[SDL_SCANCODE_D] > 0 || key_state_[SDL_SCANCODE_RIGHT] > 0) {
        rotate.x += 1.f;
    }
    // 回転アクション
    if (rotate.x != 0.f || rotate.y != 0) {
        auto action = InputAction{kRotate};
        action.vec2_value = rotate;
        actions.push_back(action);
    }

    // 攻撃アクション
    if (key_state_[SDL_SCANCODE_SPACE] > 0 || mouse_button_state_[SDL_BUTTON_LEFT] > 0) {
        auto action = InputAction{kFire};
        action.b_value = true;
        actions.push_back(action);
    }

    return actions;
}

} // namespace spaceshooter