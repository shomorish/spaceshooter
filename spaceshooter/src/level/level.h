#pragma once

#include <SDL.h>

#include "../asset/asset_manager.h"
#include "../input/input_mapping.h"
#include "../renderer.h"
#include "../window.h"

namespace spaceshooter {

class Level {
 public:
    Level(Window* window, Renderer* renderer, AssetManager* asset_manager,
          InputMapping** input_mapping);

    virtual ~Level();

    virtual void Tick(std::vector<InputAction*> actions, float delta_time) = 0;
    virtual void Render() = 0;

 protected:
    Window* window_;
    Renderer* renderer_;
    AssetManager* asset_manager_;
    InputMapping** input_mapping_;
};

} // namespace spaceshooter
