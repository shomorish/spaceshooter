#include "text_view.h"

namespace spaceshooter {

TextView::TextView() : font_(NULL) {}

TextView::~TextView() {
    if (font_) {
        delete font_;
        font_ = NULL;
    }

    // テキストビューはテクスチャを作成するのでここで削除する
    if (texture_) {
        delete texture_;
        texture_ = NULL;
    }
}

void TextView::set_font(std::string path, int point_size) { font_ = new Font(path, point_size); }

void TextView::SetText(std::string text, SDL_Color text_color, SDL_Renderer* renderer) {
    if (font_) {
        if (texture_) {
            delete texture_;
            texture_ = NULL;
        }
        texture_ = new Texture(font_, text, text_color, renderer);
    }
}

} // namespace spaceshooter