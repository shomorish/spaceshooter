#pragma once

#include <SDL.h>
#include <string>

#include "../common/vector2.h"

namespace spaceshooter {

class SpriteSheetTexture {
 public:
    SpriteSheetTexture(std::string path, int split_w, int split_h, int row, int column,
                       SDL_Renderer* renderer);

    ~SpriteSheetTexture();

    int get_num_of_sprites();

    SDL_Texture* sdl();

    void SetAlpha(Uint8 alpha);
    void Render(SDL_Renderer* renderer, int sprite_index, Vector2 pos, Vector2* size = NULL);

 private:
    int num_of_sprites_;
    SDL_Texture* texture_;
    SDL_Rect* sprite_rects_;
};

} // namespace spaceshooter
