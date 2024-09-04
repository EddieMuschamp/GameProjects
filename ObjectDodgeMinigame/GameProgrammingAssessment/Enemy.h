#ifndef anEnemy
#define anEnemy
#include "SDL.h"
#include "Sprite.h"
#include "Player.h"
#include <iostream>

class Enemy
{
private:
	int enemyX, enemyY, enemyW, enemyH;
	int randomWStart;
	int randomWaitStart;
	int randomX;
	Sprite enemySprite;
	bool collision = false;

public:
	int timeToWait;
	Enemy(SDL_Renderer* renderer);
	void Update(int* score, int* scoreMult);
	void Render(SDL_Renderer* renderer);
	void Collisions(Player* newPlayer);
};


#endif