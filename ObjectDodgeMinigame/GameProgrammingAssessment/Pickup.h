#ifndef aPickup
#define aPickup
#include "SDL.h"
#include "Sprite.h"
#include "Player.h"

class Pickup
{
private:
	int pickupX, pickupY, pickupW, pickupH;
	int randomWaitStart;
	int randomX;
	Sprite pickupSprite;
	bool collision = false;

public:
	int timeToWait;
	int activeTime;
	bool onCoolDown;
	Pickup(SDL_Renderer* renderer);
	void Update(int* score, int* scoreMulti);
	void Render(SDL_Renderer* renderer);
	void Collisions(Player* newPlayer);
};

#endif