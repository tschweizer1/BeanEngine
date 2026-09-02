#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H
#include "Sprite.h"
#include "Camera.h"
#include <list>
#include <iostream>

class SpriteRender {

public:
	SpriteRender(SDL_Texture* texture);
	~SpriteRender();
	void RenderSprites(Camera* camera);
	void addSpriteToRender(Sprite* s);

private:
	std::list<Sprite*>* spriteList;
	SDL_Texture* targetTexture;
}



#endif
;