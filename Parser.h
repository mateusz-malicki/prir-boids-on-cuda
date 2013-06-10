#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include "Frame.h"
#include "Boid.h"
#include <string>
#include <cstdlib>

using namespace std;

class Parser
{
  public:
  static Parser& GetInstance();
  static vector<Frame> Deserialize(string filename, int& width, int& height);

  private:
  Parser(){};
  Parser(Parser const&);
  void operator=(Parser const&);
};
#endif
