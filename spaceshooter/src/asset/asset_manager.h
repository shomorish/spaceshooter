#pragma once

#include <SDL.h>
#include <map>

#include "../texture/texture.h"

namespace spaceshooter {

enum AssetKey { kSpaceship1Blue, kSpin00 };

class AssetManager {
 private:
    std::map<AssetKey, Texture*> textures_;

 public:
    AssetManager(SDL_Renderer* renderer);
    AssetManager(const AssetManager&) = delete;

    ~AssetManager();

    Texture* GetTexture(AssetKey key);

    AssetManager& operator=(const AssetManager&) = delete;
};

} // namespace spaceshooter
