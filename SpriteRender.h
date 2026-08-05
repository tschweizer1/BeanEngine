#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H
#include "Sprite.h"
#include <list>
#include <iostream>

class SpriteRender {

public:
	SpriteRender();
	~SpriteRender();
	void RenderSprites();
	void addSpriteToRender(Sprite* s);

private:
	std::list<Sprite*>* spriteList;
}



#endif
;