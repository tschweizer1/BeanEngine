#include "SpriteRender.h"

SpriteRender::SpriteRender(SDL_Texture* texture) {
	spriteList = new std::list<Sprite*>;
	targetTexture = texture;
}
SpriteRender::~SpriteRender() {

}

void SpriteRender::RenderSprites() {
	SDL_SetRenderTarget(GameRenderer, targetTexture);
	for (Sprite* s : *spriteList) {
		SDL_RenderTexture(GameRenderer, s->getTexture(), NULL, s->getRect());
	}
	SDL_SetRenderTarget(GameRenderer, NULL);
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