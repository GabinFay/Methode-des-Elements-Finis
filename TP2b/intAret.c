#include "TP2B_.h"

/*
--------------------------------------------------------------------------------
    intégrale sur les bords du domaine
--------------------------------------------------------------------------------
*/

extern int nucas;
extern int normale;

void intAret(int nbneel, float **coorAr, float **MatAret, float *SMbrAret){

  for(int i = 0; i < nbneel; i++){
    MatAret[i][0] = 0; MatAret[i][1] = 0; SMbrAret[i] = 0; 
  }

  int t = 3;
  int q = valq(t);
  float wk[q];
  float **xk = float_calloctab(q,2);
  float cofvar;
  ppquad(t, wk, xk);
  
  float fctbas[4];
  float **derfctbas = float_calloctab(4, 2);
  int d = 1;
  float **Jac = float_calloctab(2,2);
  float x[2] = {0,0};
  float eltdif;

  for (int i=0; i<q; i++){
    calFbase(t, xk[i], fctbas);
    calDerFbase(t, xk[i], derfctbas);
    matJacob(coorAr, nbneel, derfctbas, d, Jac);
    transFK(coorAr, fctbas, x);
    eltdif = wk[i] * powf((Jac[0][0]*Jac[0][0] + Jac[1][0]*Jac[1][0]),0.5);
    cofvar = BN(x);
    WW(nbneel, fctbas, eltdif, cofvar, MatAret);
    cofvar = FN(x);
    W(nbneel, fctbas, eltdif, cofvar, SMbrAret);
  }

  freetab(xk);
  freetab(derfctbas);
  freetab(Jac);
  
  }

