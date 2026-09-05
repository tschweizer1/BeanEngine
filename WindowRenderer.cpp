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
Sprite* ball3;
SpriteRender* SpriteRenderer;
Camera* camera;
SDL_FRect* cameraBounds;
SDL_Rect screenBounds;



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
    
    screenBounds.x = cameraBounds->x;
    screenBounds.y = cameraBounds->y;
    SDL_LockTexture(GameTexture, &screenBounds, (void**)&pix, &pitch);
    for (int i = 0, sp = 0, dp = 0; i < cameraBounds->h; i++, dp += cameraBounds->w, sp += pitch)
        memcpy(pix + sp, gFrameBuffer + dp, cameraBounds->w * 4);

    SDL_UnlockTexture(GameTexture);
    SDL_RenderTexture(GameRenderer, GameTexture, NULL, NULL);
    SpriteRenderer->RenderSprites(camera);
    SDL_RenderPresent(GameRenderer);
    SDL_Delay(1000/FPS);
    return true;
}

//initializes the screen to all white
void init()
{
    camera = new Camera(GameTexture);
    cameraBounds = camera->getRect();
    screenBounds = SDL_Rect();
    screenBounds.w = cameraBounds->w;
    screenBounds.h = cameraBounds->h;
    int width = cameraBounds->w;
    int i, j;
    for (i = cameraBounds->y; i < cameraBounds->y + cameraBounds->h; i++)
    {
        for (j = cameraBounds->x; j < cameraBounds->x + cameraBounds->w; j++)
        {
            gFrameBuffer[i * width + j] = 0xffffffff;
        }
    }
    SpriteRenderer = new SpriteRender(GameTexture);
    ball = new Sprite("ball.png", GameRenderer, 100, 100, 0);
    SpriteRenderer->addSpriteToRender(ball);
    ball2 = new Sprite("ball2.png", GameRenderer, 500, 200, 1);
    SpriteRenderer->addSpriteToRender(ball2);
    ball3 = new Sprite("ball3.png", GameRenderer, 500, 200, 0);
    SpriteRenderer->addSpriteToRender(ball3);
}

void render(Uint64 aTicks)
{
    //ball->MoveSprite(1, 1);
    //ball2->MoveSprite(2, 2);
    camera->moveCamera(1, 1);
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
        std::cout << "big failure with sdl" << std::endl;
        return -1;
    }

    gFrameBuffer = new int[TEXTURE_WIDTH * TEXTURE_HEIGHT];
    if (!gFrameBuffer || !GameWindow || !GameRenderer || !GameTexture) {
        std::cout << "failure to create something important (texture, renderer, etc)" << std::endl;
        return -1;
    }
        
    init();
    Done = 0;

    while (!Done) {
        loop();
    }
    delete camera;
    delete SpriteRenderer;
    Quit();

    return 0;
}



