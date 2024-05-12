#include "../../../include/actor/projectile/straight_bullet.h"

namespace spaceshooter {

StraightBullet::StraightBullet(Vector2 pos, Vector2 direction, float speed, float lifetime,
                               SDL_Texture* texture, bool is_alive)
    : pos_(pos), direction_(direction), speed_(speed), lifetime_(lifetime), is_alive_(is_alive),
      texture_(texture), on_death_(NULL) {}

StraightBullet::~StraightBullet() {
    texture_ = NULL;
    on_death_ = NULL;
}

bool StraightBullet::get_is_alive() { return is_alive_; }

void StraightBullet::set_is_alive(bool is_alive) { is_alive_ = is_alive; }

void StraightBullet::set_on_death(void action()) { on_death_ = action; }

void StraightBullet::Tick(float delta_time) {
    pos_ += direction_ * speed_ * delta_time;
    lifetime_ -= delta_time;
    if (lifetime_ <= 0) {
        is_alive_ = false;
        if (on_death_ != NULL) {
            on_death_();
        }
    }
}

} // namespace spaceshooter