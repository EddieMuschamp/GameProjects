#include "Enemy.h"

Enemy::Enemy(SDL_Renderer* renderer)
{
	enemyY = 20;
	randomWStart = rand() % 90 + 10;
	enemyW = randomWStart;
	enemyH = 30;
	randomX = rand() % 1000;
	while (randomX >= 1000 - enemyW) 
	{
		randomX = rand() % 1000;
	}
	enemyX = randomX;
	randomWaitStart = rand() % 500;
	timeToWait = randomWaitStart;
	enemySprite.setWidth(randomWStart);
	enemySprite.load(renderer, "assests/FallingBrick.png");
}

void Enemy::Update(int* score, int* scoreMulti) 
{
	enemyY += 5;
	if (enemyY > 760 || collision) 
	{
		if (collision) 
		{
			*score -= 100;
		}
		else if (enemyY > 760)
		{
			*score += 5 * *scoreMulti;
		}
		randomX = rand() % 1000;
		randomX = rand() % 1000;
		while (randomX >= 1000 - enemyW)
		{
			randomX = rand() % 1000;
		}
		int randomWait = rand() % 500;
		enemyX = randomX;
		timeToWait = randomWait;
		enemyY = 20;
		collision = false;
		std::cout << *score << std::endl;
	}
	enemySprite.update();
}

void Enemy::Render(SDL_Renderer* renderer) 
{
	//std::cout << "oiueaqbfn";
	enemySprite.Render(renderer, enemyX, enemyY, SDL_FLIP_NONE);
	//SDL_SetRenderDrawColor(renderer, 247, 59, 128, 0);
	//SDL_RenderFillRect(renderer, &enemyRect);
}

void Enemy::Collisions(Player* newPlayer) 
{
	
	int enemyMaxX, enemyMinX, enemyMaxY, enemyMinY;
	int playerMaxX, playerMinX, playerMaxY, playerMinY;
	enemyMinX = enemyX;
	enemyMaxX = enemyX + enemyW;
	enemyMinY = enemyY;
	enemyMaxY = enemyY + enemyH;
	playerMinX = newPlayer->playerX;
	playerMaxX = newPlayer->playerX + newPlayer->playerW;
	playerMinY = newPlayer->playerY;
	playerMaxY = newPlayer->playerY + newPlayer->playerH;

	if (enemyMinX < playerMaxX && enemyMaxX > playerMinX && enemyMinY < playerMaxY && enemyMaxY > playerMinY)
	{
		//printf("WINNER!!!!! \n enemyMinX: %i < playerMaxX: %i \n enemyMaxX: %i > playerMinX: %i \n enemyMinY: %i < playerMaxY: %i \n enemyMaxY: %i > playerMinY: %i \n \n", enemyMinX, playerMaxX, enemyMaxX, playerMinX, enemyMinY, playerMaxY, enemyMaxY, playerMinY);
		collision = true;
		
	}
	else
	{
		//printf("enemyMinX: %i < playerMaxX: %i \n enemyMaxX: %i > playerMinX: %i \n enemyMinY: %i < playerMaxY: %i \n enemyMaxY: %i > playerMinY: %i \n \n", enemyMinX, playerMaxX, enemyMaxX, playerMinX, enemyMinY, playerMaxY, enemyMaxY, playerMinY);
	}
}