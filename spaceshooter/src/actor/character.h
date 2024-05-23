#pragma once

#include "../common/vector2.h"
#include "actor.h"
#include "controller.h"

namespace spaceshooter {

class Controller;

class Character : public Actor {
 public:
    Character(Vector2 pos, Vector2 size, Vector2 direction, SDL_Texture* texture,
              Controller* owner);

    virtual ~Character();

    Vector2 get_direction();
    void set_direction(Vector2 direction);
    SDL_Texture* get_texture();
    void set_texture(SDL_Texture* texture);
    void set_owner(Controller* owner);

    void Render(SDL_Renderer* renderer, Camera* camera) override;
    void Destroy() override;

 protected:
    Vector2 direction_;
    SDL_Texture* texture_;
    float angle_;
    Controller* owner_;
};

} // namespace spaceshooter
