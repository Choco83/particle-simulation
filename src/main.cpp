#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "../include/screen.h"
#include "../include/swarm.h"

int main(int argc, char **argv)
{
  srand(time(NULL));

  Screen screen;
  Swarm swarm;

  if (screen.init() == false)
  {
    std::cout << "Error initailizing sdl";
  }
  const auto half_width = screen.SCREEN_WIDTH / 2;
  const auto half_height = screen.SCREEN_HEIGHT / 2;

  while (true)
  {
    swarm.update();
    screen.clear();
    const Particle *const p_particles = swarm.getParticles();
    int elapsed = SDL_GetTicks();
    for (int i = 0; i < swarm.N_PARTICLES; i++)
    {
      Particle new_particle = p_particles[i];
      int x = (new_particle.m_x + 1) * half_width;
      int y = new_particle.m_y * half_width + half_height;

      int red = (1 + (sin(elapsed * 0.001))) * 128;
      int green = (1 + (cos(elapsed * 0.005))) * 128;
      int blue = (1 + (cos(elapsed * 0.003))) * 128;
      screen.setPixel(x, y, red, green, blue);
    }
    screen.update();
    if (screen.processEvents() == false)
    {
      break;
    }
  }
  return 0;
}