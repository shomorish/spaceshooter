#pragma once

#include <SDL.h>

namespace spaceshooter {

struct Color {
    Uint8 r, g, b, a;

    static Color red;
    static Color yellow;
    static Color green;
    static Color blue;
    static Color white;
};

} // namespace spaceshooter
