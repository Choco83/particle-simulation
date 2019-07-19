#include <iostream>
#include <SDL2/SDL.h>
#include "../include/screen.h"

using namespace std;

int main()
{
  screen screen;
  if (screen.init() == false)
    cout << "Error initializing screen\n";

  while (true)
  {
    // update

    // draw
    // for (int i = 0; i < screen::SCREEN_HEIGHT; i++)
    // {
    //   for (int j = 0; j < screen::SCREEN_WIDTH; j++)
    //   {
    //     screen.setPixel(x, y, 128, 0, 255);
    //   }
    // }
    screen.setPixel(400, 300, 255, 255, 255);

    screen.update();
    // events

    if (screen.processEvents() == false)
    {
      break;
    }
  }
}