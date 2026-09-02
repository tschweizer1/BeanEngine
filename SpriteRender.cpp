#include "SpriteRender.h"

SpriteRender::SpriteRender(SDL_Texture* texture) {
	spriteList = new std::list<Sprite*>;
	targetTexture = texture;
}
SpriteRender::~SpriteRender() {

	for (Sprite* s : *spriteList) {
		delete s;
	}
	delete spriteList;
}

void SpriteRender::RenderSprites(Camera* camera) {
	SDL_SetRenderTarget(GameRenderer, targetTexture);
	for (Sprite* s : *spriteList) {
		if (camera->containsSprite(s->getRect())) {
			SDL_RenderTexture(GameRenderer, s->getTexture(), NULL, s->getRect());
		}
	}
	SDL_SetRenderTarget(GameRenderer, NULL);
	camera->renderCameraView();
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