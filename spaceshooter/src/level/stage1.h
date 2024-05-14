#pragma once

#include "../actor/player.h"
#include "../actor/player_controller.h"
#include "../asset/asset_manager.h"
#include "../input/input_mapping.h"
#include "level.h"

namespace spaceshooter {

class Stage1 : public Level {
 public:
    Stage1(Window* window, Renderer* renderer, AssetManager* asset_manager,
           InputMapping** input_mapping);
    ~Stage1();

    void Tick(std::vector<InputAction> actions, float delta_time) override;
    void Render() override;

 private:
    PlayerController* player_controller_;
};

} // namespace spaceshooter
