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
	for (Sprite* s : *spriteList) {
		if (camera->containsSprite(s->getRect())){
			SDL_FRect placement = SDL_FRect{ s->getRect()->x - camera->getRect()->x, s->getRect()->y - camera->getRect()->y, s->getRect()->w, s->getRect()->h };
			if (!SDL_RenderTexture(GameRenderer, s->getTexture(), NULL, &placement)) {
				std::cout << SDL_GetError() << std::endl;
				std::cout << "sprites failing to render " << s->toString() << " Rect: " << placement.x << ", " << placement.y << ", " << placement.w << ", " << placement.h << std::endl;
			}
		}
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