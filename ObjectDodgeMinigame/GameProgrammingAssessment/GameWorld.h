#ifndef aGameWorld
#define aGameWorld
#include <SDL.h>
#include "SZ_timer.h"
#include "Player.h"
#include "EnemyContainer.h"
#include "Sprite.h"
#include "PickupContainer.h"

class GameWorld
{
private:
	SDL_Event event1;
	bool movingLeft = false;
	bool movingRight = false;
	bool exit = false;
	bool enter = false;
	bool isFull;
	SZ_Timer aTimer;
	const int DELTA_TIME = 30;
	SDL_Rect border1;
	SDL_Rect border2;
	SDL_Window* window;
	SDL_Renderer* renderer;
	int score = 0;
	int scoreMulti = 1;
	Sprite splashScreen;
public:
	GameWorld(SDL_Window* window, SDL_Renderer* currentRenderer);
	void Run();
	void Inputs(Player* newPlayer);
	void fullScreen(bool currentState);
	void splash();
};

#endif

