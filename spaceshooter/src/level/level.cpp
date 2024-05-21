#include "level.h"

namespace spaceshooter {

Level::Level(Window* window, Renderer* renderer, AssetManager* asset_manager,
             InputMapping** input_mapping)
    : window_(window), renderer_(renderer), asset_manager_(asset_manager),
      input_mapping_(input_mapping) {}

Level::~Level() {
    window_ = NULL;
    renderer_ = NULL;
    asset_manager_ = NULL;

    if (*input_mapping_ != NULL) {
        delete *input_mapping_;
        *input_mapping_ = NULL;
        input_mapping_ = NULL;
    }

    DeleteAllActors();
}

Window* Level::get_window() { return window_; }

AssetManager* Level::get_asset_manager() { return asset_manager_; }

Camera* Level::get_camera() { return &camera_; }

void Level::AddActor(Actor* actor) { actors_.push_back(actor); }

void Level::DeleteActorIfDestroyed() {
    auto iter = actors_.begin();
    while (iter != actors_.end()) {
        Actor* a = *iter;
        if (a->get_is_destroyed()) {
            delete a;
            iter = actors_.erase(iter);
        } else {
            iter++;
        }
    }
}

void Level::DeleteAllActors() {
    auto iter = actors_.begin();
    while (iter != actors_.end()) {
        Actor* a = *iter;
        delete a;
        iter = actors_.erase(iter);
    }
}

} // namespace spaceshooter