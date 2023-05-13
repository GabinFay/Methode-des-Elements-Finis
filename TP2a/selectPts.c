#include "TP2A_.h"

/*
--------------------------------------------------------------------------------
    copie nb pointeurs repérés par num[nb] à partir du tableau *coorEns[] dans *coorSel[]
--------------------------------------------------------------------------------
*/

void selectPts(int nb, int num[], float *coorEns[], float *coorSel[])
{  
  for (int i = 0; i < nb; i++){
    coorSel[i] = coorEns[num[i]-1];
  }
}
