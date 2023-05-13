#include "TP3_.h"

/*
--------------------------------------------------------------------------------
    Lecture de la SMD à partir d'un fichier binaire
--------------------------------------------------------------------------------
*/

void LecSMD(char *fic_smd, int *pNbLign, float **pSecMembre, int **pNumDLDir, float **pValDLDir,
int **pAdPrCoefLi, float **pMatrice, int **pNumCol, int **pAdSuccLi){
  
  FILE *fp = fopen(fic_smd, "rb");
    if (fp == NULL){
    printf(" LecSMD : le fichier ne s'est pas ouvert correctement\n");
    exit(1);
  }
  else{
  fread(pNbLign, sizeof(int), 1, fp);
  float *SecMembre = (float*)calloc(*pNbLign, sizeof(float));
  int *NumDLDir = (int*)calloc(*pNbLign, sizeof(int));
  float *ValDLDir = (float*)calloc(*pNbLign, sizeof(float));
  int *AdPrCoefLi = (int*)calloc(*pNbLign, sizeof(int));
  fread(SecMembre, sizeof(*SecMembre), *pNbLign, fp);
  fread(NumDLDir, sizeof(*NumDLDir), *pNbLign, fp);
  fread(ValDLDir, sizeof(*ValDLDir), *pNbLign, fp);
  fread(AdPrCoefLi, sizeof(*AdPrCoefLi), *pNbLign, fp);
  int NbCoef = AdPrCoefLi[*pNbLign - 1] - 1;
  float *Matrice =  (float*)calloc(*pNbLign + NbCoef, sizeof(float));
  int *NumCol = (int*)calloc(NbCoef, sizeof(int));
  int *AdSuccLi = (int*)calloc(NbCoef, sizeof(int));
  fread(Matrice, sizeof(*Matrice), *pNbLign+NbCoef, fp);
  fread(NumCol, sizeof(*NumCol), NbCoef, fp);
  fread(AdSuccLi, sizeof(*AdSuccLi), NbCoef, fp);
  
  *pSecMembre = SecMembre; 
  *pNumDLDir = NumDLDir;
  *pValDLDir = ValDLDir;
  *pAdPrCoefLi = AdPrCoefLi;
  *pMatrice = Matrice;
  *pNumCol = NumCol;
  *pAdSuccLi = AdSuccLi;
  
  fclose(fp);
  }
}