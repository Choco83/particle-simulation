#ifndef PARTICLE_H_
#define PARTICLE_H_

struct Particle
{
    double m_x, m_y, speed, angle;
    Particle();
    void update();
    void mouseTrail(int x, int y);
};

#endif