#include "TP4_.h"

/*
--------------------------------------------------------------------------------
    Passage de la structure SMD a la structure SMO et écriture dans fichier binaire
--------------------------------------------------------------------------------
*/

void dSMDaSMO(char *fic_smo, int NbLign, int *AdPrCoefLi, int *NumCol, int *AdSuccLi, float *Matrice, float *SecMembre,
            int *NumDLDir, float *ValDLDir, int *AdPrCoLiO, int *NumColO, float *MatriceO, float *SecMembO){
 
  cdesse_(&NbLign, AdPrCoefLi, NumCol, AdSuccLi, Matrice, SecMembre, NumDLDir, ValDLDir, AdPrCoLiO, NumColO, MatriceO, SecMembO);


  FILE *fp = fopen(fic_smo, "wb");
      if (fp == NULL){
    printf("dSMDaSMO : le fichier ne s'est pas ouvert correctement\n");
    exit(1);
  }
  else{
    int NbCoefO = AdPrCoLiO[NbLign-1]-1;
    fwrite(&NbLign, sizeof(NbLign), 1, fp);
    fwrite(SecMembO, sizeof(*SecMembO), NbLign, fp);
    fwrite(AdPrCoLiO, sizeof(*AdPrCoLiO), NbLign, fp);
    fwrite(MatriceO, sizeof(*MatriceO), NbLign+NbCoefO, fp);
    fwrite(NumColO, sizeof(*NumColO), NbCoefO, fp);
    
    fclose(fp);
  }
}