#include "level.h"

namespace spaceshooter {

Level::Level(Window* window, Renderer* renderer, AssetManager* asset_manager,
             InputMapping** input_mapping)
    : window_(window), renderer_(renderer), asset_manager_(asset_manager),
      input_mapping_(input_mapping) {}

Level::~Level() {}

} // namespace spaceshooter