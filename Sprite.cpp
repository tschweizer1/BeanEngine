#include "Sprite.h"
#include <fstream>


Sprite::Sprite() {

}
Sprite::Sprite(std::string FileNameIn, SDL_Renderer* renderer, float x, float y) {

	filename = FileNameIn.c_str();
    SDL_Surface* loadedSurface = IMG_Load(Sprite::filename);
    if (!loadedSurface) {
        std::cout << "Failed to load sprite!" << std::endl;
        Quit();
        return;
    }
    spriteTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (!spriteTexture) {
        std::cout << "Failed to create texture!" << std::endl;
        SDL_DestroySurface(loadedSurface);
        Quit();
        return;
    }
    spriteRect = new SDL_FRect{
    x,
    y,
    static_cast<float>(loadedSurface->w),
    static_cast<float>(loadedSurface->h)
    };
    SDL_DestroySurface(loadedSurface);
}

Sprite::~Sprite() {
    
}
void Sprite::LoadSprite() {
    
}
void Sprite::MoveSprite(float x, float y) {
    spriteRect->x += x;
    spriteRect->y += y;
    if (spriteRect->x < 0.0f) spriteRect->x = 0.0f;
    if (spriteRect->y < 0.0f) spriteRect->y = 0.0f;
    if (spriteRect->x + spriteRect->w > WINDOW_WIDTH) spriteRect->x = WINDOW_WIDTH - spriteRect->w;
    if (spriteRect->y + spriteRect->h > WINDOW_HEIGHT) spriteRect->y = WINDOW_HEIGHT - spriteRect->h;
}
void Sprite::SetSpritePosition(float x, float y) {
    spriteRect->x = x;
    spriteRect->y = y;
    if (spriteRect->x < 0.0f) spriteRect->x = 0.0f;
    if (spriteRect->y < 0.0f) spriteRect->y = 0.0f;
    if (spriteRect->x + spriteRect->w > 800.0f) spriteRect->x = 800.0f - spriteRect->w;
    if (spriteRect->y + spriteRect->h > 600.0f) spriteRect->y = 600.0f - spriteRect->h;
}
SDL_Texture* Sprite::getTexture() {
    return spriteTexture;
}
SDL_FRect* Sprite::getRect() {
    return spriteRect;
}