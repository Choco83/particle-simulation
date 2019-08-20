#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL2/SDL.h>

class Screen
{
public:
  const int SCREEN_WIDTH = 800;
  const int SCREEN_HEIGHT = 600;
  Screen();
  bool init();
  void close();
  bool processEvents();
  void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
  void update();
  void clear();
  void blur();

private:
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Texture *texture;
  Uint32 *buffer;
  Uint32 *blur_buffer;
};

#endif