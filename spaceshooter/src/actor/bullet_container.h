#pragma once

#include <SDL.h>
#include <vector>

#include "bullet.h"

namespace spaceshooter {

class BulletContainer {
 public:
    BulletContainer();

    ~BulletContainer();

    void TickEachBullet(float delta_time);
    void RenderEachBullet(SDL_Renderer* renderer);
    void AddPlayerBullet(Bullet* bullet);
    void ClearPlayerBullets();
    void ClearAllBullets();

 private:
    std::vector<Bullet*> player_bullets_;
};

} // namespace spaceshooter
