#include "stage1.h"

#include <random>

#include "../actor/asteroid.h"
#include "../actor/background.h"
#include "../actor/straight_bullet.h"
#include "../input/im_playing.h"

namespace spaceshooter {

Stage1::Stage1(Window* window, Renderer* renderer, AssetManager* asset_manager,
               InputMapping** input_mapping)
    : Level{window, renderer, asset_manager, input_mapping}, player_controller_(NULL) {

    *input_mapping_ = new IM_Playing();

    actors_.push_back(new Background(asset_manager->GetTexture(AssetKey::kBackground),
                                     Vector2{-800.f, -600.f}, Vector2{1024.f * 4.f, 512.f * 4.f}));

    player_controller_ = new PlayerController(this);

    std::random_device seed_gen;
    std::mt19937 engine(seed_gen());
    for (int i = 0; i < 80; i++) {
        float scale = std::uniform_real_distribution<float>(1.f, 2.5f)(engine);
        Vector2 size = Vector2{30.f, 30.f} * scale;

        Vector2 pos =
            Vector2{std::uniform_real_distribution<float>(-800.f, 1600.f - size.x)(engine),
                    std::uniform_real_distribution<float>(-600.f, 1200.f - size.y)(engine)};

        Texture* texture = asset_manager_->GetTexture(kSpin00);

        float angle = 0.f;

        float rotation_speed = std::uniform_real_distribution<float>(-180.f, 180.f)(engine);

        actors_.push_back(new Asteroid(texture, pos, size, angle, rotation_speed));
    }
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