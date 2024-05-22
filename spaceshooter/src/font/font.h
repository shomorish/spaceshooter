#pragma once

#include <SDL_ttf.h>
#include <string>

namespace spaceshooter {

class Font {
 public:
    Font();
    Font(std::string path, int point_size);

    ~Font();

    TTF_Font* sdl();

    void Open(std::string path, int point_size);
    void Close();

 private:
    TTF_Font* font_;
};

} // namespace spaceshooter
