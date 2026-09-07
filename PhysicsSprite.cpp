#include "PhysicsSprite.h"

PhysicsSprite::PhysicsSprite(std::string FileNameIn, SDL_Renderer* renderer, float x, float y) : Sprite(FileNameIn, renderer, x, y), speed(0) {

}

PhysicsSprite::PhysicsSprite(std::string FileNameIn, SDL_Renderer* renderer, float x, float y, int layer) : Sprite(FileNameIn, renderer, x, y, layer), speed(0) {

}

PhysicsSprite::PhysicsSprite(std::string FileNameIn, SDL_Renderer* renderer, float x, float y, float speedIn) : Sprite(FileNameIn, renderer, x, y), speed(speedIn) {

}

PhysicsSprite::PhysicsSprite(std::string FileNameIn, SDL_Renderer* renderer, float x, float y, int layer, float speedIn) : Sprite(FileNameIn, renderer, x, y, layer), speed(speedIn) {

}


void PhysicsSprite::update() {
	MoveSprite(0, 100 * DeltaTime);
}
