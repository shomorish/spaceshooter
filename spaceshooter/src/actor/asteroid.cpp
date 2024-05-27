#include "asteroid.h"

#include <random>

#include "../common/cast.h"
#include "../effect/explosion.h"
#include "player.h"

namespace spaceshooter {

Asteroid::Asteroid(Level* level, Texture* texture, Vector2 pos, Vector2 size, float angle,
                   float rotation_speed)
    : Actor{pos, size}, level_(level), texture_(texture->sdl()), angle_(angle),
      rotation_speed_(rotation_speed), hp_(5.f) {
    collider_ = new Collider(pos + size.x / 2.f, size.x / 2.f, this);
}

Asteroid::~Asteroid() {
    level_ = NULL;
    texture_ = NULL;
}

void Asteroid::Tick(const float& delta_time) { angle_ += rotation_speed_ * delta_time; }

void Asteroid::Render(SDL_Renderer* renderer, Camera* camera) {
    Vector2 pos;
    bool result = camera->ConvertToWindowCoords(pos_, &pos);
    if (result) {
        SDL_FRect rect{pos.x, pos.y, size_.x, size_.y};
        SDL_RenderCopyExF(renderer, texture_, NULL, &rect, angle_, NULL, SDL_FLIP_NONE);
    }
}

void Asteroid::ApplyDamage(float damage) {
    hp_ -= damage;
    if (hp_ <= 0.f) {
        Destroy();
        level_->AddActor(new Explosion(
            pos_, size_, level_->get_asset_manager()->GetSpriteSheet(AssetKey::kExplosion1)));
    }
}

} // namespace spaceshooter