#pragma once

#include <SDL.h>

#include "../collision/collider.h"
#include "../common/vector2.h"
#include "camera.h"

namespace spaceshooter {

class Collider;

class Actor {
 public:
    Actor();
    Actor(Vector2 pos, Vector2 size);

    virtual ~Actor();

    Vector2 get_pos();
    virtual void set_pos(Vector2 pos);
    Vector2 get_size();
    void set_size(Vector2 size);
    bool get_is_destroyed();
    virtual Collider* get_collider();

    virtual void Tick(const float& delta_time);
    virtual void Render(SDL_Renderer* renderer, Camera* camera);
    void Destroy();
    virtual bool HasCollider();
    virtual void ApplyDamage(float damage);

 protected:
    Vector2 pos_;
    Vector2 size_;
    bool is_destroyed_;
    Collider* collider_;
};

} // namespace spaceshooter
