#include "Sprite.h"
#include "SDL_Image.h"	
#include <iostream>

// constructor that takes X,Y position and width/height values for sprite (src Rect will be calculated from them based on current frame)
// X is the starting X position, Y is the starting Y position to draw on screen. Width and Height are the size of a single frame of the sprite
// todo: think if we need to add more data here? Should we have scale? Should we have an offset value?? (so the sprite is centered at X,Y)
Sprite::Sprite(int widthPixels, int heightPixels, int frames)
{
	frameWidthPixels = widthPixels;
	frameHeightPixels = heightPixels;
	frameIndex = 0;
	numberOfFrames = frames;
	
}

// here you should safely handle any memory you allocated.. remember you are loading textures? Do they need cleaning up?
Sprite::~Sprite()
{
	if (texture != nullptr)
	{
		SDL_DestroyTexture(texture);
	}
}

// render the sprite to the current renderer using the current X,Y positions based on the current FrameIndex we are at
// usually you'd calculate your X,Y and scaled width and height in update, here you'd use the SDL_Rect values you've calculated
// to call SDL_RenderCopy to actually do the rendering. See slides for info.
void Sprite::Render(SDL_Renderer* renderer, int X, int Y, SDL_RendererFlip flip)
{
	SDL_Rect dest = { X, Y, frameWidthPixels, frameHeightPixels };
	SDL_RenderCopyEx(renderer, texture, &src, &dest, 0, NULL, flip);
}

// this function should handle the logic of choosing the "source rectangle" srcRect, easy version is to follow the modulo % math given in the slides
// but that results in only playing a single sequence. Far better to expand on this and create your own sprite class!
void Sprite::update()
{
	//Get the number of ticks.. we'll use this to calculate what frame number we should be at
	unsigned int ticks = SDL_GetTicks();
	//The delay between changing frames -- this will change the texture every 200ms.
	unsigned int changeTimeMS = 200;
	//Calculate frame index -- this is just (time / change) mod frameCount
	unsigned int frameIndex = (ticks / changeTimeMS) % numberOfFrames;

	int calcX = (frameWidthPixels * frameIndex);

	src = { calcX, 0, frameWidthPixels, frameHeightPixels };

}

// load the texture (see lecture slides), colour key is usually not required for PNG with alpha channel (RGBA images)
// the "colour key" is essentially the first pixel (top left of the image) and is considered transparent when we don't have alpha channels (RGB images)
// its a bit old school, but some sprite sheets come with no alpha, so this is the convention to draw them properly
// note we need to pass the current SDL Renderer pointer into this function so that image functions work correctly for texture creation
// Note: In the case of using a colour key, we will likely want to use IMG_Load and store a temporary SDL_Surface * so we can then use SDL_SetColorKey on that
// surface before calling SDL_CreateTextureFromSurface
// If we don't need colour keying, we can simply call IMG_LoadTexture
void Sprite::load(SDL_Renderer* renderer, const char* path, bool bUseColourKey)
{
	/*
	Check if there is a colour key in use (bUseColourKey), if there is use IMG_Load etc.. if not, using IMG_LoadTexture
	Check out the SDL2_Image api reference for information on those..
	*/

	SDL_Surface* surface = IMG_Load(path);
	if (surface == NULL)
	{
		printf("Surface Null");
	}
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}

// simple setter
void Sprite::setNumberOfFrames(unsigned int framecount)
{
	numberOfFrames = framecount;
}
// simple setter
void Sprite::setAnimationSpeed(unsigned int speed)
{
	animationSpeed = speed;
}

void Sprite::setWidth(int newWidth)
{
	frameWidthPixels = newWidth;
}

void Sprite::setHeight(int newHeight)
{
	frameHeightPixels = newHeight;
}

void Sprite::setFrames(int newFrames)
{
	numberOfFrames = newFrames;
}



