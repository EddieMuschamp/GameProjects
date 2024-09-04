#include "Pickup.h"

Pickup::Pickup(SDL_Renderer* renderer)
{
	activeTime = 300;
	onCoolDown = false;
	pickupY = 20;
	pickupW = 30;
	pickupH = 30;
	randomX = rand() % 1000;
	while (randomX >= 1000 - pickupW)
	{
		randomX = rand() % 1000;
	}
	pickupX = randomX;
	randomWaitStart = rand() % 100;
	timeToWait = randomWaitStart;
	pickupSprite.setWidth(pickupW);
	pickupSprite.load(renderer, "assests/x2points.png");
}

void Pickup::Update(int* score, int* scoreMulti)
{
	pickupY += 5;
	if (pickupY > 760 || collision)
	{
		randomX = rand() % 1000;
		while (randomX >= 1000 - pickupW)
		{
			randomX = rand() % 1000;
		}
		int randomWait = rand() % 100;
		timeToWait = randomWait;
		pickupX = randomX;
		pickupY = 20;
		collision = false;
	}
	pickupSprite.update();
}

void Pickup::Render(SDL_Renderer* renderer)
{
	//std::cout << "oiueaqbfn";
	pickupSprite.Render(renderer, pickupX, pickupY, SDL_FLIP_NONE);
	//SDL_SetRenderDrawColor(renderer, 247, 59, 128, 0);
	//SDL_RenderFillRect(renderer, &PickupRect);
}

void Pickup::Collisions(Player* newPlayer)
{

	int pickupMaxX, pickupMinX, pickupMaxY, pickupMinY;
	int playerMaxX, playerMinX, playerMaxY, playerMinY;
	pickupMinX = pickupX;
	pickupMaxX = pickupX + pickupW;
	pickupMinY = pickupY;
	pickupMaxY = pickupY + pickupH;
	playerMinX = newPlayer->playerX;
	playerMaxX = newPlayer->playerX + newPlayer->playerW;
	playerMinY = newPlayer->playerY;
	playerMaxY = newPlayer->playerY + newPlayer->playerH;

	if (pickupMinX < playerMaxX && pickupMaxX > playerMinX && pickupMinY < playerMaxY && pickupMaxY > playerMinY)
	{
		collision = true;
		onCoolDown = true;
	}
}