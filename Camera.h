#include "Global.h"
#include <iostream>

class Camera {
public:
	Camera(SDL_Texture* texture);
	~Camera();
	void moveCamera(float x, float y);
	bool containsSprite(SDL_FRect* spriteRect);
	SDL_FRect* getRect();
private:
	SDL_FRect copyRect;
	SDL_Texture* targetTexture;
};
