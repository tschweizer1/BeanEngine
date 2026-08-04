#include "SDL3/SDL.h"

const int WINDOW_WIDTH = 1920 / 2;
const int WINDOW_HEIGHT = 1080 / 2;
const double FPS = 60;
static int Done;
extern SDL_Window* GameWindow;
extern SDL_Renderer* GameRenderer;
extern SDL_Texture* GameTexture;
extern void Quit();