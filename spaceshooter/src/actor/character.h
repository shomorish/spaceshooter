#pragma once

#include "../common/vector2.h"
#include "actor.h"

namespace spaceshooter {

class Character : public Actor {
 public:
    Character(Vector2 pos, Vector2 size, Vector2 direction, SDL_Texture* texture);

    virtual ~Character();

    Vector2 get_pos();
    void set_pos(Vector2 pos);
    Vector2 get_size();
    void set_size(Vector2 size);
    Vector2 get_direction();
    void set_direction(Vector2 direction);
    SDL_Texture* get_texture();
    void set_texture(SDL_Texture* texture);

    void Render(SDL_Renderer* renderer) override;

 protected:
    Vector2 pos_;
    Vector2 size_;
    Vector2 direction_;
    SDL_Texture* texture_;
    float angle_;
};
} // namespace spaceshooter
