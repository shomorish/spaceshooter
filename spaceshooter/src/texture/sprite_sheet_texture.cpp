#include "sprite_sheet_texture.h"

#include <SDL_image.h>
#include <stdexcept>

namespace spaceshooter {

SpriteSheetTexture::SpriteSheetTexture(std::string path, int split_w, int split_h, int row,
                                       int column, SDL_Renderer* renderer) {
    num_of_sprites_ = row * column;

    SDL_Surface* surface = IMG_Load(path.c_str());
    if (surface == NULL) {
        throw std::runtime_error("Failed to load png.\n");
    }

    sprite_rects_ = new SDL_Rect[row * column];

    for (int r = 0; r < row; r++) {
        for (int c = 0; c < column; c++) {
            sprite_rects_[r * column + c].x = c * split_w;
            sprite_rects_[r * column + c].y = r * split_h;
            sprite_rects_[r * column + c].w = split_w;
            sprite_rects_[r * column + c].h = split_h;
        }
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    surface = NULL;
    if (texture == NULL) {
        throw std::runtime_error("Failed to create texture.\n");
    }

    texture_ = texture;
}

SpriteSheetTexture::~SpriteSheetTexture() {
    delete[] sprite_rects_;
    if (texture_ != NULL) {
        SDL_DestroyTexture(texture_);
        texture_ = NULL;
    }
}

int SpriteSheetTexture::get_num_of_sprites() { return num_of_sprites_; }

SDL_Texture* SpriteSheetTexture::sdl() { return texture_; }

void SpriteSheetTexture::SetAlpha(Uint8 alpha) { SDL_SetTextureAlphaMod(texture_, alpha); }

void SpriteSheetTexture::Render(SDL_Renderer* renderer, int sprite_index, Vector2 pos,
                                Vector2* size) {
    SDL_FRect render_quad = {0};
    render_quad.x = pos.x;
    render_quad.y = pos.y;
    render_quad.w = sprite_rects_[sprite_index].w;
    render_quad.h = sprite_rects_[sprite_index].h;
    if (size) {
        render_quad.w = size->x;
        render_quad.h = size->y;
    }
    SDL_RenderCopyF(renderer, texture_, &sprite_rects_[sprite_index], &render_quad);
}

} // namespace spaceshooter