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
    // events

    if (screen.processEvents() == false)
    {
      break;
    }
  }
}