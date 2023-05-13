#include "TP4_.h"

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
  int numRefD0[nbRefD0];
  int numRefD1[nbRefD1];
  int numRefF1[nbRefF1];

  numRefD0[0] = 1;
  numRefD1[0] = 4;
  numRefF1[0] = 2; numRefF1[1] = 3;

  float *Matrice = (float*)calloc(0.5*nbtng*(nbtng+1), sizeof(float));
  float *SecMembre = (float*)calloc(nbtng, sizeof(float));
  int *NumDLDir = (int*)calloc(nbtng, sizeof(int));
  float *ValDLDir=(float*)calloc(nbtng,sizeof(float));
  
  int NbCoefMax = 0.5*nbtng*(nbtng-1);

  int *AdPrCoefLi = (int*)calloc(nbtng, sizeof(int));
  int *NumCol = (int*)calloc(NbCoefMax, sizeof(int));
  int *AdSuccLi = (int*)calloc(NbCoefMax, sizeof(int));

  Assemblage(t, nbneel, nbaret, nbtel,  nbtng,  nrefdom,  nbRefD0, 
     nbRefD1,  nbRefF1, numRefD0,  numRefD1,  numRefF1, nRefAr,
       coord,  ngnel,  Matrice, SecMembre, NumDLDir,  ValDLDir,
         NumCol,  AdSuccLi,  AdPrCoefLi);
  
  int NbCoef = AdPrCoefLi[nbtng-1] - 1;
  Matrice = realloc(Matrice, (nbtng + NbCoef)*sizeof(float));
  NumCol = realloc(NumCol, NbCoef*sizeof(int));
  AdSuccLi = realloc(AdSuccLi, NbCoef*sizeof(int));
  
  char *fic_smd = "../../TP3/SMD.txt";
  
  EcrSMD(fic_smd, nbtng, SecMembre, NumDLDir, ValDLDir, AdPrCoefLi, 
      Matrice, NumCol, AdSuccLi);  

  LecSMD(fic_smd, &nbtng, &SecMembre, &NumDLDir, &ValDLDir, &AdPrCoefLi,
     &Matrice, &NumCol, &AdSuccLi);
  
  // affsmd_(&nbtng, AdPrCoefLi, NumCol, AdSuccLi, Matrice, SecMembre, 
  //   NumDLDir, ValDLDir);

  char *fic_smo = "../../TP4/SMO.txt";

  float *SecMembO = SecMembre;
  int *AdPrCoLiO = AdPrCoefLi;
  float *MatriceO = (float*)calloc(nbtng+NbCoef, sizeof(float));
  int *NumColO = (int*)calloc(NbCoef, sizeof(int));
  
  dSMDaSMO(fic_smo, nbtng, AdPrCoefLi, NumCol, AdSuccLi, Matrice, 
        SecMembre,NumDLDir, ValDLDir, AdPrCoLiO, NumColO, 
        MatriceO, SecMembO);

  LecSMO(fic_smo, &nbtng, &SecMembO, &AdPrCoLiO, &MatriceO, &NumColO);

  affsmo_(&nbtng, AdPrCoLiO, NumColO, MatriceO, SecMembO);

  return 0;
}