#include "TP2B_.h"

/*
--------------------------------------------------------------------------------
    Intégrale de la forme bilinéaire
--------------------------------------------------------------------------------
*/

void ADWDW(int nbneel, float **derfctbas, float **invJac, float eltdif, float **A, float **MatElem){
  float sum;
  float scalar_prod_alpha, scalar_prod_beta;
  int alpha; int beta;

  for(int i = 0; i < nbneel; i++){
    for (int j=0; j < nbneel; j++){
      sum = 0;
      for (alpha = 0; alpha < 2; alpha++){
        for (beta = 0; beta < 2; beta++){
          scalar_prod_alpha = derfctbas[i][0]*invJac[0][alpha] + derfctbas[i][1]*invJac[1][alpha];
          scalar_prod_beta = derfctbas[j][0]*invJac[0][beta] + derfctbas[j][1]*invJac[1][beta];
          sum = sum + A[alpha][beta] * scalar_prod_alpha * scalar_prod_beta;
        }
      }
      MatElem[i][j] = MatElem[i][j] + eltdif * sum;
    }
  }
}
