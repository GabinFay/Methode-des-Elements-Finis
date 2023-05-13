#ifndef TP2B_H
#define TP2B_H

void W(int nbneel, float *fctbas, float eltdif, float cofvar, float *SMbrElem);

void ADWDW(int nbneel, float **derfctbas, float **invJac, float eltdif, float **A, float **MatElem);

void WW(int nbneel, float *fctbas, float eltdif, float cofvar, float **MatElem);

float A00(float *x);

float A11(float *x);

float A12(float *x);

float A22(float *x);

float BN(float *x);

float FN(float *x);

float FOMEGA(float *x);

float UD(float *x);

void intElem(int nbneel, float **coorEl, int t, float **MatElem, float *SMbrElem);

void intAret(int nbneel, float **coorAr, float **MatAret, float *SMbrAret);

void cal1Elem(int t, int nbneel, int nbaret, float **coorEl,
  int *nRefArEl, int nrefdom, int nbRefD0, int *numRefD0, 
  int nbRefD1, int *numRefD1, int nbRefF1, int *numRefF1,
  float **MatElem,float *SMbrElem, int *NuDElem, float *uDElem);

void impCalEl(int K, int t, int nbneel, float **MatElem, float *SMbrElem,
              int *NuDElem, float *uDElem);
#endif
