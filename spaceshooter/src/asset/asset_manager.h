#pragma once

#include <SDL.h>
#include <map>

#include "../texture/texture.h"

namespace spaceshooter {

enum AssetKey { kBackground, kOverlay, kSpaceship1Blue, kSpin00, kAsteroid, kShip1, kAlien1 };

class AssetManager {
 public:
    AssetManager(SDL_Renderer* renderer);
    AssetManager(const AssetManager&) = delete;

    ~AssetManager();

    Texture* GetTexture(AssetKey key);

    AssetManager& operator=(const AssetManager&) = delete;

 private:
    std::map<AssetKey, Texture*> textures_;

    void LoadTexture(std::string path, AssetKey key, SDL_Renderer* renderer);
};

} // namespace spaceshooter
