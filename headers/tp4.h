#ifndef TP4_H
#define TP4_H

void dSMDaSMO(char *fic_smo, int NbLign, int *AdPrCoefLi, int *NumCol, int *AdSuccLi, float *Matrice, float *SecMembre,
            int *NumDLDir, float *ValDLDir, int *AdPrCoLiO, int *NumColO, float *MatriceO, float *SecMembO);

void LecSMO(char *fic_smo, int *pNbLign, float **pSecMembO, int **pAdPrCoLiO, float **pMatriceO, int **pNumColO);

#endif