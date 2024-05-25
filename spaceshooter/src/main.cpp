// clang-format off

// メモリーリークチェック
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

// clang-format on

#include <SDL.h>
#include <stdexcept>
#include <stdio.h>

#include "game.h"

int main(int argc, char* args[]) {
    // メモリーリークチェック
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    try {
        spaceshooter::Game().Run();
    } catch (std::runtime_error& error) {
        printf("Runtime Error: %s\nSDL Error: %s\n", error.what(), SDL_GetError());
    } catch (std::exception& error) {
        printf("Error: %s\n", error.what());
    }

    // メモリーリークチェック
    _CrtDumpMemoryLeaks();

    return 0;
}