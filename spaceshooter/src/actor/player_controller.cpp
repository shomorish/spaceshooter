#include "player_controller.h"

#include <cmath>

#include "../common/matrix2x2.h"
#include "../common/vector3.h"

namespace spaceshooter {

PlayerController::PlayerController(Level* level) : level_(level) {}

PlayerController::~PlayerController() { level_ = NULL; }

void PlayerController::Tick(const std::vector<InputAction>& actions, const float& delta_time) {
    if (character_ != NULL) {
        CountdownFiringInterval(delta_time);
        // 前進
        Move(Range{0.f, (float)level_->get_window()->get_width()},
             Range{0.f, (float)level_->get_window()->get_height()}, delta_time);
        for (auto iter = actions.begin(); iter != actions.end(); iter++) {
            if (iter->type == kRotate) {
                // 回転
                InputAction input_action = *iter;
                Rotate(input_action.vec2_value.Normalize(), delta_time);
            } else if (iter->type == kFire) {
                // 攻撃
                if (CanFire()) {
                    level_->AddActor(Fire());
                }
            }
        }
    }
}

void PlayerController::Move(Range x_limit, Range y_limit, float delta_time) {
    Player* player = (Player*)character_;
    Vector2 pos = player->get_pos() + player->get_direction() * player->get_speed() * delta_time;
    // 画面外に出ないように位置を補正
    Vector2 size = player->get_size();
    if (pos.x < 0.f) {
        pos.x = 0.f;
    } else if (pos.x >= x_limit.max - size.x) {
        pos.x = x_limit.max - size.x;
    }
    if (pos.y < 0.f) {
        pos.y = 0.f;
    } else if (pos.y >= y_limit.max - size.y) {
        pos.y = y_limit.max - size.y;
    }
    player->set_pos(pos);

    player->get_weapon()->set_pos(pos + size / 2.f);
}

void PlayerController::Rotate(const Vector2& direction, float delta_time) {
    Player* player = (Player*)character_;
    Vector2 current_direction = player->get_direction();
    // 回転量（単位は度数法）の計算
    float radian = std::acosf(current_direction.Dot(direction));
    float angle = radian * 180.f / (float)M_PI;
    float rotation_amount = player->get_rotation_speed() * delta_time;
    if (rotation_amount > angle) {
        rotation_amount = angle;
    }

    // 回転の方向を外積で求める
    Vector3 a = Vector3{current_direction.x, current_direction.y, 0.f};
    Vector3 b = Vector3{direction.x, direction.y, 0.f};
    Vector3 cross = a.Cross(b);
    if (cross.z > 0.f) {
        // 右回りで回転
        player->set_angle(player->get_angle() + rotation_amount);
        Matrix2x2 m(std::cosf(rotation_amount * (float)M_PI / 180.f),
                    -std::sinf(rotation_amount * (float)M_PI / 180.f),
                    std::sinf(rotation_amount * (float)M_PI / 180.f),
                    std::cosf(rotation_amount * (float)M_PI / 180.f));
        // 誤差？で単位ベクトルにならないので、正規化して単位ベクトルにする
        player->set_direction((m * current_direction).Normalize());
    } else {
        // 左回りで回転
        player->set_angle(player->get_angle() - rotation_amount);
        Matrix2x2 m(std::cosf(rotation_amount * (float)M_PI / 180.f),
                    std::sinf(rotation_amount * (float)M_PI / 180.f),
                    -std::sinf(rotation_amount * (float)M_PI / 180.f),
                    std::cosf(rotation_amount * (float)M_PI / 180.f));
        // 誤差？で単位ベクトルにならないので、正規化して単位ベクトルにする
        player->set_direction((m * current_direction).Normalize());
    }
}

bool PlayerController::CanFire() { return ((Player*)character_)->get_weapon()->CanFire(); }

void PlayerController::CountdownFiringInterval(float delta_time) {
    ((Player*)character_)->get_weapon()->CountdownInterval(delta_time);
}

Bullet* PlayerController::Fire() { return ((Player*)character_)->get_weapon()->Fire(); }

} // namespace spaceshooter