#pragma once

#include <SDL.h>
#include <map>

#include "../texture/sprite_sheet_texture.h"
#include "../texture/texture.h"

namespace spaceshooter {

enum AssetKey {
    kBackground,
    kOverlay,
    kFrame1,
    kCursor1,
    kSpaceship1Blue,
    kSpin00,
    kAsteroid,
    kShip1,
    kAlien1,
    kExplosion1,
};

class AssetManager {
 public:
    AssetManager(SDL_Renderer* renderer);
    AssetManager(const AssetManager&) = delete;

    ~AssetManager();

    Texture* GetTexture(AssetKey key);
    SpriteSheetTexture* GetSpriteSheet(AssetKey key);

    AssetManager& operator=(const AssetManager&) = delete;

 private:
    std::map<AssetKey, Texture*> textures_;
    std::map<AssetKey, SpriteSheetTexture*> sprite_sheets_;
    void LoadTexture(std::string path, AssetKey key, SDL_Renderer* renderer);
    void LoadSpriteSheet(std::string path, AssetKey key, int split_w, int split_h, int row,
                         int column, SDL_Renderer* renderer);
};

} // namespace spaceshooter
