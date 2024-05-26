#include "asset_manager.h"

#include <SDL.h>
#include <SDL_image.h>
#include <stdexcept>

namespace spaceshooter {

AssetManager::AssetManager(SDL_Renderer* renderer) : textures_{} {
    LoadTexture("assets/images/background.png", AssetKey::kBackground, renderer);
    LoadTexture("assets/images/overlay.png", AssetKey::kOverlay, renderer);
    LoadTexture("assets/images/frame-1.png", AssetKey::kFrame1, renderer);
    LoadTexture("assets/images/cursor-1.png", AssetKey::kCursor1, renderer);
    LoadTexture("assets/images/spaceship_1_blue.png", AssetKey::kSpaceship1Blue, renderer);
    LoadTexture("assets/images/spin-00.png", AssetKey::kSpin00, renderer);
    LoadTexture("assets/images/ship-1.png", AssetKey::kShip1, renderer);
    LoadTexture("assets/images/alien-1.png", AssetKey::kAlien1, renderer);
    LoadTexture("assets/images/asteroid.png", AssetKey::kAsteroid, renderer);
}

AssetManager::~AssetManager() {
    for (auto iter = textures_.begin(); iter != textures_.end(); iter++) {
        delete iter->second;
    }
    textures_.clear();
}

Texture* AssetManager::GetTexture(AssetKey key) { return textures_.at(key); }

void AssetManager::LoadTexture(std::string path, AssetKey key, SDL_Renderer* renderer) {
    Texture* texture = new Texture(path, renderer);
    if (texture == NULL) {
        throw std::runtime_error("Failed to create player texture.");
    }
    textures_.insert(std::make_pair(key, texture));
}

} // namespace spaceshooter