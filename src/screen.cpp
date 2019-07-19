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

  return true;
}

void screen::update()
{
  SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, texture, NULL, NULL);
  SDL_RenderPresent(renderer);
}

void screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue)
{
  Uint32 color = 0;
  color += red;
  color <<= 8;
  color += green;
  color <<= 8;
  color += blue;
  color <<= 8;
  color += 0xFF;
  buffer[(y * SCREEN_WIDTH) + x] = color;
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