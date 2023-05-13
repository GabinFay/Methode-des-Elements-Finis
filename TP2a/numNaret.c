#include "TP2A_.h"

/*
--------------------------------------------------------------------------------
    renvoie les numéros locaux des noeuds d'une arête
--------------------------------------------------------------------------------
*/

void numNaret(int num_ar, int t, int *nunear){
  
  nunear[0] = num_ar;
  if (num_ar == 0){
    printf("Veuillez rentrer un numéro d'arête > 0");
  }
  switch(t){
    case 1:
      if(num_ar != 4){
        nunear[1] = num_ar + 1;
      }
      else{
        nunear[1] = 1;
      }
      break;
    case 2:
      if(num_ar != 3){
        nunear[1] = num_ar + 1;
      }
      else{
        nunear[1] = 1;
      }
      break;
  default:
    printf("Please enter a valid number for t\nsquare = 1, triangle = 2, segment = 3\n");
    exit(1);
    break;
}
}
