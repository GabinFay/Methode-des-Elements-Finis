#ifndef TP3_H
#define TP3_H

void Assemblage(int t, int nbneel, int nbaret, 
int nbtel, int nbtng, int nrefdom, int nbRefD0, int nbRefD1, int nbRefF1,
int *numRefD0, int *numRefD1, int *numRefF1,
int **nRefAr, float **coord, int **ngnel,  float *Matrice, float *SecMembre, 
int *NumDLDir, float *ValDLDir, int *NumCol, int *AdSuccLi, int *AdPrCoefLi);

void EcrSMD(char *fic_smd, int NbLign, float *SecMembre, int *NumDLDir, float *ValDLDir,
int *AdPrCoefLi, float *Matrice, int *NumCol, int *AdSuccLi);

void LecSMD(char *fic_smd, int *pNbLign, float **pSecMembre, int **pNumDLDir, float **pValDLDir,
int **pAdPrCoefLi, float **pMatrice, int **pNumCol, int **pAdSuccLi);

#endif