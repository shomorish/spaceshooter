#pragma once

#include "collider.h"

namespace spaceshooter {

class Collider;

class Space {
 public:
    Space();

    ~Space();

    Collider* get_first();

    void ResetLink(Collider* collider);
    void Add(Collider* collider);
    void OnRemove(Collider* collider);

 private:
    Collider* first_;
};

} // namespace spaceshooter
