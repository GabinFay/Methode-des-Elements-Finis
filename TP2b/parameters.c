#include "TP2B_.h"

/*
--------------------------------------------------------------------------------
    Réglage des coefficients de l'équation
--------------------------------------------------------------------------------
*/

extern int nucas;
extern int normale;

float A00(float *x){
  float y;
  switch (nucas){
    case 0:
      y = 1;
      break;
    case 1:
      y = 0;
      break;
    case 2:
      y = 0;
      break;
    case 3:
      y = 1;
      break;
    default:
      printf("A00 : Erreur t, cas imprévu\n");
      exit(1);
      break;
    }
  return y;
}

float A11(float *x){
  float y;
  y = 1;
  return y;
}

float A12(float *x){
  float y;
  y = 0;
  return y;
}

float A22(float *x){
  float y;
  y = 1;
  return y;
}

float BN(float *x){
  float y;
  switch (nucas){
    case 0:
      y = 1;
      break;
    case 1:
    case 2:
    case 3:
      y = 4;
      break;
    default:
      printf("BN : Erreur t, cas imprévu\n");
      exit(1);
      break;
  }
  return y;
}

float FOMEGA(float *x){
  float y;
  float pi = 3.14159;
  switch(nucas){
    case 0: //Exemple des TP3 & TP4
      y = 1;
      break;
    case 1:
      y = 32*(x[0]*(1-x[0]) + x[1]*(1-x[1]));
      break;
    case 2:
      y = 2 * pi * pi * sin(pi*x[0]) * sin(pi*x[1]);
      break;
    case 3:
      y = (1 + 2*pi*pi)*cos(pi*x[0])*cos(pi*x[1]);  
      break;
    default: 
      printf("FOMEGA : Exemple non prévu\n");
      exit(1);
      break;
  }
  return y;
}

float FN(float *x){
  float y;
  float pi = 3.14159;
  float nu[2];
  switch (nucas){
    case 0:
      y = 1;
      break;
    case 1:
    case 2:
    case 3:
      switch (normale){
        case 1:
          nu[0] = 0;  nu[1] = -1;
          break;
        case 2:
          nu[0] = 1;  nu[1] = 0;
          break;
        case 3:
          nu[0] = 0;  nu[1] = 1;
          break;
        case 4:
          nu[0] = -1; nu[1] = 0;
          break;
        default:
          printf("FN : Erreur normale, cas imprévu\n");
          exit(1);
          break;
      }
      y = -pi * nu[0] * sin(pi*x[0])*cos(pi*x[1]) -pi * nu[1] * sin(pi*x[1])*cos(pi*x[0]) + BN(x) * cos(pi*x[0])*cos(pi*x[1]);
      break;
      default:
        printf("FN : Erreur nucas, cas imprévu\n");
        exit(1);
        break;
  }
  return y;
}

float UD(float *x){
  float pi = 3.14159;
  float y;
  switch(nucas){
    case 0:
      y = 100*x[0] +x[1];
      break;
    case 1:
      break;
    case 2:
      break;
    case 3:
      switch(normale){
        case 1:
          y = 0;
          break;
        case 2:
          y = sin(pi) * sin(pi*x[1]);
          break;
        case 3:
          y = sin(pi) * sin(pi*x[0]);
          break;
        case 4:
          y = 0;
          break;
        default:
          printf("Erreur normale, cas imprévu\n");
          exit(1);
          break;
      }
    break;
  }
  return y;
}
