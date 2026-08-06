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
	
	std::list<Sprite*>::iterator it = spriteList->begin();
	for (Sprite* sprite : *spriteList) {
		if (sprite->getLayer() > s->getLayer()) {
			break;
		}
		else {
			it++;
		}
	}
	spriteList->insert(it, s);
}