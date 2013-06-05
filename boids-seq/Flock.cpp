#include "Flock.h"

  Flock::Flock(int window_size, int num_boids){
    int i;
    int row_size =  window_size / CELL_SIZE;

    size = num_boids;
// TODO lista boidow
//Alokacja pamięci na tabelę cells/boids
    cell_boid_table = (int**)malloc(row_size*sizeof(int*));
    for(i=0; i<row_size; i++){
      cell_boid_table[i] = (int*) malloc(row_size*sizeof(int));
    }
  }
