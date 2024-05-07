#pragma once

#include "window.h"
#include "renderer.h"

namespace spaceshooter {

/// <summary>
/// ゲーム全体で必要になるオブジェクトを管理するクラス。
/// サービスロケーターパターン。
/// </summary>
class GameContainer {

 private:
    Window* window_;
    Renderer* renderer_;

 public:
    GameContainer(const char*, int, int);
    ~GameContainer();
    Window* get_window();
    Renderer* get_renderer();
};

} // namespace spaceshooter
