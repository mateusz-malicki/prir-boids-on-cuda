#ifndef BOID_H
#define BOID_H

#include "Structures.h"
#include <stdlib.h>
#include <vector>

class Parser; //forward declaration

class Boid
{
  public:
 
  friend class Parser; 
  Point2D position;
  Vector2D separateForce;
  Vector2D alignForce;
  Vector2D cohesionForce;
  Vector2D velocityForce;
  
  vector<int> neighbours;

  public:
  Boid() {};
  Boid(int x, int y);
  Boid(Point2D position);
  Boid(Point2D position, Vector2D separateForce, Vector2D alignForce, Vector2D cohesionForce);
  //void SetSeparateForce(Vector2D separateForce);
  Vector2D GetSeparateForce();
  //void SetAlignForce(Vector2D alignForce);
  Vector2D GetAlignForce();
  //void SetCohesionForce(Vector2D cohesionForce);
  Vector2D GetCohesionForce();
  //void SetPosition(Point2D position);
  Point2D GetPosition();

  //void SetNeighbours(Vector2D<int> neighbours);
  //void AddNeighbour(int index);
  vector<int> GetNeighbours();
};
#endif
