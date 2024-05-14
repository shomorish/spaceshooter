#include "stage1.h"

#include "../actor/straight_bullet.h"
#include "../input/im_playing.h"

namespace spaceshooter {

Stage1::Stage1(Window* window, Renderer* renderer, AssetManager* asset_manager,
               InputMapping** input_mapping)
    : Level{window, renderer, asset_manager, input_mapping}, player_(NULL),
      bullet_container_(NULL) {
    *input_mapping_ = new IM_Playing();
    player_ = new Player(asset_manager_->GetTexture(AssetKey::kSpaceship1Blue));
    bullet_container_ = new BulletContainer();
}

Stage1::~Stage1() {
    if (player_ != NULL) {
        delete player_;
        player_ = NULL;
    }

    if (bullet_container_ != NULL) {
        delete bullet_container_;
        bullet_container_ = NULL;
    }
}

void Stage1::Tick(std::vector<InputAction> actions, float delta_time) {
    // 衝突判定

    // 弾の更新
    bullet_container_->TickEachBullet(delta_time);

    /**
     * プレイヤーの更新処理
     */
    player_->CountdownFiringInterval(delta_time);
    // 前進
    player_->Move(Range{0.f, (float)window_->get_width()}, Range{0.f, (float)window_->get_height()},
                  delta_time);
    for (auto iter = actions.begin(); iter != actions.end(); iter++) {
        if (iter->type == kRotate) {
            // 回転
            player_->Rotate(iter->vec2_value.Normalize(), delta_time);
        } else if (iter->type == kFire) {
            // 攻撃
            if (player_->CanFire()) {
                bullet_container_->AddPlayerBullet(player_->Fire());
            }
        }
    }

    // 敵更新
}

void Stage1::Render() {
    bullet_container_->RenderEachBullet(renderer_->sdl());
    player_->Render(renderer_->sdl());
}

} // namespace spaceshooter