#pragma once

#include "../actor/player.h"
#include "../asset/asset_manager.h"
#include "../input/input_mapping.h"
#include "level.h"

namespace spaceshooter {

class Stage1 : public Level {
 private:
    Player* player_;

 public:
    Stage1(Window* window, Renderer* renderer, AssetManager* asset_manager,
           InputMapping** input_mapping);
    ~Stage1();

    void Tick(std::vector<InputAction*> actions, float delta_time) override;
    void Render() override;
};

} // namespace spaceshooter
