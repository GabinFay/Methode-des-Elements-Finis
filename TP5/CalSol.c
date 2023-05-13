#include "TP5_.h"

/*
--------------------------------------------------------------------------------
    Evaluation de la solution exacte
--------------------------------------------------------------------------------
*/

void CalSol(int nbtng, float **coord, float *UEX){
  for (int i=0; i < nbtng; i++){
    UEX[i] = solex(coord[i]);
  }
}