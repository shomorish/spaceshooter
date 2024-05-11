#include <SDL.h>
#include <stdexcept>
#include <stdio.h>

#include "../include/game.h"

int main(int argc, char* args[]) {
    try {
        spaceshooter::Game().Run();
    } catch (std::runtime_error& error) {
        printf("Runtime Error: %s\nSDL Error: %s\n", error.what(), SDL_GetError());
    } catch (std::exception& error) {
        printf("Error: %s\n", error.what());
    }

    return 0;
}