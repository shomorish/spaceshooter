#include "bullet.h"

namespace spaceshooter {

Bullet::~Bullet() {}

bool Bullet::get_is_alive() { return is_alive_; }

void Bullet::set_is_alive(bool is_alive) { is_alive_ = is_alive; }

} // namespace spaceshooter