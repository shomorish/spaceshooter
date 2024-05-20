#pragma once

#include "../actor/actor.h"
#include "../common/vector2.h"
#include "space.h"

namespace spaceshooter {

class Space;

class Collider {
 public:
    Collider(float radius, Actor* actor);

    ~Collider();

    float get_radius();
    Actor* get_actor();
    Space* get_space();
    void set_space(Space* space);
    Collider* get_previous();
    void set_previous(Collider* previous);
    Collider* get_next();
    void set_next(Collider* next);

    Vector2 GetPos();
    Vector2 GetTopLeft();
    Vector2 GetBottomRight();
    void ExitSpace();

 protected:
    Vector2 pos_;
    float radius_;
    Actor* actor_;
    Space* space_;
    Collider* previous_;
    Collider* next_;
};

} // namespace spaceshooter
