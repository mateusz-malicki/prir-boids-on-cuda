#include "Boid.h"

Boid::Boid(Point2D position)
{
  this->position = position;
}

Boid::Boid(int x, int y)
{
  Point2D point(x,y);
  this->position = point;
}

Boid::Boid(Point2D position, Vector2D separateForce, Vector2D alignForce, Vector2D cohesionForce)
{
  this->position = position;
  this->separateForce = separateForce;
  this->alignForce = alignForce;
  this->cohesionForce = cohesionForce;
}

vector<int> Boid::GetNeighbours()
{
  return neighbours;
}
