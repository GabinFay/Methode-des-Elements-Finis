#include "TP1_.h"



int main(void){
  char * ficmai = "maill_file.txt";
  int typel = 0;
  int n = 0;
  int m = 0;
  int p = 0;
  int q = 0;
  float **coord = NULL;
  int **ngnel = NULL;
  int **nRefAr = NULL;
  lecfima(ficmai, &typel, &n, &coord, &m, &ngnel, &p, &q, &nRefAr);
  printf("after lecfima\n");
  printf("%p\n", coord);
  printf("%d\n", nRefAr[5][0]);
  float_freetab(coord);
  int_freetab(ngnel);
  int_freetab(nRefAr);
  printf("%d\n", nRefAr[5][2]);
  return 0;
}
