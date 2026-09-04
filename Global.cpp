#include "Global.h"
#include <iostream>

SDL_Window* GameWindow = SDL_CreateWindow("How peculiar", WINDOW_WIDTH, WINDOW_HEIGHT, 0);
SDL_Renderer* GameRenderer = SDL_CreateRenderer(GameWindow, NULL);
SDL_Texture* GameTexture = SDL_CreateTexture(GameRenderer, SDL_PIXELFORMAT_ABGR8888, (SDL_TEXTUREACCESS_STREAMING | SDL_TEXTUREACCESS_TARGET), TEXTURE_WIDTH, TEXTURE_HEIGHT);

void Quit() {
    std::cout << "Quitting" << std::endl;
    SDL_DestroyTexture(GameTexture);
    SDL_DestroyRenderer(GameRenderer);
    SDL_DestroyWindow(GameWindow);
    SDL_Quit();
    std::exit(0);
}