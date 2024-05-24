#include "rush_ai_controller.h"

#include <cmath>

#include "../common/matrix2x2.h"
#include "../common/vector3.h"
#include "alien.h"

namespace spaceshooter {

RushAiController::RushAiController(Level* level, Vector2 pos, Character** target,
                                   EnemyCounter* enemy_counter) {
    character_ = new Alien(this, level->get_asset_manager()->GetTexture(AssetKey::kAlien1), pos);
    target_ = target;
    enemy_counter_ = enemy_counter;
}

RushAiController::~RushAiController() {
    enemy_counter_ = NULL;
    target_ = NULL;

    if (character_) {
        delete character_;
        character_ = NULL;
    }
}

Collider* RushAiController::get_collider() { return character_->get_collider(); }

void RushAiController::Tick(const float& delta_time) {
    if (*target_ != NULL) {
        Rotate(delta_time);
        Move(delta_time);
    }
}

void RushAiController::Render(SDL_Renderer* renderer, Camera* camera) {
    character_->Render(renderer, camera);
}

bool RushAiController::HasCollider() { return character_->get_collider() != NULL; }

void RushAiController::DestroyCharacter() {
    Destroy();
    enemy_counter_->num_of_destroy_enemies++;
}

void RushAiController::Move(const float& delta_time) {
    Alien* alien = (Alien*)character_;
    Vector2 pos = alien->get_pos() + alien->get_direction() * alien->get_speed() * delta_time;
    alien->set_pos(pos);
    alien->get_collider()->set_pos(pos);
}

void RushAiController::Rotate(const float& delta_time) {
    Alien* alien = (Alien*)character_;
    Vector2 current_direction = alien->get_direction();
    Vector2 target_direction = ((*target_)->get_pos() - alien->get_pos()).Normalize();
    // 回転量（単位は度数法）の計算
    float radian = std::acosf(current_direction.Dot(target_direction));
    float angle = radian * 180.f / (float)M_PI;
    float rotation_amount = alien->get_rotation_speed() * delta_time;
    if (rotation_amount > angle) {
        rotation_amount = angle;
    }

    // 回転の方向を外積で求める
    Vector3 a = Vector3{current_direction.x, current_direction.y, 0.f};
    Vector3 b = Vector3{target_direction.x, target_direction.y, 0.f};
    Vector3 cross = a.Cross(b);
    if (cross.z > 0.f) {
        // 右回りで回転
        Matrix2x2 m(std::cosf(rotation_amount * (float)M_PI / 180.f),
                    -std::sinf(rotation_amount * (float)M_PI / 180.f),
                    std::sinf(rotation_amount * (float)M_PI / 180.f),
                    std::cosf(rotation_amount * (float)M_PI / 180.f));
        // 誤差？で単位ベクトルにならないので、正規化して単位ベクトルにする
        alien->set_direction((m * current_direction).Normalize());
    } else {
        // 左回りで回転
        Matrix2x2 m(std::cosf(rotation_amount * (float)M_PI / 180.f),
                    std::sinf(rotation_amount * (float)M_PI / 180.f),
                    -std::sinf(rotation_amount * (float)M_PI / 180.f),
                    std::cosf(rotation_amount * (float)M_PI / 180.f));
        // 誤差？で単位ベクトルにならないので、正規化して単位ベクトルにする
        alien->set_direction((m * current_direction).Normalize());
    }
}

} // namespace spaceshooter