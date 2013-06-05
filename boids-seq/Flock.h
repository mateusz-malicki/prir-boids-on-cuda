#ifndef FLOCK_H
#define FLOCK_H

#include<stdio.h>
#include<stdlib.h>
#include<math.h>


#define CELL_SIZE 32;

class Flock {
  int** cell_boid_table;
  int size;

  public:
    Flock (int,int);
};
#endif
