#include "actor.h"

namespace spaceshooter {

Actor::Actor() : is_destroyed_(false) {}

Actor::~Actor() {}

bool Actor::get_is_destroyed() { return is_destroyed_; }

void Actor::Tick(const float& delta_time) {}

void Actor::Render(SDL_Renderer* renderer) {}

void Actor::Destroy() { is_destroyed_ = true; }

} // namespace spaceshooter