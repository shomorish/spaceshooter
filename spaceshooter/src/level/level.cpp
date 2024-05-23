#include "level.h"

namespace spaceshooter {

Level::Level(GameContext* game_context) : game_context_(game_context) {}

Level::~Level() {
    game_context_ = NULL;
    DeleteAllActors();
}

Window* Level::get_window() { return game_context_->get_window(); }

AssetManager* Level::get_asset_manager() { return game_context_->get_asset_manager(); }

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