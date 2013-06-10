#ifndef FRAME_H
#define FRAME_H

#include <vector>
#include "Boid.h"

class Parser;

class Frame
{
  public:
  friend class Parser;
  vector<Boid> boids;

  public:
  Frame(){};
  Frame(vector<Boid> boids);
  void AddBoid(Boid boid);
};
#endif
