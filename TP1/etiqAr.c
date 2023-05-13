#include "TP1_.h"

/*
--------------------------------------------------------------------------------
    Crée nRefAr, numéros de référence des arêtes des éléments du maillage
--------------------------------------------------------------------------------
*/

void etiqAr(int typel, int n1, int n2, int nrefdom,\
   const int *nrefcot, int nbtel, int nbaret,\
   int **nRefAr){
    // FILL THE ARRAY WITH THE VALUE NREFDOM
  for(int elem = 0; elem < nbtel; elem++){
      for(int ar = 0; ar < nbaret; ar++){
        nRefAr[elem][ar] = nrefdom;
    }
  }
  // ASSIGN VALUES TO ARETS
  switch (typel){
    case 1:
      // y = 0; Down
      for(int j = 0; j < n1 - 1; j++){
        nRefAr[j][3] = nrefcot[0];
      }
      // x = 0; Left
      for(int i = 0; i < n2 - 1; i++){
        nRefAr[i*(n1-1)][2] = nrefcot[3];
      }
      // y = n2 - 2; Up
      for(int j = 0; j < n1 - 1; j++){
        nRefAr[(n2-2)*(n1-1) + j][1] = nrefcot[2];
      }
      // x = n1 - 2; Right
      for(int i = 0; i < n2 - 1; i++){
        nRefAr[i*(n1-1) + n1 - 2][0] = nrefcot[1];
      }
      break;

    case 2:
      // y = 0; Down
      for(int j = 0; j < n1 - 1; j++){
        nRefAr[2*j][2] = nrefcot[0];
      }
      // x = 0; Left
      for(int i = 0; i < n2 - 1; i++){
        nRefAr[2*i*(n1 - 1)][1] = nrefcot[3];
      }
      // y = n2 - 2; Up
      for(int j = 0; j < n1 - 1; j++){
        nRefAr[2*(n2-2)*(n1-1) + 2*j +1][2] = nrefcot[2];
      }
      // x = n1 - 2; Right
      for(int i = 0; i < n2 - 1; i++){
        nRefAr[2*i*(n1-1) + 2*(n1 - 2) +1][1] = nrefcot[1];
      }
      break;
   }
 }
