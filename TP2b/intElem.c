#include "TP2B_.h"

/*
--------------------------------------------------------------------------------
    intégrale sur l'élément
--------------------------------------------------------------------------------
*/


void intElem(int nbneel, float **coorEl, int t, float **MatElem, float *SMbrElem){ 
  int q = valq(t);
  float wk[q];
  float **xk = float_calloctab(q,2);
  float cofvar;
  float **A = float_calloctab(2,2);

  ppquad(t, wk, xk);

  float fctbas[nbneel];
  float **derfctbas = float_calloctab(nbneel,2);
  int d = 2;
  float **Jac = float_calloctab(2,2);
  float **invJac = float_calloctab(2,2);
  float x[2] = {0,0};
  float eltdif;

  for (int i=0; i<q; i++){
      float det = 0;

      calFbase(t, xk[i], fctbas);
      
      calDerFbase(t, xk[i], derfctbas);
      matJacob(coorEl, nbneel, derfctbas, d, Jac);

      invertM2x2(Jac, &det, invJac);
      transFK(coorEl, fctbas, x);

      eltdif = wk[i]*det;
      cofvar = A00(x);
      WW(nbneel, fctbas, eltdif, cofvar, MatElem);
      A[0][0] = A11(x); A[0][1] = A12(x);
      A[1][0] = A12(x); A[1][1] = A22(x);
      ADWDW(nbneel, derfctbas, invJac, eltdif, A, MatElem);
      cofvar = FOMEGA(x);
      W(nbneel, fctbas, eltdif, cofvar, SMbrElem);
      }
  
  freetab(xk);
  freetab(A);
  freetab(derfctbas);
  freetab(Jac);
  freetab(invJac);
  
  }

