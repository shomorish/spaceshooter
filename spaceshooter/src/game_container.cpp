#include "game_container.h"

namespace spaceshooter {

GameContainer::GameContainer(const char* window_title, int window_width, int window_height)
    : window_(NULL), renderer_(NULL) {
    window_ = new Window(window_title, window_width, window_height);
    renderer_ = new Renderer(window_);
}

GameContainer::~GameContainer() {
    if (window_ != NULL) {
        delete window_;
        window_ = NULL;
    }

    if (renderer_ != NULL) {
        delete renderer_;
        renderer_ = NULL;
    }
}

Window* GameContainer::get_window() { return window_; }

Renderer* GameContainer::get_renderer() { return renderer_; }

} // namespace spaceshooter