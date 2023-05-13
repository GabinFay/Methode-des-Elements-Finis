#include <stdio.h>
#include <stdlib.h>
#include "tp1.h"
#include "tp2a.h"
#include "tp2b.h"

float **float_alloctab(int dim1, int dim2) {
  float **ptr;

  ptr = malloc(dim1*sizeof(*ptr));
  if (ptr != NULL) {
    int taille_ligne = dim2*sizeof(**ptr);
    float *tmp = malloc(dim1*taille_ligne);
    if (tmp != NULL) {
      for (int i = 0; i<dim1; i++) {
  	ptr[i] = tmp;
  	tmp += dim2;
  	}
      }
    else
      ptr = NULL;
    }
  return(ptr);
}
