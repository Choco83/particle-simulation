#include "../include/particle.h"
#include <stdlib.h>
#include <math.h>

Particle::Particle() : m_x(0), m_y(0)
{
    angle = 2 * M_PI * rand() / RAND_MAX;
    speed = 0.001 * rand() / RAND_MAX;
}

void Particle::update()
{
    auto speed_x = speed * cos(angle);
    auto speed_y = speed * sin(angle);

    m_x += speed_x;
    m_y += speed_y;

    if (m_x < -1.0 || m_x > 1.0)
        speed = -speed;
    if (m_y < -1.0 || m_y > 1.0)
        speed = -speed;
}

// void Particle::mouseTrail(int x, int y)
// {
//     m_x = (2.0 * rand() / RAND_MAX - 1) * x / 800;
//     m_y = (2.0 * rand() / RAND_MAX - 1) * y / 600;
// }