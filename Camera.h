#include "Global.h"

class Camera {
public:
	Camera(SDL_Texture* texture);
	~Camera();
	void moveCamera(float x, float y);
	void renderCameraView();
	bool containsSprite(SDL_FRect* spriteRect);
	SDL_FRect* getRect();
private:
	SDL_FRect* copyRect;
	SDL_Texture* targetTexture;
};
