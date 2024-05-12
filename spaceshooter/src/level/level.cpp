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
}

} // namespace spaceshooter