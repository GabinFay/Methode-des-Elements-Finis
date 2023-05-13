#include "TP5_.h"

// /*
// --------------------------------------------------------------------------------
//     Passage de la structure SMO a la structure Profil
// --------------------------------------------------------------------------------
// */


void dSMOaPR(int nbtng, int *AdPrCoLiO, float *MatriceO, int *NumColO, 
    int *Profil, float *MatProf){

  for (int i = 0; i < nbtng; i++){
    MatProf[i] = MatriceO[i];
  }

  Profil[0] = 1;

  for(int l = 0; l < nbtng; l++){
    
    int adl = AdPrCoLiO[l];
    
    if (AdPrCoLiO[l+1] == adl){
      Profil[l+1] = Profil[l];
    }
    
    else if (AdPrCoLiO[l+1] == adl + 1){
      Profil[l+1] = Profil[l] + l - NumColO[adl-1] + 2;
      MatProf[nbtng + Profil[l] - 1] = MatriceO[nbtng + adl - 1];
    }
    
    else{
      Profil[l+1] = Profil[l] + l - NumColO[adl-1] + 2;
      int ad = adl;
      while(ad < AdPrCoLiO[l+1]){
        MatProf[nbtng + Profil[l] - 1 + NumColO[ad-1] - NumColO[adl-1]] = MatriceO[nbtng + ad - 1];
        ad = ad + 1;
      }
    }
  }
}



