#pragma once

#include "renderer.h"
#include "time/timer.h"
#include "window.h"

namespace spaceshooter {

/// <summary>
/// ゲーム全体で必要になるオブジェクトを管理するクラス。
/// サービスロケーターパターン。
/// </summary>
class GameContainer {

 private:
    Window* window_;
    Renderer* renderer_;
    Timer* timer_;

 public:
    GameContainer(const char*, int, int);
    ~GameContainer();
    Window* get_window();
    Renderer* get_renderer();
    Timer* get_timer();
};

} // namespace spaceshooter
