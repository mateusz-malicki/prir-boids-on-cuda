#include "Structures.h"

  void Point2D::serialize(Archive & ar, const unsigned int version)
  {
    ar & x;
    ar & y;
  }

  Point2D::Point2D(int a, int b)
  {
    x = a;
    y = b;
  }

  void Frame::serialize(Archive & ar, const unsigned int version)
  {
    ar & pos;
  }

  Frame::Frame(int len)
  {
    for(int i = 0; i < len; i++)
    {
      Point2D point(i, len-i-1);
      pos.push_back(point);
    }
  }
