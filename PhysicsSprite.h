#ifndef PHYSICSSPRITE_H
#define PHYSICSSPRITE_H
#include <iostream>
#include <string>
#include "SDL3_image/SDL_image.h"
#include "Global.h"
#include "Sprite.h"

class PhysicsSprite : public Sprite {

public:
	PhysicsSprite(std::string FileNameIn, SDL_Renderer* renderer, float x, float y);
	PhysicsSprite(std::string FileNameIn, SDL_Renderer* renderer, float x, float y, int layer);
	PhysicsSprite(std::string FileNameIn, SDL_Renderer* renderer, float x, float y, float speed);
	PhysicsSprite(std::string FileNameIn, SDL_Renderer* renderer, float x, float y, int layer, float speed);
	void update();

private:
	float speed;
}
#endif
;