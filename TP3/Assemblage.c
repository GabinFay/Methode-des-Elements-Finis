#include "TP3_.h"

/*
--------------------------------------------------------------------------------
    Assemblage du système linéaire
--------------------------------------------------------------------------------
*/


void Assemblage(int t, int nbneel, int nbaret, 
int nbtel, int nbtng, int nrefdom, int nbRefD0, int nbRefD1, int nbRefF1,
int *numRefD0, int *numRefD1, int *numRefF1,
int **nRefAr, float **coord, int **ngnel,  float *Matrice, float *SecMembre, 
int *NumDLDir, float *ValDLDir, int *NumCol, int *AdSuccLi, int *AdPrCoefLi){

  int NbCoefMax = 0.5*nbtng*(nbtng-1);
  float LowMat[NbCoefMax];
  float DiagMat[nbtng];

  float X;
  int NextAd = 1;

  for (int i = 0; i < nbtng; i++){
    NumDLDir[i] = i+1;
    ValDLDir[i] = 1;
    DiagMat[i] = 0;
  }

  float **MatElem = float_calloctab(nbneel,nbneel);
  float *coorEl[4];
  float *SMbrElem = (float*)calloc(nbneel,sizeof(float));
  int *NuDElem = (int*)calloc(nbneel,sizeof(float));
  float *uDElem = (float*)calloc(nbneel,sizeof(float));
  int *nRefArEl = (int*)calloc(nbaret,sizeof(int));

  for (int K = 0; K < nbtel; K++){

    nRefArEl = nRefAr[K];

    selectPts(nbneel, ngnel[K], coord, coorEl);
    cal1Elem(t, nbneel, nbaret, coorEl, nRefArEl, nrefdom, nbRefD0, 
    numRefD0, nbRefD1, numRefD1, nbRefF1, numRefF1,
    MatElem, SMbrElem, NuDElem, uDElem);

    for(int i = 0; i < nbneel; i++){
      int I = ngnel[K][i];

      for(int j = 0; j < nbneel; j++){
        int J = ngnel[K][j];
        if(I > J){

          X = MatElem[i][j];
          assmat_(&I, &J, &X, AdPrCoefLi,
            NumCol, AdSuccLi, LowMat, &NextAd);
        }
        if (I == J){
          DiagMat[I-1] += MatElem[i][j];
        }
      }

      SecMembre[I-1] += SMbrElem[i];

      if(NumDLDir[I-1] == I){
        NumDLDir[I-1] = NumDLDir[I-1] * NuDElem[i];
        ValDLDir[I-1] = uDElem[i];
      }
    }
    impCalEl(K+1, t, nbneel, MatElem, SMbrElem, NuDElem, uDElem);
  }


  AdPrCoefLi[nbtng-1] = NextAd;
  
  for (int i=0;i<nbtng;i++){
    Matrice[i] = DiagMat[i];
  }
  for(int i=nbtng;i<nbtng+NextAd;i++){
    Matrice[i]=LowMat[i-nbtng];
  }

  freetab(MatElem);
  free(SMbrElem);  
  free(NuDElem);
  free(uDElem);
}