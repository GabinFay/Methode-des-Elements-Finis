#ifndef UTILITY_H
#define UTILITY_H

int **int_alloctab(int dim1, int dim2);

int **int_calloctab(int dim1, int dim2);

float **float_alloctab(int dim1, int dim2);

float **float_calloctab(int dim1, int dim2);

void freetab(void *ptr);

void float_imptab(float *tab, int nb);

void int_imptab(int *tab, int nb);

char* concat(const char *s1, const char *s2);

#endif