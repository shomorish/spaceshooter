#pragma once

#include "../../include/texture/texture.h"
#include <SDL.h>
#include <map>

namespace spaceshooter {

enum AssetKey { kSpaceship1Blue };

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
