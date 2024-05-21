#pragma once

#include <SDL.h>
#include <vector>

#include "../actor/actor.h"
#include "../actor/camera.h"
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

    Window* get_window();
    AssetManager* get_asset_manager();
    Camera* get_camera();

    virtual void Tick(std::vector<InputAction> actions, float delta_time) = 0;
    virtual void Render() = 0;
    void AddActor(Actor* actor);
    void DeleteActorIfDestroyed();
    void DeleteAllActors();

 protected:
    Window* window_;
    Renderer* renderer_;
    AssetManager* asset_manager_;
    InputMapping** input_mapping_;
    std::vector<Actor*> actors_;
    Camera camera_;
};

} // namespace spaceshooter
