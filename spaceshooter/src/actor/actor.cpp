#include "actor.h"

namespace spaceshooter {

Actor::Actor() : pos_(Vector2::zero), size_(Vector2::zero), is_destroyed_(false) {}

Actor::Actor(Vector2 pos, Vector2 size) : pos_(pos), size_(size), is_destroyed_(false) {}

Actor::~Actor() {}

Vector2 Actor::get_pos() { return pos_; }

void Actor::set_pos(Vector2 pos) { pos_ = pos; }

Vector2 Actor::get_size() { return size_; }

void Actor::set_size(Vector2 size) { size_ = size; }

bool Actor::get_is_destroyed() { return is_destroyed_; }

void Actor::Tick(const float& delta_time) {}

void Actor::Render(SDL_Renderer* renderer) {}

void Actor::Destroy() { is_destroyed_ = true; }

} // namespace spaceshooter