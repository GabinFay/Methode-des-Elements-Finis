#include "TP2B_.h"

/*
--------------------------------------------------------------------------------
    Intégrale du second membre
--------------------------------------------------------------------------------
*/


void W(int nbneel, float *fctbas, float eltdif, float cofvar, float *SMbrElem){
  for(int i = 0; i < nbneel; i++){
    SMbrElem[i] = SMbrElem[i] + eltdif*cofvar*fctbas[i];
  }
}
