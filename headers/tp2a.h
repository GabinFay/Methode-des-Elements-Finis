#ifndef TP2A_H
#define TP2A_H


void ppquad(int t, float *wk, float **xk);

int valq(int t);

void calFbase(int t, float *xref, float *fctbas);

void calDerFbase(int t, float *xref, float **derfctbas);

void transFK(float **coorEl, float *fctbas, float *x);

void matJacob(float **coorEl, int nbneel, float **derfctbas, int d, float **Jac);

void invertM2x2(float **M, float *pdet, float **invertM);

void numNaret(int num_ar, int t, int *nunear);

void selectPts(int nb, int num[], float *coorEns[], float *coorSel[]);

#endif
