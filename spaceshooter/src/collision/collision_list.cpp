#include "collision_list.h"

namespace spaceshooter {

CollisionList::CollisionList() {}

CollisionList::~CollisionList() { Clear(); }

const std::vector<Collider*>& CollisionList::get_collision_list() { return collision_list_; }

void CollisionList::Add(Collider* c1, Collider* c2) {
    collision_list_.push_back(c1);
    collision_list_.push_back(c2);
}

void CollisionList::Clear() { collision_list_.clear(); }

size_t CollisionList::GetSize() { return collision_list_.size(); }

} // namespace spaceshooter