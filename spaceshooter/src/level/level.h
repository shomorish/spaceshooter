#pragma once

#include <SDL.h>
#include <vector>

#include "../actor/actor.h"
#include "../actor/camera.h"
#include "../asset/asset_manager.h"
#include "../game_context.h"
#include "../input/input_mapping.h"
#include "../renderer.h"
#include "../window.h"

namespace spaceshooter {

class Level {
 public:
    Level(GameContext* game_context);

    virtual ~Level();

    Window* get_window();
    AssetManager* get_asset_manager();
    Camera* get_camera();

    virtual void Tick(float delta_time) = 0;
    virtual void Render() = 0;
    void UpdateInputState();
    void HandleInputEvent(const SDL_Event& event);
    void ClearInputActions();
    void AddActor(Actor* actor);
    void DeleteActorIfDestroyed();
    void DeleteAllActors();

 protected:
    GameContext* game_context_;
    InputMapping* input_mapping_;
    std::vector<Actor*> actors_;
    Camera camera_;
};

} // namespace spaceshooter
