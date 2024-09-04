#ifndef aSprite
#define aSprite
#include "SDL.h"

class Sprite
{
public:
	Sprite(int widthPixels = 0, int heightPixels = 30, int frames = 1);
	~Sprite();

	// you might need to rename these functions to work with your own code.. don't forget to update the CPP file too!
	void Render(SDL_Renderer* renderer, int playerX, int playerY, SDL_RendererFlip flip);
	void update();
	void load(SDL_Renderer* renderer, const char* path, bool bUseColourKey = false);
	void setNumberOfFrames(unsigned int framecount);
	void setAnimationSpeed(unsigned int speed);
	void setWidth(int newWidth);
	void setHeight(int newHeight);
	void setFrames(int newFrames);

	// x and y position of the sprite in screen space
	int x, y = 0;
	// width and height of the sprite within the source texture
	int frameWidthPixels, frameHeightPixels = 0;
	// optional, scale the destination sprite during rendering
	int xscale, yscale = 1;
protected:
	SDL_Texture* texture = nullptr;	// pointer to an SDL_Texture, always initialize your pointers to either NULL or nullptr
	//SDL_Rect srcRect;					// this is the source rectangle where we will copy the sprite from within the texture
	unsigned int numberOfFrames;	// how many frames of animation?
	unsigned int animationSpeed = 100;	// how many milliseconds between each frame of animation?
	unsigned int frameIndex = 0;	 // which frame are we currently on?
	SDL_Rect src;
};


#endif
