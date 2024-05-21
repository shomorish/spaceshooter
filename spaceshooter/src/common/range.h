#pragma once

namespace spaceshooter {

struct Range {
    float min;
    float max;

    bool withinRange(float current);
};

} // namespace spaceshooter
