#include "Frame.h"

Frame::Frame(vector<Boid> boids)
{
  this->boids = boids;
}

void Frame::AddBoid(Boid boid)
{
  boids.push_back(boid);
}
