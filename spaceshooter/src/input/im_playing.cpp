#include "im_playing.h"

namespace spaceshooter {

std::vector<InputAction> IM_Playing::GenerateInputAction() {
    std::vector<InputAction> actions;
    auto move = Vector2({0.f, 0.f});
    // 上移動
    if (key_state_[SDL_SCANCODE_W] > 0 || key_state_[SDL_SCANCODE_UP] > 0) {
        move.y -= 1.f;
    }
    // 下移動
    if (key_state_[SDL_SCANCODE_S] > 0 || key_state_[SDL_SCANCODE_DOWN] > 0) {
        move.y += 1.f;
    }
    // 左移動
    if (key_state_[SDL_SCANCODE_A] > 0 || key_state_[SDL_SCANCODE_LEFT] > 0) {
        move.x -= 1.f;
    }
    // 右移動
    if (key_state_[SDL_SCANCODE_D] > 0 || key_state_[SDL_SCANCODE_RIGHT] > 0) {
        move.x += 1.f;
    }
    // 移動アクション
    if (move.x != 0.f || move.y != 0.f) {
        auto action = InputAction{kMove};
        action.vec2_value = move;
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