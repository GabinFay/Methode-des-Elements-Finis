#include <stdio.h>
#include <stdlib.h>
#include "tp1.h"
#include "tp2a.h"
#include "tp2b.h"

int main(void){
	/* ####### GET MESH INFOS  ###########*/
	char * filename = "info.txt";
	FILE *fp = fopen(filename, "r");
	if (fp == NULL){
		printf("le fichier ne s'est pas ouvert correctement");
	}
	float a,b,c,d;
	int n1,n2;
	int m, typel, p, q;
	int nrefdom;
	int nrefcot[4];
	fscanf(fp, "%f %f %f %f", &a, &b, &c, &d);
	fscanf(fp, "%d %d", &n1, &n2);
	fscanf(fp, "%d %d %d %d" , &m, &typel, &p, &q);
	fscanf(fp, "%d %d %d %d %d", &nrefdom, nrefcot,\
	nrefcot+1, nrefcot + 2, nrefcot + 3);
	fclose(fp);

	int **nRefAr;
	nRefAr = int_alloctab(m, q);
	etiqAr(typel, n1,n2,nrefdom, nrefcot, m, q, nRefAr);

/* ####### CREATE MESH FILE  ####### "*/
	char * maill_file = "maill_file.txt";
	FILE *fp1 = fopen(maill_file, "w");
	fprintf(fp1, "%d\n", n1 * n2);

	float hx = (b-a)/(n1-1);
	float hy = (d-c)/(n2-1);

	for (int j = 0; j < n2; j++){
	   for (int i = 0; i < n1; i++){
	      fprintf(fp1, "%f " , a + i * hx);
	      fprintf(fp1, "%f\n" , c + j * hy);
	   }
	}

	fprintf(fp1, "%d %d %d %d\n", m, typel, p, q);
#include "TP1_.h"

switch (typel){
	case 1:
		for (int i = 0; i < n2-1 ; i++){
   		for (int j = 0; j < n1-1; j++){
	    	int a1, a2, a3, a4;
	      a1 = i * n1 + j + 1;
	      a2 = a1 + 1;
	      a3 = (i+1) * n1 + j + 1;
       	a4 = a3 + 1;
	      fprintf(fp1, "%d %d %d %d", a2, a4, a3, a1);
      	for(int ar = 0; ar < q; ar++){
					fprintf(fp1, " %d", nRefAr[i*(n1-1) + j][ar]);
				}
				fprintf(fp1,"\n");
	   	}
		}
		break;

	case 2:
		for (int i = 0; i < n2-1 ; i++){
	  	for (int j = 0; j < n1-1; j++){
	    	int a1, a2, a3, a4;
	      a1 = i * n1 + j + 1;
	      a2 = a1 + 1;
	      a3 = (i+1) * n1 + j + 1;
	      a4 = a3 + 1;
	      fprintf(fp1, "%d %d %d", a2, a3, a1);
				for(int ar = 0; ar < q; ar++){
					fprintf(fp1, " %d", nRefAr[2*i*(n1-1) + 2*j][ar]);
				}
		 	 	fprintf(fp1, "\n%d %d %d", a3, a2, a4);
				for(int ar = 0; ar < q; ar++){
					fprintf(fp1, " %d", nRefAr[2*i*(n1-1) + 2*j + 1][ar]);
				}
				fprintf(fp1, "\n");
      }
		}
		break;
	}

free(nRefAr);
return 0;
}
