#include "../../include/level/stage1.h"

#include "../../include/input/im_playing.h"

namespace spaceshooter {

Stage1::Stage1(GameContainer* game_container, InputMapping** input_mapping)
    : game_container_(game_container), input_mapping_(input_mapping), player_(NULL) {
    *input_mapping_ = new IM_Playing();
    player_ = new Player("assets/spaceship_1_blue.png", 64, 64, 0, 0, game_container_);
}

Stage1::~Stage1() {
    game_container_ = NULL;

    if (*input_mapping_ != NULL) {
        delete *input_mapping_;
        input_mapping_ = NULL;
    }

    if (player_ != NULL) {
        delete player_;
        player_ = NULL;
    }
}

void Stage1::Tick(std::vector<InputAction*> actions) {
    // プレイヤー衝突判定

    // 敵衝突判定

    // プレイヤー移動

    // プレイヤー弾移動

    // 敵移動

    // 敵弾移動

    // プレイヤー攻撃

    // 敵攻撃
}

void Stage1::Render() { player_->Render(); }

} // namespace spaceshooter