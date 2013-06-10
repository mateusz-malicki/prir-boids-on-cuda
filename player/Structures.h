#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <list>

#include <cmath>

using namespace std;


class Vector2D
{
 public:
  float x;
  float y;
  
  public:
  float GetLength();
  float GetAngle();
  Vector2D(){};
  Vector2D(float x , float y);
  Vector2D operator+ (Vector2D &addend) {return Vector2D(x+addend.x, y+addend.y); }; //yup, lubimy przeciążać te oczywiste operatory
};

class Point2D
{
  public:
  int x;
  int y;

  public:
  Point2D(){};
  Point2D(int x, int y);
};

#endif
