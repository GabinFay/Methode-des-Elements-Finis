#include "TP2B_.h"

/*
--------------------------------------------------------------------------------
    calcule la matrice élémentaire et le second membre élémentaire pour un élément
--------------------------------------------------------------------------------
*/

extern int normale = 0;

void cal1Elem(int t, int nbneel, int nbaret, float **coorEl,
  int *nRefArEl, int nrefdom, int nbRefD0, int *numRefD0, 
  int nbRefD1, int *numRefD1, int nbRefF1, int *numRefF1,
  float **MatElem,float *SMbrElem, int *NuDElem, float *uDElem){

  for (int i = 0; i < nbneel; i++){
    SMbrElem[i] = 0;
    NuDElem[i] = 1;
    uDElem[i] = 0;
    for (int j = 0; j < nbneel; j++){
      MatElem[i][j] = 0;
    }
  }
  
  intElem(nbneel, coorEl, t, MatElem, SMbrElem);
  //Stack equivalent of float_alloctab, since we don't need DA here
  float zeros[8] = {0};
  float *coorAr[4] = {zeros, zeros +2, zeros +4, zeros +6};

  float **MatAret = float_calloctab(nbneel,2);
  float *SMbrAret = (float*)calloc(nbneel, sizeof(float));
  
  for (int i = 0; i < nbaret; i++){
    if(nRefArEl[i] != nrefdom){
      
      int nunear[2];
      
      numNaret(i+1, t, nunear);
      selectPts(2, nunear, coorEl, coorAr);
      for(int j = 0; j < nbRefF1; j++){
          
        if(nRefArEl[i] == numRefF1[j]){
          normale = nRefArEl[i];
          intAret(nbneel, coorAr, MatAret, SMbrAret);

          for(int k = 0; k < 2; k++){
            SMbrElem[nunear[k]-1] = SMbrElem[nunear[k]-1] + SMbrAret[k];
            for(int l = 0; l < 2; l++){
              MatElem[nunear[k]-1][nunear[l]-1] = MatElem[nunear[k]-1][nunear[l]-1] + MatAret[k][l];
            }
          }

        }
      }

      for(int j = 0; j < nbRefD0; j++){
        if(nRefArEl[i] == numRefD0[j]){
          if(NuDElem[nunear[0]-1] == 1){
            NuDElem[nunear[0]-1] = 0;
          }
          if(NuDElem[nunear[1]-1] == 1){
            NuDElem[nunear[1]-1] = 0;
          }
        }
      }

      for(int j = 0; j < nbRefD1; j++){
        if(nRefArEl[i] == numRefD1[j]){
          if(NuDElem[nunear[0]-1] == 1){
            NuDElem[nunear[0]-1] = -1;
            uDElem[nunear[0]-1] = UD(coorAr[0]);
          }
          if(NuDElem[nunear[1]-1] == 1){
            NuDElem[nunear[1]-1] = -1;
            uDElem[nunear[1]-1] = UD(coorAr[1]);
          }
        }
      }

    }
  }
  free(SMbrAret);
  freetab(MatAret);
}
