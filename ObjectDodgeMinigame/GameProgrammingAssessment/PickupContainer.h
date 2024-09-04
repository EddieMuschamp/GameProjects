#ifndef aPickupContainer
#define aPickupContainer
#include <vector>
#include <iostream>
#include "SDL.h"
#include "Pickup.h"

class PickupContainer
{
private:
	SDL_Renderer* renderer;
	int pickupAmount;
public:
	std::vector<Pickup*> pickupList;
	PickupContainer(SDL_Renderer* currentRenderer);
	~PickupContainer();
	void FillContainer();
	void UpdateAndRender(int* score, int* scoreMulti);
	void Collisions(Player* newPlayer);
};


#endif