#include "TP3_.h"

/*
--------------------------------------------------------------------------------
    Ecriture de la SMD dans un fichier binaire
--------------------------------------------------------------------------------
*/

void EcrSMD(char *fic_smd, int NbLign, float *SecMembre, int *NumDLDir, float *ValDLDir,
int *AdPrCoefLi, float *Matrice, int *NumCol, int *AdSuccLi){
  
  int NbCoef = AdPrCoefLi[NbLign-1]-1;
  FILE *fp = fopen(fic_smd, "wb");
  if (fp == NULL){
    printf("EcrSMD : le fichier ne s'est pas ouvert correctement\n");
    exit(1);
  }
  else{
  fwrite(&NbLign, sizeof(NbLign), 1, fp);
  fwrite(SecMembre, sizeof(*SecMembre), NbLign, fp);
  fwrite(NumDLDir, sizeof(*NumDLDir), NbLign, fp);
  fwrite(ValDLDir, sizeof(*ValDLDir), NbLign, fp);
  fwrite(AdPrCoefLi, sizeof(*AdPrCoefLi), NbLign, fp);
  fwrite(Matrice, sizeof(*Matrice), NbLign+NbCoef, fp);
  fwrite(NumCol, sizeof(*NumCol), NbCoef, fp);
  fwrite(AdSuccLi, sizeof(*AdSuccLi), NbCoef, fp);
  
  fclose(fp);
  }
}