#include "stage1.h"

#include "../input/im_playing.h"

namespace spaceshooter {

Stage1::Stage1(Window* window, Renderer* renderer, AssetManager* asset_manager,
               InputMapping** input_mapping)
    : Level{window, renderer, asset_manager, input_mapping}, player_(NULL) {
    *input_mapping_ = new IM_Playing();
    player_ = new Player(asset_manager_->GetTexture(AssetKey::kSpaceship1Blue));
}

Stage1::~Stage1() {
    if (player_ != NULL) {
        delete player_;
        player_ = NULL;
    }
}

void Stage1::Tick(std::vector<InputAction> actions, float delta_time) {
    // プレイヤー衝突判定

    // 敵衝突判定

    for (auto iter = actions.begin(); iter != actions.end(); iter++) {
        if (iter->type == kMove) {
            // プレイヤー移動
            player_->Move(iter->vec2_value.Normalize(), Range{0.f, (float)window_->get_width()},
                          Range{0.f, (float)window_->get_height()}, delta_time);
        } else if (iter->type == kFire) {
            // プレイヤー攻撃
            printf("kFire\n");
        }
    }

    // プレイヤー弾移動

    // 敵移動

    // 敵弾移動

    // 敵攻撃
}

void Stage1::Render() { player_->Render(renderer_->sdl()); }

} // namespace spaceshooter