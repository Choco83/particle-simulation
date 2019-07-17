#include <iostream>
#include "../include/screen.h"

using namespace std;

screen::screen() : window(NULL),
                   renderer(NULL),
                   texture(NULL),
                   buffer(NULL){};

bool screen::init()
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    cout << "SDL init failed\n";
    return false;
  }
  window = SDL_CreateWindow("particle simulation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
  texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

  if (renderer == NULL)
    cout << "could not create renderer\n";

  if (texture == NULL)
    cout << "could not create texture\n";

  if (window == NULL)
  {
    SDL_Quit();
    return false;
  }

  buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
  memset(buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

  for (int i = 0; i < SCREEN_HEIGHT * SCREEN_WIDTH; i++)
  {
    if (i % 2 == 0)
      buffer[i] = 0x0000FF00;
    else
      buffer[i] = 0x00000000;
  }

  SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, texture, NULL, NULL);
  SDL_RenderPresent(renderer);
  return true;
}

void screen::close()
{
  delete[] buffer;
  SDL_DestroyRenderer(renderer);
  SDL_DestroyTexture(texture);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

bool screen::processEvents()
{
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    if (event.type == SDL_QUIT)
    {
      return false;
    }
  }
  return true;
};