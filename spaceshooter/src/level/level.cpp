#include "level.h"

namespace spaceshooter {

Level::Level(GameContext* game_context) : game_context_(game_context), input_mapping_(NULL) {
    door_.set_texture(game_context_->get_asset_manager()->GetTexture(AssetKey::kOverlay));
}

Level::~Level() {
    game_context_ = NULL;
    if (input_mapping_) {
        delete input_mapping_;
        input_mapping_ = NULL;
    }
    DeleteAllActors();
}

Window* Level::get_window() { return game_context_->get_window(); }

AssetManager* Level::get_asset_manager() { return game_context_->get_asset_manager(); }

InputMapping* Level::get_input_mapping() { return input_mapping_; }

void Level::set_input_mapping(InputMapping* input_mapping) {
    if (input_mapping_) {
        delete input_mapping_;
        input_mapping_ = NULL;
    }
    input_mapping_ = input_mapping;
}

Camera* Level::get_camera() { return &camera_; }

void Level::UpdateInputState() {
    if (input_mapping_) {
        input_mapping_->UpdateInputState();
    }
}

void Level::HandleInputEvent(const SDL_Event& event) {
    if (input_mapping_) {
        input_mapping_->HandleInputEvent(event);
    }
}

void Level::ClearInputActions() {
    if (input_mapping_) {
        input_mapping_->ClearInputActions();
    }
}

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