#include "Camera.h"

Camera::Camera(SDL_Texture* texture) {
	targetTexture = texture;
	copyRect = new SDL_FRect{
		0,
		0,
		WINDOW_WIDTH,
		WINDOW_HEIGHT
	};

}

Camera::~Camera() {
	delete copyRect;
}

void Camera::moveCamera(float x, float y) {
	copyRect->x += x;
	copyRect->y += y;
}

void Camera::renderCameraView() {
	SDL_SetRenderTarget(GameRenderer, NULL);
	SDL_RenderTexture(GameRenderer, targetTexture, copyRect, NULL);
}