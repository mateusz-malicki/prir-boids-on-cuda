#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <list>

#include <boost/serialization/list.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>

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
  Point2D(int , int );
};

class Frame
{
private:
  friend class boost::serialization::access;  
  template<class Archive>
  void serialize(Archive & ar, const unsigned int version);


public:
  list<Point2D>pos;
  Frame(){};
  void add_point(Point2D);
};
#endif
