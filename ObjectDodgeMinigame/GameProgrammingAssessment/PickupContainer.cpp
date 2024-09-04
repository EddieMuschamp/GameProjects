#include "PickupContainer.h"

PickupContainer::PickupContainer(SDL_Renderer* currentRenderer)
{
	renderer = currentRenderer;
	pickupAmount = 5;
}

PickupContainer::~PickupContainer()
{

}

void PickupContainer::FillContainer()
{
	for (int i = 0; i < pickupAmount; i++)
	{
		Pickup* newPickup = new Pickup(renderer);
		pickupList.push_back(newPickup);
	}
}

void PickupContainer::UpdateAndRender(int* score, int* scoreMulti)
{
	for (Pickup* pickup : pickupList)
	{
		if (pickup->onCoolDown && pickup->activeTime > 0)
		{
			*scoreMulti = 2;
			pickup->activeTime -= 1;
		}
		if (pickup->activeTime <= 0)
		{
			pickup->activeTime = 300;
			pickup->onCoolDown = false;
			*scoreMulti = 1;
		}
		if (pickup->timeToWait <= 0)
		{
			pickup->Render(renderer);
			pickup->Update(score, scoreMulti);
		}
		else
		{
			pickup->timeToWait -= 1;
		}
	}
}

void PickupContainer::Collisions(Player* newPlayer)
{
	for (Pickup* pickup : pickupList)
	{
		pickup->Collisions(newPlayer);
	}
}
