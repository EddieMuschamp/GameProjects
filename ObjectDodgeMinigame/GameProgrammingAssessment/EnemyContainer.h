#ifndef anEnemyContainer
#define anEnemyContainer
#include <vector>
#include <iostream>
#include "SDL.h"
#include "Enemy.h"

class EnemyContainer
{
private:
	SDL_Renderer* renderer;
	int enemyAmount;
public:
	std::vector<Enemy*> enemyList;
	EnemyContainer(SDL_Renderer* currentRenderer);
	~EnemyContainer();
	void FillContainer();
	void UpdateAndRender(int *score, int *scoreMulti);
	void Collisions(Player* newPlayer);
};


#endif