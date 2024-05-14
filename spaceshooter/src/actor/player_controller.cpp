#include "player_controller.h"

namespace spaceshooter {

PlayerController::PlayerController(Level* level, Window* window)
    : level_(level), window_(window), player_(NULL) {}

PlayerController::~PlayerController() {
    level_ = NULL;
    window_ = NULL;
    player_ = NULL;
}

void PlayerController::Tick(const std::vector<InputAction>& actions, const float& delta_time) {
    if (*player_ != NULL) {
        auto player = *player_;
        player->CountdownFiringInterval(delta_time);
        // 前進
        player->Move(Range{0.f, (float)window_->get_width()},
                     Range{0.f, (float)window_->get_height()}, delta_time);
        for (auto iter = actions.begin(); iter != actions.end(); iter++) {
            if (iter->type == kRotate) {
                // 回転
                InputAction input_action = *iter;
                player->Rotate(input_action.vec2_value.Normalize(), delta_time);
            } else if (iter->type == kFire) {
                // 攻撃
                if (player->CanFire()) {
                    level_->AddActor(player->Fire());
                }
            }
        }
    }
}

void PlayerController::AttachPlayer(Player** player) { player_ = player; }

void PlayerController::DetachPlayer() { player_ = NULL; }

} // namespace spaceshooter