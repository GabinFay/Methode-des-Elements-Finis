#include "TP1_.h"

/*
--------------------------------------------------------------------------------
    lecture du fichier de maillage
--------------------------------------------------------------------------------
*/

int lecfima(char *ficmai, int *t, int *nbtng,\
  float ***pcoord, int *nbtel, int ***pngnel, int *nbneel,\
  int *nbaret, int ***pnRefAr){
    
  FILE *fp = fopen(ficmai, "r");
  if (fp == NULL){
    printf("lecfima : le fichier ne s'est pas ouvert correctement\n");
    exit(1);
  }
  else{
    fscanf(fp, "%d", nbtng);
    float **coord = float_alloctab((*nbtng), 2);
    for(int node = 0; node < (*nbtng); node++){
      fscanf(fp, "%f %f", &(coord[node][0]), &(coord[node][1]));
    }
    fscanf(fp, "%d %d %d %d", nbtel, t, nbneel, nbaret);


    int **ngnel = int_alloctab(*nbtel, *nbneel);
    int **nRefAr = int_alloctab(*nbtel, *nbaret);
    for(int elem = 0; elem < *nbtel; elem++){
      for(int p = 0; p < *nbneel; p++){
        fscanf(fp, "%d", &(ngnel[elem][p]));
      }
      for(int ar = 0; ar < *nbaret; ar++){
        fscanf(fp, "%d", &(nRefAr[elem][ar]));
      }
    }
    fclose(fp);
    *pcoord = coord;
    *pngnel = ngnel;
    *pnRefAr = nRefAr;
    return 0;
  }
}
