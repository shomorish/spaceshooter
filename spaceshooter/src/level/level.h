#pragma once

#include <SDL.h>
#include <vector>

#include "../actor/actor.h"
#include "../actor/camera.h"
#include "../asset/asset_manager.h"
#include "../game_context.h"
#include "../input/input_action_container.h"
#include "../input/input_mapping.h"
#include "../renderer.h"
#include "../window.h"
#include "level_door.h"
#include "level_type.h"
#include "open_level_interface.h"

namespace spaceshooter {

class Level {
 public:
    Level(GameContext* game_context, OpenLevelInterface* open_level_interface);

    virtual ~Level();

    Window* get_window();
    AssetManager* get_asset_manager();
    InputMapping* get_input_mapping();
    void set_input_mapping(InputMapping* input_mapping);
    Camera* get_camera();

    virtual void Tick(float delta_time) = 0;
    virtual void Render() = 0;
    void UpdateInputState();
    void HandleInputEvent(const SDL_Event& event);
    void ClearInputActions();
    void AddActor(Actor* actor);
    void DeleteActorIfDestroyed();
    void DeleteAllActors();
    void GenerateInputActions();
    const InputActionContainer* GetInputActionContainer();

 protected:
    GameContext* game_context_;
    OpenLevelInterface* open_level_interface_;
    std::vector<Actor*> actors_;
    Camera camera_;
    LevelDoor door_;

 private:
    InputMapping* input_mapping_;
    InputActionContainer action_container_;
};

} // namespace spaceshooter
