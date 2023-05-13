#include "TP4_.h"

/*
--------------------------------------------------------------------------------
    Lecture SMO dans fichier binaire
--------------------------------------------------------------------------------
*/

void LecSMO(char *fic_smo, int *pNbLign, float **pSecMembO, int **pAdPrCoLiO, float **pMatriceO, int **pNumColO){
  
  FILE *fp = fopen(fic_smo, "rb");
  if (fp == NULL){
    printf("LecSMO : le fichier ne s'est pas ouvert correctement\n");
    exit(1);
  }
  else{
    fread(pNbLign, sizeof(int), 1, fp);
    float *SecMembO = (float*)calloc(*pNbLign, sizeof(float));
    int *AdPrCoLiO = (int*)calloc(*pNbLign, sizeof(int));
    fread(SecMembO, sizeof(*SecMembO), *pNbLign, fp);

    fread(AdPrCoLiO, sizeof(*AdPrCoLiO), *pNbLign, fp);
    int NbCoefO = AdPrCoLiO[*pNbLign - 1] - 1;
    float *MatriceO =  (float*)calloc(*pNbLign + NbCoefO, sizeof(float));
    int *NumColO = (int*)calloc(NbCoefO, sizeof(int));
    fread(MatriceO, sizeof(*MatriceO), *pNbLign+NbCoefO, fp);
    fread(NumColO, sizeof(*NumColO), NbCoefO, fp);
    
    *pSecMembO = SecMembO; 
    *pAdPrCoLiO = AdPrCoLiO;
    *pMatriceO = MatriceO;
    *pNumColO = NumColO;

    fclose(fp);
  }
}