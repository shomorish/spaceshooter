#pragma once

#include <SDL.h>

#include "../font/font.h"
#include "view.h"

namespace spaceshooter {

class TextView : public View {
 public:
    TextView();

    ~TextView();

    void set_font(std::string, int point_size);

    void SetText(std::string text, SDL_Color text_color, SDL_Renderer* renderer);

 private:
    Font* font_;
};

} // namespace spaceshooter
