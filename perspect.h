// Glaide de Lara Oliveira
// GRR20184567
#ifndef perspect
#define perspect
#include "datatypes.h"
#include <stdio.h>
#include <stdlib.h>
#define W 800
#define H 600
#define espaco 50
#define menor(p,q) ((p < q)? (p):(q))

// funções de cálculo de perspectiva

void conv2d(convert *doisD, vert *vet, FILE *obj, int tamV);
void conv_coord(convert *doisD, int tamV);


#endif