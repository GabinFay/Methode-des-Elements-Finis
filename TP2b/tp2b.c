#include "TP2B_.h"

/*
--------------------------------------------------------------------------------
    Evaluation de la solution exacte
--------------------------------------------------------------------------------
*/

int main(void){
  char *ficmai = "../../TP1/car1x1t_1";
  int t = 0;
  int nbneel = 0;
  int nbtng = 0;
  int nbtel = 0;
  int nbaret = 0;
  float **coord = NULL; 
  int **ngnel = NULL;
  int **nRefAr = NULL;

  lecfima(ficmai, &t, &nbtng, &coord, &nbtel, &ngnel, &nbneel, &nbaret, &nRefAr);
 
  int nrefdom = 0;
  int nbRefD0 = 1;
  int nbRefD1 = 1;
  int nbRefF1 = 2;
  int *numRefD0 = (int*)calloc(nbRefD0,sizeof(int));
  int *numRefD1 = (int*)calloc(nbRefD1,sizeof(int));
  int *numRefF1 = (int*)calloc(nbRefF1,sizeof(int));

  numRefD0[0] = 1;
  numRefD1[0] = 4;
  numRefF1[0] = 2; numRefF1[1] = 3;


    float **MatElem = float_calloctab(nbneel,nbneel);
    float *SMbrElem = (float*)calloc(nbneel,sizeof(float));
    int *NuDElem = (int*)calloc(nbneel,sizeof(float));
    float *uDElem = (float*)calloc(nbneel,sizeof(float));
    float **coorEl = float_calloctab(4,2); 
    int *nRefArEl;

  for (int K = 0; K < nbtel; K++){

    nRefArEl = nRefAr[K];

    selectPts(nbneel, ngnel[K], coord, coorEl);
     
    cal1Elem(t, nbneel, nbaret, coorEl, nRefArEl, nrefdom, nbRefD0, 
    numRefD0, nbRefD1, numRefD1, nbRefF1, numRefF1,
    MatElem, SMbrElem, NuDElem, uDElem);

    impCalEl(K+1, t, nbneel, MatElem, SMbrElem, NuDElem, uDElem);

  }
  
  freetab(MatElem);
  freetab(coorEl);
  free(SMbrElem);
  free(NuDElem);
  free(uDElem);
  free(nRefArEl);
  return 0;
}
