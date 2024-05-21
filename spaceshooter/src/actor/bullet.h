#pragma once

#include <SDL.h>

#include "../common/vector2.h"
#include "actor.h"

namespace spaceshooter {

enum BulletOwnerType { kPlayer, kEnemy, kUnknown };

class Bullet : public Actor {
 public:
    Bullet();
    Bullet(Vector2 pos, Vector2 size, Vector2 direction, float speed, float lifetime,
           bool is_alive, BulletOwnerType owner_type);
    Bullet(const Bullet&) = delete;

    virtual ~Bullet();

    bool get_is_alive();
    void set_is_alive(bool is_alive);

    Bullet& operator=(const Bullet&) = delete;

 protected:
    Vector2 direction_;
    float speed_;
    float lifetime_;
    bool is_alive_;
    BulletOwnerType owner_type_;
};

} // namespace spaceshooter
