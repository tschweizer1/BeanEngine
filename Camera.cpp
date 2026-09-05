#include "Camera.h"

Camera::Camera(SDL_Texture* texture) {
	targetTexture = texture;
	copyRect = SDL_FRect{
		0,
		0,
		WINDOW_WIDTH,
		WINDOW_HEIGHT
	};

}

Camera::~Camera() {

}

void Camera::moveCamera(float x, float y) {
	copyRect.x += x;
	copyRect.y += y;
}

bool Camera::containsSprite(SDL_FRect* spriteRect) {
	//x,y coord top left corner of FRect, y and x increase down and right
	//checks if left side of sprite rectangle is inside the camera rectangle
	if (spriteRect->x > copyRect.x && spriteRect->x < (copyRect.x + copyRect.w)) {
		//checks if the top left corner is within the camera rectangle
		if (spriteRect->y > copyRect.y && spriteRect->y < (copyRect.y + copyRect.h)) {
			return true;
		}
		//checks if the bottom left corner is within the camera rectangle
		if ((spriteRect->y + spriteRect->h) > copyRect.y && (spriteRect->y + spriteRect->h) < (copyRect.y + copyRect.h)) {
			return true;
		}
	}
	//checks if the right side of the rectangle is inside the camera rectangle
	if ((spriteRect->x + spriteRect->w) > copyRect.x && (spriteRect->x + spriteRect->w) < (copyRect.x + copyRect.w)) {
		//checks if the top right corner is within the camera rectangle
		if (spriteRect->y > copyRect.y && spriteRect->y < (copyRect.y + copyRect.h)) {
			return true;
		}
		//checks if the bottom right corner is within the camera rectangle
		if ((spriteRect->y + spriteRect->h) > copyRect.y && (spriteRect->y + spriteRect->h) < (copyRect.y + copyRect.h)) {
			return true;
		}
	}

	return false;
}

SDL_FRect* Camera::getRect() {
	return &copyRect;
}