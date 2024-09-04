#include "GameWorld.h"


GameWorld::GameWorld(SDL_Window* newWindow, SDL_Renderer* currentRenderer)
{
    border1.x = 1000;
    border1.y = 0;
    border1.w = 2000;
    border1.h = 2000;
    border2.x = 0;
    border2.y = 800;
    border2.w = 2000;
    border2.h = 2000;
    splashScreen.setWidth(1000);
    splashScreen.setHeight(800);
    window = newWindow;
    renderer = currentRenderer;
    
}

void GameWorld::splash() 
{
    SDL_SetRenderDrawColor(renderer, 126, 129, 135, 0);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderFillRect(renderer, &border1);
    SDL_RenderFillRect(renderer, &border2);
    splashScreen.load(renderer, "assests/splash.png");
    splashScreen.update();
    splashScreen.Render(renderer, 0, 0, SDL_FLIP_NONE);
    SDL_RenderPresent(renderer);
    while (!enter && !exit) 
    {
        while (SDL_PollEvent(&event1))
        {
            if (event1.type == SDL_QUIT)
                exit = true;
            if (event1.type == SDL_KEYDOWN)
            {
                switch (event1.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    exit = true;
                    break;
                case SDLK_RETURN:
                    enter = true;
                    break;
                case SDLK_f:
                    fullScreen(isFull);
                    splashScreen.update();
                    splashScreen.Render(renderer, 0, 0, SDL_FLIP_NONE);
                    SDL_RenderPresent(renderer);
                }
            }
        }
    }
}
void GameWorld::Run()
{
    
    Player* newPlayer = new Player(renderer);
    EnemyContainer* newEnemies = new EnemyContainer(renderer);
    PickupContainer* newPickups = new PickupContainer(renderer);
    newEnemies->FillContainer();
    newPickups->FillContainer();
    while (!exit)
    {
        aTimer.resetTicksTimer();


        SDL_SetRenderDrawColor(renderer, 126, 129, 135, 0);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderFillRect(renderer, &border1);
        SDL_RenderFillRect(renderer, &border2);

        Inputs(newPlayer);


        newEnemies->Collisions(newPlayer);
        newPickups->Collisions(newPlayer);
        newPlayer->Update();
        newPlayer->Render(renderer);
        newEnemies->UpdateAndRender(&score, &scoreMulti);
        newPickups->UpdateAndRender(&score, &scoreMulti);
        //std::cout << score << std::endl;

        SDL_RenderPresent(renderer);

        if (aTimer.getTicks() < DELTA_TIME)
        {
            SDL_Delay(DELTA_TIME - aTimer.getTicks());
        }
    }
}


void GameWorld::Inputs(Player* newPlayer) 
{
    while (SDL_PollEvent(&event1))
    {
        if (event1.type == SDL_QUIT)
            exit = true;
        if (event1.type == SDL_KEYDOWN)
        {
            switch (event1.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                exit = true;
                break;
            case SDLK_a:
                movingLeft = true;
                movingRight = false;
                newPlayer->Input(event1.key.keysym.sym);
                break;
            case SDLK_d:
                movingRight = true;
                movingLeft = false;
                newPlayer->Input(event1.key.keysym.sym);
                break;
            case SDLK_SPACE:
                break;
            case SDLK_f:
                fullScreen(isFull);
            }
        }
        else if (event1.type == SDL_KEYUP)
        {
            switch (event1.key.keysym.sym)
            {
            case SDLK_a:
                if (!movingRight)
                {
                    movingLeft = false;
                    newPlayer->Input(0);
                }
                break;
            case SDLK_d:
                if (!movingLeft)
                {
                    movingRight = false;
                    newPlayer->Input(0);
                }
                break;
            }
        }
    }
}

void GameWorld::fullScreen(bool currentState)
{
    isFull = !currentState;
    if (isFull) 
    {
        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
    }
    else 
    {
        SDL_SetWindowFullscreen(window, 0);
    }
    
}