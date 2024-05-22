#include "font.h"

#include <stdexcept>

namespace spaceshooter {

Font::Font() : font_(NULL) {}

Font::Font(std::string path, int point_size) { Open(path, point_size); }

Font::~Font() { Close(); }

TTF_Font* Font::sdl() { return font_; }

void Font::Open(std::string path, int point_size) {
    // すでにフォントを開いている場合は閉じる
    if (font_ != NULL) Close();

    font_ = TTF_OpenFont(path.c_str(), point_size);
    if (font_ == NULL) {
        throw std::runtime_error("Failed to open font.");
    }
}

void Font::Close() {
    TTF_CloseFont(font_);
    font_ = NULL;
}

} // namespace spaceshooter