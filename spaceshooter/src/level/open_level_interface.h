#pragma once

#include "level_type.h"

namespace spaceshooter {

class OpenLevelInterface {
 public:
    virtual void OpenLevel(LevelType level_type) = 0;
};

} // namespace spaceshooter
