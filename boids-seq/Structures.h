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
  void serialize(Archive & ar, const unsigned int version);

public:
  int x;
  int y;
  Point2D(){};
  Point2D(int a, int b);
};

class Frame
{
private:
  friend class boost::serialization::access;  
  template<class Archive>
  void serialize(Archive & ar, const unsigned int version);

  list<Point2D>pos;

public:
  Frame(){};
  Frame(int len);
};
