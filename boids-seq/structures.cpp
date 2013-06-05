#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <list>


#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/list.hpp>

using namespace std;

class Point2D
{
private:
  friend class boost::serialization::access;  
  template<class Archive>
  void serialize(Archive & ar, const unsigned int version)
  {
    ar & x;
    ar & y;
  }


public:
  int x;
  int y;
  Point2D(){};
  Point2D(int a, int b)
  {
    x = a;
    y = b;
  };
};

class Frame
{
private:
  friend class boost::serialization::access;  
  template<class Archive>
  void serialize(Archive & ar, const unsigned int version)
  {
    ar & pos;
  }

  list<Point2D>pos;

public:
  Frame(){};
  Frame(int len)
  {
    for(int i = 0; i < len; i++)
    {
      Point2D point(i, len-i-1);
      pos.push_back(point);
    }
  };
};
