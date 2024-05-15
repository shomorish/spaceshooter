#include "asset_manager.h"

#include <SDL.h>
#include <SDL_image.h>
#include <stdexcept>

namespace spaceshooter {

AssetManager::AssetManager(SDL_Renderer* renderer) : textures_{} {
    Texture* texture = new Texture("assets/spaceship_1_blue.png", renderer);
    if (texture == NULL) {
        throw std::runtime_error("Failed to create player texture.");
    }
    textures_.insert(std::make_pair(AssetKey::kSpaceship1Blue, texture));

    texture = new Texture("assets/spin-00.png", renderer);
    if (texture == NULL) {
        throw std::runtime_error("Failed to create player texture.");
    }
    textures_.insert(std::make_pair(AssetKey::kSpin00, texture));
}

AssetManager::~AssetManager() {
    for (auto iter = textures_.begin(); iter != textures_.end(); iter++) {
        delete iter->second;
    }
    textures_.clear();
}

Texture* AssetManager::GetTexture(AssetKey key) { return textures_.at(key); }

} // namespace spaceshooter