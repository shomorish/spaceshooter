#include "character.h"

namespace spaceshooter {

Character::Character(Vector2 pos, Vector2 size, Vector2 direction, SDL_Texture* texture)
    : pos_(pos), size_(size), direction_(direction), texture_(texture) {}

Character::~Character() {}

}