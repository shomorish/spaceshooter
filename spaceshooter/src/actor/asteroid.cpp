#include "asteroid.h"

#include <random>

#include "../common/cast.h"
#include "player.h"

namespace spaceshooter {

Asteroid::Asteroid(Texture* texture, Vector2 pos, Vector2 size, float angle, float rotation_speed)
    : Actor{pos, size}, texture_(texture->sdl()), angle_(angle), rotation_speed_(rotation_speed),
      hp_(5.f) {
    collider_ = new Collider(pos + size.x / 2.f, size.x / 2.f, this);
}

Asteroid::Asteroid(Texture* texture) {
    std::random_device seed_gen;
    std::mt19937 engine(seed_gen());

    float scale = std::uniform_real_distribution<float>(1.f, 2.5f)(engine);
    size_ = Vector2{30.f, 30.f} * scale;

    pos_ = Vector2{std::uniform_real_distribution<float>(-800.f, 1600.f - size_.x)(engine),
                   std::uniform_real_distribution<float>(-600.f, 1200.f - size_.y)(engine)};

    texture_ = texture->sdl();

    angle_ = 0.f;

    rotation_speed_ = std::uniform_real_distribution<float>(-180.f, 180.f)(engine);

    collider_ = new Collider(pos_ + size_.x / 2.f, size_.x / 2.f, this);

    hp_ = 5.f;
}

Asteroid::~Asteroid() { texture_ = NULL; }

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
    }
}

} // namespace spaceshooter