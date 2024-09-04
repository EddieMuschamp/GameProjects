#include <iostream>
#include <string>
#include <ctime>
#include "SDL.h"
#include "SZ_timer.h"
#include "Player.h"
#include "GameWorld.h"
#include "Sprite.h"




int main(int argc, char *argv[])
{
    srand((unsigned int)time(NULL));
    Uint32 flags = SDL_WINDOW_OPENGL;
    SDL_Window* window = SDL_CreateWindow("Assessment1", 0, 25, 1000, 800, flags);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    GameWorld mainWorld(window, renderer);
    mainWorld.splash();
    mainWorld.Run();


    return 0;
}
