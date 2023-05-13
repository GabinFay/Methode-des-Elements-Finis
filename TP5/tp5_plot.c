#include "TP5_.h"
#include <string.h>

/*
--------------------------------------------------------------------------------
    Evaluation de la solution exacte
--------------------------------------------------------------------------------
*/

extern int nucas = 1;

int main(void){
  
  char fic1[12], fic2[12] = ".txt";
  char *ficmai;
  for (int num=2; num < 33; num = 2*num){
    ficmai = "../../Maillage/d1q1_";
    sprintf(fic1, "%d", num);
    ficmai = concat(ficmai, fic1);
    ficmai = concat(ficmai, fic2);
    printf("ficmai : %s\n", ficmai);
  

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
    int nbRefD0, nbRefD1, nbRefF1;
    int *numRefD0, *numRefD1, *numRefF1;

    switch(nucas){
      case 0:
        nbRefD0 = 1; nbRefD1 = 1; nbRefF1 = 2;
        numRefD0 = (int *)calloc(nbRefD0, sizeof(int));
        numRefD1 = (int *)calloc(nbRefD1, sizeof(int));
        numRefF1 = (int *)calloc(nbRefF1, sizeof(int));
        numRefD0[0] = 1; numRefD1[0] = 4; numRefF1[0] = 2; numRefF1[1] = 3;
        break;
      case 1:
        nbRefD0 = 4; nbRefD1 = 0; nbRefF1 = 0;
        numRefD0 = (int *)calloc(nbRefD0, sizeof(int));
        numRefD1 = (int *)calloc(nbRefD1, sizeof(int));
        numRefF1 = (int *)calloc(nbRefF1, sizeof(int));
        numRefD0[0] = 1; numRefD0[1] = 2; numRefD0[2] = 3; numRefD0[3] = 4;
        break;
      case 2:
        nbRefD0 = 0; nbRefD1 = 4; nbRefF1 = 0;
        numRefD0 = (int *)calloc(nbRefD0, sizeof(int));
        numRefD1 = (int *)calloc(nbRefD1, sizeof(int));
        numRefF1 = (int *)calloc(nbRefF1, sizeof(int));
        numRefD1[0] = 1; numRefD1[1] = 2; numRefD1[2] = 3; numRefD1[3] = 4;
        break;
      case 3:
        nbRefD0 = 0; nbRefD1 = 0; nbRefF1 = 4;
        numRefD0 = (int *)calloc(nbRefD0, sizeof(int));
        numRefD1 = (int *)calloc(nbRefD1, sizeof(int));
        numRefF1 = (int *)calloc(nbRefF1, sizeof(int));
        numRefF1[0] = 1; numRefF1[1] = 2; numRefF1[2] = 3; numRefF1[3] = 4;
        break;
      }

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

    affsmd_(&nbtng, AdPrCoefLi, NumCol, AdSuccLi, Matrice, SecMembre, 
      NumDLDir, ValDLDir);

    char *fic_smo = "../../TP4/SMO.txt";

    float *SecMembO = SecMembre;
    int *AdPrCoLiO = AdPrCoefLi;

    float *MatriceO = (float*)calloc(nbtng+NbCoef, sizeof(float));
    int *NumColO = (int*)calloc(NbCoef, sizeof(int));
    
    dSMDaSMO(fic_smo, nbtng, AdPrCoefLi, NumCol, AdSuccLi, Matrice, 
          SecMembre, NumDLDir, ValDLDir, AdPrCoLiO, NumColO, 
          MatriceO, SecMembO);


    LecSMO(fic_smo, &nbtng, &SecMembO, &AdPrCoLiO, &MatriceO, &NumColO);

    affsmo_(&nbtng, AdPrCoLiO, NumColO, MatriceO, SecMembO);

    int NbCoefO = AdPrCoLiO[nbtng-1] - 1;

    int *Profil = (int*)calloc(nbtng, sizeof(int));
    float *MatProf = (float*)calloc(nbtng + NbCoefMax, sizeof(float)); 
    int codret = 0;
    float *U = (float*)calloc(nbtng, sizeof(float));
    float *UEX = (float*)calloc(nbtng, sizeof(float));


    dSMOaPR(nbtng, AdPrCoLiO, MatriceO, NumColO, 
      Profil, MatProf);

    // dmoapr(nbtng, AdPrCoLiO, NumColO, MatriceO, NbCoefMax + nbtng, Profil, MatProf, &codret);  

    int NbCoefP = Profil[nbtng-1] -1;

    float *DiagMatProf = MatProf;
    float *LowMatProf = &(MatProf[nbtng]);
    float *DiagL = (float *)calloc(nbtng,sizeof(float));
    float *LowMatL = (float*)calloc(NbCoefMax,sizeof(float));

    float eps = 0.00001;

    ltlpr_(&nbtng, Profil, DiagMatProf, LowMatProf, &eps, DiagL, LowMatL);

    rsprl_(&nbtng, Profil, DiagL, LowMatL, SecMembO, U);

    rspru_(&nbtng, Profil, DiagL, LowMatL, SecMembO, U);

    CalSol(nbtng, coord, UEX);

    float coord_transposed[2][nbtng];
    
    for(int i=0; i<2; i++){
      for(int j = 0; j < nbtng; j++){
        coord_transposed[i][j] = coord[j][i];
      }
    }
    
    int impfch = 3;
    
    affsol_(&nbtng, *coord_transposed, U, UEX, &impfch);
    
    freetab(coord);
    freetab(ngnel);
    freetab(nRefAr);
    }

  return 0;
}