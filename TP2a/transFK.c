#include "TP2A_.h"

/*
--------------------------------------------------------------------------------
    Calcule x=FK(xref)
--------------------------------------------------------------------------------
*/

void transFK(float **coorEl, float *fctbas, float *x){
  x[0] = 0; x[1] = 0;
  for(int i=0 ; i<2 ; i++){
    for(int j=0 ; j<4 ; j++){
      x[i] += coorEl[j][i]*fctbas[j];
    }
  }
}

