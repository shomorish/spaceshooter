#include "bullet_container.h"

namespace spaceshooter {

BulletContainer::BulletContainer() {}

BulletContainer::~BulletContainer() { ClearAllBullets(); }

void BulletContainer::TickEachBullet(float delta_time) {
    auto iter = player_bullets_.begin();
    while (iter != player_bullets_.end()) {
        auto bullet = *iter;
        bullet->Tick(delta_time);
        if (!bullet->get_is_alive()) {
            // 弾が死んだらvectorから削除
            delete bullet;
            iter = player_bullets_.erase(iter);
        } else {
            iter++;
        }
    }
}

void BulletContainer::RenderEachBullet(SDL_Renderer* renderer) {
    for (auto iter = player_bullets_.begin(); iter != player_bullets_.end(); iter++) {
        auto bullet = *iter;
        // 弾が死んでいたら以降の処理はスキップ
        if (!bullet->get_is_alive()) continue;
        bullet->Render(renderer);
    }
}

void BulletContainer::AddPlayerBullet(Bullet* bullet) { player_bullets_.push_back(bullet); }

void BulletContainer::ClearPlayerBullets() {
    for (auto iter = player_bullets_.begin(); iter != player_bullets_.end(); iter++) {
        delete *iter;
    }
    player_bullets_.clear();
}

void BulletContainer::ClearAllBullets() { ClearPlayerBullets(); }

} // namespace spaceshooter