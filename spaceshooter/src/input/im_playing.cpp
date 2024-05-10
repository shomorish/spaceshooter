#include "../../../include/input/im_playing.h"
#include "../../../include/input/action/ia_fire.h"
#include "../../../include/input/action/ia_move.h"

namespace spaceshooter {

std::vector<InputAction*> IM_Playing::GenerateInputAction() {
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
        actions_.push_back(new IA_Move(move));
    }

    // 攻撃アクション
    if (key_state_[SDL_SCANCODE_SPACE] == 1) {
        actions_.push_back(new IA_Fire(true));
    }

    return actions_;
}

} // namespace spaceshooter