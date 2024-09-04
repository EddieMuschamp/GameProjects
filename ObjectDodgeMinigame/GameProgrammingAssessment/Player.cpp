#include "Player.h"

Player::Player(SDL_Renderer* renderer)
{
	playerX = 500;
	playerY = 700;
	playerW = 17;
	playerH = 18;
	moveLeft = false;
	moveRight = false;
	playerSprite.setWidth(playerW);
	playerSprite.setHeight(playerH);
	playerSprite.setFrames(4);
	playerSprite.load(renderer, "assests/spritesheet.png");
}


void Player::Render(SDL_Renderer* renderer) 
{
	if (moveLeft)
	{
		playerSprite.Render(renderer, playerX, playerY, SDL_FLIP_NONE);
	}
	else 
	{
		playerSprite.Render(renderer, playerX, playerY, SDL_FLIP_HORIZONTAL);
	}
	
}

void Player::Update()
{
	if (moveLeft)
	{
		playerX -= 10;
	}
	if (moveRight)
	{
		playerX += 10;
	}
	if (playerX < 0) 
	{
		playerX = 0;
	}
	if (playerX > 983) 
	{
		playerX = 983;
	}
	playerSprite.update();
}

void Player::Input(int whichKey)
{
	moveLeft = false;
	moveRight = false;

	switch (whichKey)
	{
	case SDLK_a: {moveLeft = true;  break; }
	case SDLK_d: {moveRight = true; break; }
	}
	
}