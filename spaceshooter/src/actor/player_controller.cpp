#include "player_controller.h"

#include <cmath>

#include "../common/matrix2x2.h"
#include "../common/vector3.h"

namespace spaceshooter {

PlayerController::PlayerController(Level* level, Range area_x_range, Range area_y_range)
    : level_(level), area_x_range_(area_x_range), area_y_range_(area_y_range) {}

PlayerController::~PlayerController() {
    level_ = NULL;
    character_ = NULL;
}

Collider* PlayerController::get_collider() { return character_->get_collider(); }

void PlayerController::Tick(const InputActionContainer* action_container, const float& delta_time) {
    if (character_ != NULL) {
        CountdownFiringInterval(delta_time);

        // 前進
        Move(delta_time);

        if (action_container) {
            // 回転
            auto rotate_action = action_container->GetActionOrNull(InputActionType::kRotate);
            if (rotate_action) Rotate(rotate_action->vec2_value.Normalize(), delta_time);

            // 攻撃
            auto fire_action = action_container->GetActionOrNull(InputActionType::kFire);
            if (fire_action && CanFire()) level_->AddActor(Fire());
        }
    }
}

void PlayerController::Render(SDL_Renderer* renderer, Camera* camera) {
    if (character_ != NULL) {
        character_->Render(renderer, camera);
    }
}

void PlayerController::Attach(Player* player) {
    character_ = player;
    level_->get_camera()->set_pos(character_->get_pos());
}

bool PlayerController::HasCollider() {
    if (character_ == NULL) return false;
    return character_->get_collider();
}

void PlayerController::DestroyCharacter() { character_ = NULL; }

float PlayerController::GetPlayerHp() {
    if (character_) {
        return ((Player*)character_)->get_hp();
    }
    return 0.f;
}

void PlayerController::Move(float delta_time) {
    Player* player = (Player*)character_;
    Vector2 pos = player->get_pos() + player->get_direction() * player->get_speed() * delta_time;
    // 移動可能範囲外に出ないように位置を補正
    Vector2 size = player->get_size();
    Range x_movable_range =
        Range{area_x_range_.min + size.x / 2.f, area_x_range_.max - size.x / 2.f};
    Range y_movable_range =
        Range{area_y_range_.min + size.y / 2.f, area_y_range_.max - size.y / 2.f};
    if (pos.x < x_movable_range.min) {
        pos.x = x_movable_range.min;
    } else if (pos.x > x_movable_range.max) {
        pos.x = x_movable_range.max;
    }
    if (pos.y < y_movable_range.min) {
        pos.y = y_movable_range.min;
    } else if (pos.y > y_movable_range.max) {
        pos.y = y_movable_range.max;
    }
    player->set_pos(pos);

    level_->get_camera()->set_pos(pos);
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

    player->get_weapon()->set_direction(player->get_direction());
}

bool PlayerController::CanFire() { return ((Player*)character_)->get_weapon()->CanFire(); }

void PlayerController::CountdownFiringInterval(float delta_time) {
    ((Player*)character_)->get_weapon()->CountdownInterval(delta_time);
}

Bullet* PlayerController::Fire() { return ((Player*)character_)->get_weapon()->Fire(); }

} // namespace spaceshooter