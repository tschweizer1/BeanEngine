#include "Sprite.h"
#include <fstream>


Sprite::Sprite(std::string FileNameIn, SDL_Renderer* renderer, float x, float y) {
	filename = FileNameIn;
    SDL_Surface* loadedSurface = IMG_Load(Sprite::filename.c_str());
    if (!loadedSurface) {
        std::cout << SDL_GetError() << std::endl;
        std::cout << "Failed to load sprite!" << std::endl;
        Quit();
        return;
    }
    spriteTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (!spriteTexture) {
        std::cout << SDL_GetError() << std::endl;
        std::cout << "Failed to create texture!" << std::endl;
        SDL_DestroySurface(loadedSurface);
        Quit();
        return;
    }
    spriteRect = SDL_FRect{
    x,
    y,
    static_cast<float>(loadedSurface->w),
    static_cast<float>(loadedSurface->h)
    };
    layer = 0;
    SDL_DestroySurface(loadedSurface);
}
Sprite::Sprite(std::string FileNameIn, SDL_Renderer* renderer, float x, float y, int layer) {
    filename = FileNameIn;
    SDL_Surface* loadedSurface = IMG_Load(Sprite::filename.c_str());
    if (!loadedSurface) {
        std::cout << SDL_GetError() << std::endl;
        std::cout << "Failed to load sprite!" << std::endl;
        Quit();
        return;
    }
    spriteTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (!spriteTexture) {
        std::cout << SDL_GetError() << std::endl;
        std::cout << "Failed to create texture!" << std::endl;
        SDL_DestroySurface(loadedSurface);
        Quit();
        return;
    }
    spriteRect = SDL_FRect{
    x,
    y,
    static_cast<float>(loadedSurface->w),
    static_cast<float>(loadedSurface->h)
    };
    Sprite::layer = layer;
    SDL_DestroySurface(loadedSurface);
}
Sprite::~Sprite() {
    SDL_DestroyTexture(spriteTexture);
}
std::string Sprite::toString() {
    return (filename);
}
void Sprite::LoadSprite() {
    
}
void Sprite::MoveSprite(float x, float y) {
    spriteRect.x += x;
    spriteRect.y += y;
}
void Sprite::SetSpritePosition(float x, float y) {
    spriteRect.x = x;
    spriteRect.y = y;
}
SDL_Texture* Sprite::getTexture() {
    return spriteTexture;
}
SDL_FRect* Sprite::getRect() {
    return &spriteRect;
}
int Sprite::getLayer() {
    return layer;
}