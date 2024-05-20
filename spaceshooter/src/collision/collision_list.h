#pragma once

#include <vector>

#include "collider.h"

namespace spaceshooter {

class CollisionList {
 public:
    CollisionList();

    ~CollisionList();

    void Add(Collider* c1, Collider* c2);
    void Clear();
    size_t GetSize();

 private:
    std::vector<Collider*> collision_list_;
};

} // namespace spaceshooter
