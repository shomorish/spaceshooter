#include "asset_manager.h"

#include <SDL.h>
#include <SDL_image.h>
#include <stdexcept>

namespace spaceshooter {

AssetManager::AssetManager(SDL_Renderer* renderer) : textures_{} {
    LoadTexture("assets/background.png", AssetKey::kBackground, renderer);
    LoadTexture("assets/spaceship_1_blue.png", AssetKey::kSpaceship1Blue, renderer);
    LoadTexture("assets/spin-00.png", AssetKey::kSpin00, renderer);
    LoadTexture("assets/ship-1.png", AssetKey::kShip1, renderer);
    LoadTexture("assets/alien-1.png", AssetKey::kAlien1, renderer);
    LoadTexture("assets/asteroid.png", AssetKey::kAsteroid, renderer);
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