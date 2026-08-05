#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "SDL3/SDL_main.h"
#include "SDL3_image/SDL_image.h"
#include "Sprite.h"
#include "SpriteRender.h"
int* gFrameBuffer;
int* gTempBuffer;
Sprite* ball;
Sprite* ball2;
SpriteRender* SpriteRenderer;



//checks if the user or event to quit has been triggered to end the loop, if still active locks the texture and renders in the new one
bool update()
{
    SDL_Event e;
    if (Done == 1 || SDL_PollEvent(&e))
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

    SDL_LockTexture(GameTexture, NULL, (void**)&pix, &pitch);
    for (int i = 0, sp = 0, dp = 0; i < WINDOW_HEIGHT; i++, dp += WINDOW_WIDTH, sp += pitch)
        memcpy(pix + sp, gFrameBuffer + dp, WINDOW_WIDTH * 4);

    SDL_UnlockTexture(GameTexture);
    SDL_RenderTexture(GameRenderer, GameTexture, NULL, NULL);
    SpriteRenderer->RenderSprites();
    SDL_RenderPresent(GameRenderer);
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
    SpriteRenderer = new SpriteRender();
    ball = new Sprite("ball.png", GameRenderer, 100, 100);
    SpriteRenderer->addSpriteToRender(ball);
    ball2 = new Sprite("ball.png", GameRenderer, 500, 200);
    SpriteRenderer->addSpriteToRender(ball2);
}

void render(Uint64 aTicks)
{
    ball->MoveSprite(0.001 * aTicks, 0.001 * aTicks);
    ball2->MoveSprite(0.001 * aTicks, 0.001 * aTicks);
}

void loop()
{
    if (!update())
    {
        Done = 1;
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
    

    if (!gFrameBuffer || !GameWindow || !GameRenderer || !GameTexture)
        return -1;
    init();
    Done = 0;

    while (!Done) {
        loop();
    }
    Quit();

    return 0;
}



