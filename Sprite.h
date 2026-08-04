#ifndef SPRITE_H
#define SPRITE_H
#include <iostream>
#include <string>
#include "SDL3_image/SDL_image.h"
#include "Global.h"

class Sprite {

public:
	Sprite(std::string FileNameIn, SDL_Renderer* renderer, float x, float y);
	Sprite();
	~Sprite();
	void LoadSprite();
	void MoveSprite(float x, float y);
	void SetSpritePosition(float x, float y);
	SDL_Texture* getTexture();
	SDL_FRect* getRect();

private:
	const char* filename;
	SDL_Texture* spriteTexture;
	SDL_FRect* spriteRect;
}
#endif
;