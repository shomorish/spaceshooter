#include "space.h"

namespace spaceshooter {

Space::Space() : first_(NULL) {}

Space::~Space() {
    if (first_ != NULL) {
        ResetLink(first_);
    }
}

Collider* Space::get_first() { return first_; }

void Space::ResetLink(Collider* collider) {
    if (collider->get_next() != 0) {
        ResetLink(collider->get_next());
    }
    collider = 0;
}

void Space::Add(Collider* collider) {
    if (collider == first_) return;

    if (first_ == NULL) {
        first_ = collider;
    } else {
        collider->set_next(first_);
        first_->set_previous(collider);
        first_ = collider;
    }

    collider->set_space(this);
}

void Space::OnRemove(Collider* collider) {
    if (collider == first_) {
        if (collider->get_next() != NULL) {
            first_ = collider->get_next();
        }
    }
}

} // namespace spaceshooter