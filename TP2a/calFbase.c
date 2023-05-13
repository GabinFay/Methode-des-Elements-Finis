#include "TP2A_.h"

/*
--------------------------------------------------------------------------------
    fonctions de base de l'élément de référence
--------------------------------------------------------------------------------
*/

void calFbase(int t, float *xref, float *fctbas){
  switch(t){
    case 1:
      fctbas[0] = xref[0]*(1-xref[1]);
      fctbas[1] = xref[0]*xref[1];
      fctbas[2] = xref[1]*(1-xref[0]);
      fctbas[3] = (1-xref[0])*(1-xref[1]);
      break;
    case 2:
      fctbas[0] = xref[0];
      fctbas[1] = xref[1];
      fctbas[2] = 1 - xref[0] - xref[1];
      break;
    case 3:
      fctbas[0] = xref[0];
      fctbas[1] = 1-xref[0];
      break;
    default:
      printf("calFbase : Erreur t, cas imprévu\n");
      exit(1);
      break;
    }
  }
