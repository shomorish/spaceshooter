#include "asset_manager.h"

#include <SDL.h>
#include <SDL_image.h>
#include <stdexcept>

namespace spaceshooter {

AssetManager::AssetManager(SDL_Renderer* renderer) : textures_{} {
    LoadTexture("assets/images/bg-1.png", AssetKey::kBg1, renderer);
    LoadTexture("assets/images/bg-2.png", AssetKey::kBg2, renderer);
    LoadTexture("assets/images/overlay.png", AssetKey::kOverlay, renderer);
    LoadTexture("assets/images/frame-1.png", AssetKey::kFrame1, renderer);
    LoadTexture("assets/images/cursor-1.png", AssetKey::kCursor1, renderer);
    LoadTexture("assets/images/ship-1.png", AssetKey::kShip1, renderer);
    LoadTexture("assets/images/alien-1.png", AssetKey::kAlien1, renderer);
    LoadTexture("assets/images/asteroid.png", AssetKey::kAsteroid, renderer);
    LoadSpriteSheet("assets/images/exp-1.png", AssetKey::kExplosion1, 64, 64, 4, 4, renderer);
}

AssetManager::~AssetManager() {
    for (auto iter = textures_.begin(); iter != textures_.end(); iter++) {
        delete iter->second;
    }
    textures_.clear();

    for (auto iter = sprite_sheets_.begin(); iter != sprite_sheets_.end(); iter++) {
        delete iter->second;
    }
    sprite_sheets_.clear();
}

Texture* AssetManager::GetTexture(AssetKey key) { return textures_.at(key); }

SpriteSheetTexture* AssetManager::GetSpriteSheet(AssetKey key) { return sprite_sheets_.at(key); }

void AssetManager::LoadTexture(std::string path, AssetKey key, SDL_Renderer* renderer) {
    Texture* texture = new Texture(path, renderer);
    if (texture == NULL) {
        throw std::runtime_error("Failed to create player texture.");
    }
    textures_.insert(std::make_pair(key, texture));
}

void AssetManager::LoadSpriteSheet(std::string path, AssetKey key, int split_w, int split_h,
                                   int row, int column, SDL_Renderer* renderer) {
    SpriteSheetTexture* texture =
        new SpriteSheetTexture(path, split_w, split_h, row, column, renderer);
    if (texture == NULL) {
        throw std::runtime_error("Failed to create player texture.");
    }
    sprite_sheets_.insert(std::make_pair(key, texture));
}

} // namespace spaceshooter