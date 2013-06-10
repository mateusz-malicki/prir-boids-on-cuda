#include "Structures.h"
 
  Point2D::Point2D(int x, int y)
  {
    this->x = x;
    this->y = y;
  }

  Vector2D::Vector2D(float x, float y)
  {
    this->x = x;
    this->y = y;
  }

  float Vector2D::GetAngle()
  { //v2 = {1,0}
    //angle(v1, v2) = acos( (v1x * v2x + v1y * v2y) / (sqrt(v1x^2+v1y^2) * sqrt(v2x^2+v2y^2)) )
    return acos( x/(sqrt(x*x+y*y)) );
  }

  float Vector2D::GetLength()
  {
    return sqrt(x*x + y*y);
  }

