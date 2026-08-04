#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "SDL3/SDL.h"
#include "SDL3/SDL_main.h"
#include "SDL3_image/SDL_image.h"
#include "Sprite.h"

SDL_Window* gSDLWindow;
SDL_Renderer* gSDLRenderer;
SDL_Texture* gSDLTexture;
int* gFrameBuffer;
int* gTempBuffer;
const double FPS = 60;
static int gDone;
Sprite *ball;



//checks if the user or event to quit has been triggered to end the loop, if still active locks the texture and renders in the new one
bool update()
{
    SDL_Event e;
    if (SDL_PollEvent(&e))
    {
        if (e.type == SDL_EVENT_QUIT)
        {
            return false;
        }
        if (e.type == SDL_EVENT_KEY_UP && e.key.key == SDLK_ESCAPE)
        {
            return false;
        }
    }
    char* pix;
    int pitch;

    SDL_LockTexture(gSDLTexture, NULL, (void**)&pix, &pitch);
    for (int i = 0, sp = 0, dp = 0; i < WINDOW_HEIGHT; i++, dp += WINDOW_WIDTH, sp += pitch)
        memcpy(pix + sp, gFrameBuffer + dp, WINDOW_WIDTH * 4);

    SDL_UnlockTexture(gSDLTexture);
    SDL_RenderTexture(gSDLRenderer, gSDLTexture, NULL, NULL);
    SDL_RenderTexture(gSDLRenderer, ball->getTexture(), nullptr, ball->getRect());
    SDL_RenderPresent(gSDLRenderer);
    SDL_Delay(1000/FPS);
    return true;
}

//initializes the screen to all white
void init()
{
    int x, y, n;

    int i, j;
    for (i = 0; i < WINDOW_HEIGHT; i++)
    {
        for (j = 0; j < WINDOW_WIDTH; j++)
        {
            gFrameBuffer[i * WINDOW_WIDTH + j] = 0xffffffff;
        }
    }
    ball = new Sprite("ball.png", gSDLRenderer, 100, 100);
    
    
    //std::cout << SDL_RenderPresent(gSDLRenderer) << std::endl;
}

void render(Uint64 aTicks)
{
    ball->MoveSprite(0.001 * aTicks, 0.001 * aTicks);
}

void loop()
{
    if (!update())
    {
        gDone = 1;
    }
    else
    {
        render(SDL_GetTicks());
    }
}

int main(int argc, char** argv)
{
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS))
    {
        return -1;
    }

    gFrameBuffer = new int[WINDOW_WIDTH * WINDOW_HEIGHT];
    gSDLWindow = SDL_CreateWindow("How peculiar", WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    gSDLRenderer = SDL_CreateRenderer(gSDLWindow, NULL);
    gSDLTexture = SDL_CreateTexture(gSDLRenderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING, WINDOW_WIDTH, WINDOW_HEIGHT);

    if (!gFrameBuffer || !gSDLWindow || !gSDLRenderer || !gSDLTexture)
        return -1;
    init();
    gDone = 0;

    while (!gDone) {
        loop();
    }
    SDL_DestroyTexture(gSDLTexture);
    SDL_DestroyRenderer(gSDLRenderer);
    SDL_DestroyWindow(gSDLWindow);
    SDL_Quit();

    return 0;
}



