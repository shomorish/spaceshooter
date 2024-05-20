#include "collider.h"

namespace spaceshooter {

Collider::Collider(float radius, Actor* actor)
    : pos_(Vector2::zero), radius_(radius), actor_(actor), space_(NULL), previous_(NULL), next_(NULL) {}

Collider::~Collider() {
    actor_ = NULL;
    space_ = NULL;
    previous_ = NULL;
    next_ = NULL;
}

float Collider::get_radius() { return radius_; }

Actor* Collider::get_actor() { return actor_; }

Space* Collider::get_space() { return space_; }

void Collider::set_space(Space* space) { space_ = space; }

Collider* Collider::get_previous() { return previous_; }

void Collider::set_previous(Collider* previous) { previous_ = previous; }

Collider* Collider::get_next() { return next_; }

void Collider::set_next(Collider* next) { next_ = next; }

Vector2 Collider::GetPos() { return pos_; }

Vector2 Collider::GetTopLeft() { return pos_ - radius_; }

Vector2 Collider::GetBottomRight() { return pos_ + radius_; }

void Collider::ExitSpace() {
    if (space_ == NULL) return;

    space_->OnRemove(this);

    if (previous_ != NULL) {
        if (next_ != NULL) {
            previous_->set_next(next_);
        } else {
            previous_->set_next(NULL);
        }
    }

    if (next_ != NULL) {
        if (previous_ != NULL) {
            next_->set_previous(previous_);
        } else {
            next_->set_previous(NULL);
        }
    }

    previous_ = NULL;
    next_ = NULL;
    space_ = NULL;
}

} // namespace spaceshooter