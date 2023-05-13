#include "TP2A_.h"

/*
--------------------------------------------------------------------------------
    Dérivée des fonctions de base de l'élément de référence
--------------------------------------------------------------------------------
*/

void calDerFbase(int t, float *xref, float **derfctbas){
  switch(t){
    case 1:
      derfctbas[0][0] = 1 - xref[1]; derfctbas[0][1] = - xref[0];
      derfctbas[1][0] = xref[1];     derfctbas[1][1] = xref[0];
      derfctbas[2][0] = -xref[1];    derfctbas[2][1] = 1 - xref[0];
      derfctbas[3][0] = xref[1] - 1; derfctbas[3][1] = xref[0] - 1;
      break;
    case 2:
      derfctbas[0][0] = 1;     derfctbas[0][1] = 0;
      derfctbas[1][0] = 0;     derfctbas[1][1] = 1;
      derfctbas[2][0] = - 1;   derfctbas[2][1] = - 1;
      break;
    case 3:
      derfctbas[0][0] = 1;     derfctbas[0][1] = 0;
      derfctbas[1][0] = -1;    derfctbas[1][1] = 0;
      break;
    default:
      printf("calDerFbase : Erreur t, cas imprévu\n");
      exit(1);
      break;
    }
  }
