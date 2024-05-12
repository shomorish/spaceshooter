#pragma once

#include "../actor/player.h"
#include "../asset/asset_manager.h"
#include "../game_container.h"
#include "../input/input_mapping.h"

namespace spaceshooter {

class Stage1 {
 private:
    GameContainer* game_container_;
    AssetManager* asset_manager_;
    InputMapping** input_mapping_;
    Player* player_;

 public:
    Stage1(GameContainer* game_container, AssetManager* asset_manager,
           InputMapping** input_mapping);
    ~Stage1();

    void Tick(std::vector<InputAction*> actions, float delta_time);
    void Render();
};

} // namespace spaceshooter
