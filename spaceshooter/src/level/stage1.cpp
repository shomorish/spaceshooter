#include "../../include/level/stage1.h"

#include "../../include/input/im_playing.h"

namespace spaceshooter {

Stage1::Stage1(GameContainer* game_container, AssetManager* asset_manager,
               InputMapping** input_mapping)
    : game_container_(game_container), asset_manager_(asset_manager), input_mapping_(input_mapping),
      player_(NULL) {
    *input_mapping_ = new IM_Playing();
    player_ = new Player(game_container, asset_manager_->GetTexture(AssetKey::kSpaceship1Blue));
}

Stage1::~Stage1() {
    game_container_ = NULL;

    asset_manager_ = NULL;

    if (*input_mapping_ != NULL) {
        delete *input_mapping_;
        *input_mapping_ = NULL;
        input_mapping_ = NULL;
    }

    if (player_ != NULL) {
        delete player_;
        player_ = NULL;
    }
}

void Stage1::Tick(std::vector<InputAction*> actions, float delta_time) {
    // プレイヤー衝突判定

    // 敵衝突判定

    // プレイヤー移動
    player_->Tick(actions, delta_time);

    // プレイヤー弾移動

    // 敵移動

    // 敵弾移動

    // プレイヤー攻撃

    // 敵攻撃
}

void Stage1::Render() { player_->Render(); }

} // namespace spaceshooter