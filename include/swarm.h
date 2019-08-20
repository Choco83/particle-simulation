#ifndef SWARM_H_
#define SWARM_H_

#include "../include/particle.h"

class Swarm
{
  private:
    Particle *p_particles;

  public:
    int N_PARTICLES = 10000;
    Swarm();
    virtual ~Swarm();

    const inline Particle *const getParticles() { return p_particles; }
    void update();
};

#endif // !SWARM_H