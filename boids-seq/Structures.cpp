#include "Structures.h"
  template<class Archive>
  void Point2D::serialize(Archive & ar, const unsigned int version)
  {
    ar & BOOST_SERIALIZATION_NVP(x)
       & BOOST_SERIALIZATION_NVP(y);
  }

  Point2D::Point2D(int a, int b)
  {
    x = a;
    y = b;
  }

  template<class Archive>
  void Frame::serialize(Archive & ar, const unsigned int version)
  {
    ar & BOOST_SERIALIZATION_NVP(pos);
  }

  void Frame::add_point(Point2D point)
  {
      pos.push_back(point);
  }
