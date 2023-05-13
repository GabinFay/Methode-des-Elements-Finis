#include <stdio.h>

void float_imptab(float *tab, int nb){
  for (int i = 0; i < nb; i++){
    printf("%f ", tab[i]);
  }
  printf("\n");
}