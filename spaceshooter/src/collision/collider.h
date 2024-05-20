#pragma once

#include <functional>

#include "../actor/actor.h"
#include "../common/vector2.h"
#include "space.h"

namespace spaceshooter {

class Space;
class Actor;

class Collider {
 public:
    Collider(Vector2 pos, float radius, Actor* actor);

    ~Collider();

    Vector2 get_pos();
    void set_pos(Vector2 pos);
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
    void OnCollision(Actor* actor);
    void RegistOnCollisionListener(std::function<void(Actor*)> listener);
    void UnregistOnCollisionListener();

 protected:
    Vector2 pos_;
    float radius_;
    Actor* actor_;
    Space* space_;
    Collider* previous_;
    Collider* next_;
    std::function<void(Actor*)> on_collision_listener_;
};

} // namespace spaceshooter
