#include "stage1.h"

#include "../actor/straight_bullet.h"
#include "../input/im_playing.h"

namespace spaceshooter {

Stage1::Stage1(Window* window, Renderer* renderer, AssetManager* asset_manager,
               InputMapping** input_mapping)
    : Level{window, renderer, asset_manager, input_mapping}, player_controller_(NULL) {

    *input_mapping_ = new IM_Playing();

    player_controller_ = new PlayerController(this);
}

Stage1::~Stage1() {
    if (player_controller_ != NULL) {
        delete player_controller_;
        player_controller_ = NULL;
    }
}

void Stage1::Tick(std::vector<InputAction> actions, float delta_time) {
    // 削除マークが付いたアクタを削除
    DeleteActorIfDestroyed();

    // 衝突判定

    for (auto iter = actors_.begin(); iter != actors_.end(); iter++) {
        (*iter)->Tick(delta_time);
    }

    /**
     * プレイヤーの更新処理
     */
    player_controller_->Tick(actions, delta_time);

    // 敵更新
}

void Stage1::Render() {
    for (auto iter = actors_.begin(); iter < actors_.end(); iter++) {
        (*iter)->Render(renderer_->sdl());
    }
    player_controller_->get_character()->Render(renderer_->sdl());
}

} // namespace spaceshooter