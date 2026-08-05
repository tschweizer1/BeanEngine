#include "SpriteRender.h"

SpriteRender::SpriteRender() {
	spriteList = new std::list<Sprite*>;
}
SpriteRender::~SpriteRender() {

}

void SpriteRender::RenderSprites() {
	for (Sprite* s : *spriteList) {
		SDL_RenderTexture(GameRenderer, s->getTexture(), NULL, s->getRect());
	}
}

void SpriteRender::addSpriteToRender(Sprite* s) {
	spriteList->push_back(s);
	std::cout << spriteList << std::endl;
}