#include "../../../include/actor/projectile/projectile.h"

namespace spaceshooter {

Projectile::~Projectile() {}

Vector2 Projectile::get_pos() { return pos_; }

void Projectile::set_pos(Vector2 pos) { pos_ = pos; }

void Projectile::set_size(Vector2 size) { size_ = size; };

Vector2 Projectile::get_direction() { return direction_; }

void Projectile::set_direction(Vector2 direction) { direction_ = direction; }

void Projectile::set_speed(float speed) { speed_ = speed; };

void Projectile::set_lifetime(float lifetime) { lifetime_ = lifetime; };

bool Projectile::get_is_alive() { return is_alive_; }

void Projectile::set_is_alive(bool is_alive) { is_alive_ = is_alive; }

void Projectile::set_texture(SDL_Texture* texture) { texture_ = texture; };

} // namespace spaceshooter