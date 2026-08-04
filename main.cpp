//#include <string.h>
//#include <math.h>
//#include <stdlib.h>
//#ifdef __EMSCRIPTEN__
//#include <emscripten/emscripten.h>
//#endif
//#include "SDL3/SDL.h"
//#include "SDL3/SDL_main.h"
//#define TREECOUNT 64
//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"
//
//float gTreeCoord[TREECOUNT * 2];
//int* gFrameBuffer;
//int* gTempBuffer;
//SDL_Window* gSDLWindow;
//SDL_Renderer* gSDLRenderer;
//SDL_Texture* gSDLTexture;
//static int gDone;
//const int WINDOW_WIDTH = 1920 / 2;
//const int WINDOW_HEIGHT = 1080 / 2;
//const int WINDOW_MIN = fmin(WINDOW_WIDTH, WINDOW_HEIGHT);
//// Look-up table
//unsigned short* gLut;
//// Texture
//int* gTexture;
//
//bool update()
//{
//    SDL_Event e;
//    if (SDL_PollEvent(&e))
//    {
//        if (e.type == SDL_EVENT_QUIT)
//        {
//            return false;
//        }
//        if (e.type == SDL_EVENT_KEY_UP && e.key.key == SDLK_ESCAPE)
//        {
//            return false;
//        }
//    }
//
//    char* pix;
//    int pitch;
//
//    SDL_LockTexture(gSDLTexture, NULL, (void**)&pix, &pitch);
//    for (int i = 0, sp = 0, dp = 0; i < WINDOW_HEIGHT; i++, dp += WINDOW_WIDTH, sp += pitch)
//        memcpy(pix + sp, gFrameBuffer + dp, WINDOW_WIDTH * 4);
//
//    SDL_UnlockTexture(gSDLTexture);
//    SDL_RenderTexture(gSDLRenderer, gSDLTexture, NULL, NULL);
//    SDL_RenderPresent(gSDLRenderer);
//    SDL_Delay(1);
//    return true;
//}
//#define PI 3.1415926535897932384626433832795
//
//void drawcircle(int x, int y, int r, int c)
//{
//    for (int i = 0; i < 2 * r; i++)
//    {
//        // vertical clipping: (top and bottom)
//        if ((y - r + i) >= 0 && (y - r + i) < WINDOW_HEIGHT)
//        {
//            int len = (int)(sqrt(r * r - (r - i) * (r - i)) * 2);
//            int xofs = x - len / 2;
//
//            // left border
//            if (xofs < 0)
//            {
//                len += xofs;
//                xofs = 0;
//            }
//
//            // right border
//            if (xofs + len >= WINDOW_WIDTH)
//            {
//                len -= (xofs + len) - WINDOW_WIDTH;
//            }
//            int ofs = (y - r + i) * WINDOW_WIDTH + xofs;
//
//            // note that len may be 0 at this point, 
//            // and no pixels get drawn!
//            for (int j = 0; j < len; j++)
//                gFrameBuffer[ofs + j] = c;
//        }
//    }
//}
///*void putpixel(int x, int y, int color)
//{
//    if (x < 0 ||
//        y < 0 ||
//        x >= WINDOW_WIDTH ||
//        y >= WINDOW_HEIGHT)
//    {
//        return;
//    }
//    gFrameBuffer[y * WINDOW_WIDTH + x] = color;
//} */
//const unsigned char sprite[] =
//{
//0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,
//0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,
//0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,
//0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
//0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
//0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
//1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
//1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
//1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
//1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
//0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
//0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
//0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
//0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,
//0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,
//0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0
//};
//void drawsprite(int x, int y, unsigned int color)
//{
//    int i, j, c, yofs;
//    yofs = y * WINDOW_WIDTH + x;
//    for (i = 0, c = 0; i < 16; i++)
//    {
//        for (j = 0; j < 16; j++, c++)
//        {
//            if (sprite[c])
//            {
//                gFrameBuffer[yofs + j] = color;
//            }
//        }
//        yofs += WINDOW_WIDTH;
//    }
//}
//void init()
//{
//    int x, y, n;
//    gTexture = (int*)stbi_load("tunneltexture.png", &x, &y, &n, 4);
//    gLut = new unsigned short[WINDOW_WIDTH * WINDOW_HEIGHT];
//
//    int i, j;
//    for (i = 0; i < WINDOW_HEIGHT; i++)
//    {
//        for (j = 0; j < WINDOW_WIDTH; j++)
//        {
//            int xdist = j - (WINDOW_WIDTH / 2);
//            int ydist = i - (WINDOW_HEIGHT / 2);
//
//            int distance = (int)sqrt((float)(xdist * xdist + ydist * ydist));
//
//            if (distance > 0)
//                distance = (64 * 256 / distance) & 0xff;
//
//            int angle = (int)(((atan2((float)xdist, (float)ydist) / PI) + 1.0f) * 128);
//
//            gLut[i * WINDOW_WIDTH + j] = (distance << 8) + angle;
//        }
//    }
//}
//
//void render(Uint64 aTicks)
//{
//    for (int i = 0; i < WINDOW_HEIGHT; i++)
//    {
//        for (int j = 0; j < WINDOW_WIDTH; j++)
//        {
//            int lut = gLut[i * WINDOW_WIDTH + j];
//            gFrameBuffer[j + i * WINDOW_WIDTH] =
//                gTexture[((lut + aTicks / 32) & 0xff) +
//                (((lut >> 8) + aTicks / 8) & 0xff) * 256];
//        }
//    }
//}
//
//void loop()
//{
//    if (!update())
//    {
//        gDone = 1;
//#ifdef __EMSCRIPTEN__
//        emscripten_cancel_main_loop();
//#endif
//    }
//    else
//    {
//        render(SDL_GetTicks());
//    }
//}
//
//int main(int argc, char** argv)
//{
//    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS))
//    {
//        return -1;
//    }
//
//    gFrameBuffer = new int[WINDOW_WIDTH * WINDOW_HEIGHT];
//    gSDLWindow = SDL_CreateWindow("How peculiar", WINDOW_WIDTH, WINDOW_HEIGHT, 0);
//    gSDLRenderer = SDL_CreateRenderer(gSDLWindow, NULL);
//    gSDLTexture = SDL_CreateTexture(gSDLRenderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING, WINDOW_WIDTH, WINDOW_HEIGHT);
//
//    if (!gFrameBuffer || !gSDLWindow || !gSDLRenderer || !gSDLTexture)
//        return -1;
//    init();
//    gDone = 0;
//#ifdef __EMSCRIPTEN__
//    emscripten_set_main_loop(loop, 0, 1);
//#else
//    while (!gDone)
//    {
//        loop();
//    }
//#endif
//
//    SDL_DestroyTexture(gSDLTexture);
//    SDL_DestroyRenderer(gSDLRenderer);
//    SDL_DestroyWindow(gSDLWindow);
//    SDL_Quit();
//
//    return 0;
//}