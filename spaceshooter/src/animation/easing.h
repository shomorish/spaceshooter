#pragma once

namespace spaceshooter {

class Easing {
 public:
    virtual float operator()(float x) = 0;
};

} // namespace spaceshooter
