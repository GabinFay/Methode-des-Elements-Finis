#include "TP2A_.h"


/*
--------------------------------------------------------------------------------
    Calcule la matrice Jacobienne de FK
--------------------------------------------------------------------------------
*/

void matJacob(float **coorEl, int nbneel, float **derfctbas, int d, float **Jac){
  switch(d){
    case 1:
      Jac[0][0] = 0; Jac[1][0] = 0;
      for(int i=0; i<2; i++){
        for(int k=0; k<2; k++){
          Jac[i][0] += coorEl[k][i]*derfctbas[k][0];
        }
      }
      break;
    case 2:
      Jac[0][0] = 0; Jac[0][1] = 0; Jac[1][1] = 0; Jac[1][1] = 0;
      for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
          for(int k=0; k<nbneel; k++){
            Jac[i][j] += coorEl[k][i]*derfctbas[k][j];
          }
        }
      }
      break;
    default:
      printf("Erreur t, cas imprévu\n");
      exit(1);
      break;
  }
}
