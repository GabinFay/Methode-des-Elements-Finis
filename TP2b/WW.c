#include "TP2B_.h"

/*
--------------------------------------------------------------------------------
    Intégrale du terme sans dérivées
--------------------------------------------------------------------------------
*/

void WW(int nbneel, float *fctbas, float eltdif, float cofvar, float **MatElem){
  int i, j;
  float coeff;

  for(i = 0; i < nbneel; i++){
    coeff = eltdif*cofvar*fctbas[i];
    for (j=0; j < nbneel; j++){
      MatElem[i][j] = MatElem[i][j] + coeff*fctbas[j];
    }
  }
}
