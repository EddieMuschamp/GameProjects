#include "EnemyContainer.h"


EnemyContainer::EnemyContainer(SDL_Renderer* currentRenderer)
{
	renderer = currentRenderer;
	enemyAmount = 400;
}

EnemyContainer::~EnemyContainer() 
{

}

void EnemyContainer::FillContainer() 
{
	for (int i = 0; i < enemyAmount; i++) 
	{
		Enemy* newEnemy = new Enemy(renderer);
		enemyList.push_back(newEnemy);
	}
}

void EnemyContainer::UpdateAndRender(int* score, int* scoreMulti) 
{
	for (Enemy* enemy : enemyList) 
	{
		if (enemy->timeToWait <= 0)
		{
			enemy->Render(renderer);
			enemy->Update(score, scoreMulti);


		}
		else
		{
			enemy->timeToWait -= 1;
		}
	}
}

void EnemyContainer::Collisions(Player* newPlayer) 
{
	for (Enemy* enemy : enemyList)
	{
		enemy->Collisions(newPlayer);
	}
}
