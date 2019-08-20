#include "../include/swarm.h"

Swarm::Swarm()
{
    p_particles = new Particle[N_PARTICLES];
}

Swarm::~Swarm()
{
    delete[] p_particles;
}

void Swarm::update()
{
    for (int i = 0; i < N_PARTICLES; i++)
    {
        p_particles[i].update();
    }
}