#include <iostream>
#include <string>
#include "SDL.h"
#include "SZ_timer.h"

SZ_Timer aTimer;
const int DELTA_TIME = 1;
bool done = false;
bool grid[96][96];
bool updateGrid[96][96];
bool gridDone = false;

int numNeigh(int x, int y) 
{
    int totalNum = 0;
    for (int i = -1; i < 2; i++) 
    {
        for (int j = -1; j < 2; j++) 
        {
            if (i == 0 && j == 0) 
            {
                continue;
            }
            if (grid[x + i][y + j]) 
            {
                totalNum++;
            }
        }
    }
    return totalNum;
}


int main(int argc, char* argv[])
{
    

    Uint32 flags = SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN_DESKTOP;
    SDL_Window* window = SDL_CreateWindow("Workshop #3", 300, 300, 800, 600, flags);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); //Create a renderer which draws to the window surface

    while (!done)
    {
        aTimer.resetTicksTimer(); // resets a frame timer to zero

        SDL_SetRenderDrawColor(renderer, 72, 173, 204, 0); //Set the “pen colour” to a red colour
        SDL_RenderClear(renderer); //Clear everything on the window -- paint over with last known colour
 
        if (!gridDone) 
        {
            for (int i = 0; i < 96; i++)
            {
                for (int j = 0; j < 96; j++)
                {
                    SDL_Rect newSquare;
                    newSquare.x = 25 * i;
                    newSquare.y = 25 * j;
                    newSquare.w = 20;
                    newSquare.h = 20;
                    //-----------------------ADD LIVE CELLS HERE (i && j)----------------------//
                    if ((i == 2 && j == 2) || (i == 2 && j == 3) || (i == 3 && j == 2) || (i == 5 && j == 2) || (i == 5 && j == 3) || (i == 5 && j == 1))
                    {
                        grid[i][j] = true;
                    }
                    else
                    {
                        grid[i][j] = false;

                    }
                    SDL_SetRenderDrawColor(renderer, 84, 86, 87, 0);
                    SDL_RenderFillRect(renderer, &newSquare);
                }
            }
            gridDone = true;
        }
        

        
        for (int k = 0; k < 96; k++)
        {
            for (int l = 0; l < 96; l++)
            {
                if (grid[k][l]) 
                {
                    SDL_Rect newSquare;
                    newSquare.x = 25 * k;
                    newSquare.y = 25 * l;
                    newSquare.w = 20;
                    newSquare.h = 20;
                    if (numNeigh(k, l) > 3 || numNeigh(k, l) < 2)
                    {
                        SDL_SetRenderDrawColor(renderer, 84, 86, 87, 0);
                        updateGrid[k][l] = false;
                    }
                    else 
                    {
                        SDL_SetRenderDrawColor(renderer, 255, 0, 100, 0);
                        updateGrid[k][l] = true;
                    }

                    SDL_RenderFillRect(renderer, &newSquare);
                }
                else 
                {
                    SDL_Rect newSquare;
                    newSquare.x = 25 * k;
                    newSquare.y = 25 * l;
                    newSquare.w = 20;
                    newSquare.h = 20;
                    if (numNeigh(k, l) == 3) 
                    {
                        SDL_SetRenderDrawColor(renderer, 255, 0, 100, 0);
                        updateGrid[k][l] = true;
                    }
                    else 
                    {
                        SDL_SetRenderDrawColor(renderer, 84, 86, 87, 0);
                        updateGrid[k][l] = false;
                    }
                    SDL_RenderFillRect(renderer, &newSquare);
                }
            }
        }

        for (int i = 0; i < 96; i++)
        {
            for (int j = 0; j < 96; j++)
            {
                grid[i][j] = updateGrid[i][j];
            }
        }
        





        SDL_RenderPresent(renderer); //Tell SDL we have finished drawing, SDL will actually show our changes:

        if (aTimer.getTicks() < DELTA_TIME)
        {
            SDL_Delay(DELTA_TIME - aTimer.getTicks());
        }

    }

    return 0;
}


