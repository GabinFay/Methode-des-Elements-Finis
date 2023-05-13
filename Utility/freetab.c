#include <stdio.h>
#include <stdlib.h>
#include "tp1.h"
#include "tp2a.h"
#include "tp2b.h"

/*
--------------------------------------------------------------------------------
  Cette fonction libere la memoire allouee par alloctab.
--------------------------------------------------------------------------------
*/
void freetab(void *ptr) {
  void **ptrT=ptr;
  free(ptrT[0]);
  free(ptr);
}
