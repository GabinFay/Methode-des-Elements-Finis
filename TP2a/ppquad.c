#include "TP2A_.h"

/*
--------------------------------------------------------------------------------
    renvoie les points et poids de quadrature
--------------------------------------------------------------------------------
*/

void ppquad(int t, float *wk, float **xk){
  FILE *fp;
  float a; float b;
  int q = valq(t);

  switch(t){
    case 1:
      fp = fopen("../../TP2a/ppquad_1.txt", "r");
      break;
    case 2:
      fp = fopen("../../TP2a/ppquad_2.txt", "r");
      break;
    case 3:
      fp = fopen("../../TP2a/ppquad_3.txt", "r");
      break;
    default:
      printf("ppquad : Erreur t, cas imprévu\n");
      exit(1);
      break;
  }
  
  if (fp == NULL){
    printf("ppquad : le fichier ne s'est pas ouvert correctement\n");
    exit(1); 
  }
  else{
    switch(t){
      case 1:
        for (int i = 0; i < q; i++){
          fscanf(fp, "%f %f", &a, &b);
          wk[i] = a / b;
        }
        for (int i = 0; i < q; i++){
          fscanf(fp, "%f %f", &(xk[i][0]), &(xk[i][1]));
        }
        
        break;
      case 2:
        for (int i = 0; i < q; i++){
          fscanf(fp, "%f %f", &a, &b);
          wk[i] = a / b;
        }
        for (int i = 0; i < q; i++){
          fscanf(fp, "%f %f", &(xk[i][0]), &(xk[i][1]));
        }
        break;
      case 3:
        for (int i = 0; i < q; i++){
          fscanf(fp, "%f %f", &a, &b);
          wk[i] = a / b;
        }
        for (int i = 0; i < q; i++){
          fscanf(fp, "%f %f", &(xk[i][0]), &(xk[i][1]));
        }
        break;
    }
    fclose(fp);
  
  }
}
