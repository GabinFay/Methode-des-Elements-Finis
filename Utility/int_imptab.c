#include <stdio.h>

void int_imptab(int *tab, int nb){
  for (int i = 0; i < nb; i++){
    printf("%d ", tab[i]);
  }
  printf("\n");
}