#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL2/SDL.h>

class screen
{
public:
  const int SCREEN_WIDTH = 800;
  const int SCREEN_HEIGHT = 600;
  screen();
  bool init();
  void close();
  bool processEvents();

private:
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Texture *texture;
  Uint32 *buffer;
};

#endif