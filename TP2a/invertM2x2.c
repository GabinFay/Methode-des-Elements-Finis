#include "TP2A_.h"

/*
--------------------------------------------------------------------------------
    Inverse une matrice 2x2 et calcule son déterminant
--------------------------------------------------------------------------------
*/

void invertM2x2(float **M, float *pdet, float **invertM){
  float a, b, c, d, det;
  a = M[0][0]; b = M[0][1];
  c = M[1][0]; d = M[1][1];
  det = a*d - b*c;
  invertM[0][0] =   d/det; invertM[0][1] = -b/det;
  invertM[1][0] =  -c/det; invertM[1][1] = a/det;
  *pdet = det;
  }
