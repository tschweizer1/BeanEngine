#include "Global.h"

class Camera {
public:
	Camera(SDL_Texture* texture);
	~Camera();
	void moveCamera(float x, float y);
	void renderCameraView();
private:
	SDL_FRect* copyRect;
	SDL_Texture* targetTexture;
};
