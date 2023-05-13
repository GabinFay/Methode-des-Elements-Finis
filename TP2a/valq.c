#include "TP2A_.h"

/*
--------------------------------------------------------------------------------
    renvoie la valeur du nombre de poids de quadrature en fonction du type d'élément
--------------------------------------------------------------------------------
*/

int valq(int t){
  int q;
  switch (t){
    case 1:
      q = 9;    
      break;
    case 2:
      q = 3;
      break;
    case 3:
      q = 3;
      break;
    default:
      printf("Erreur t, cas imprévu\n");
      exit(1);
      break;
  }
  
  return q;
}