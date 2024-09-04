#ifndef aPlayer
#define aPlayer
#include <SDL.h>
#include "Sprite.h"
#include <iostream>

class Player
{
protected:
	bool moveLeft;
	bool moveRight;
	Sprite playerSprite;
public:
	int playerX, playerY, playerW, playerH;
	Player(SDL_Renderer* renderer);
	void Update();
	void Render(SDL_Renderer* renderer);
	void Input(int whichKey);
};

#endif