/* 
Glaide de Lara Oliveira
GRR20184567
*/

// funções de leitura do arquivo OBJ

#ifndef objread
#define objread
#include <stdio.h>
#include "datatypes.h"

#include <stdlib.h>
#define tam 100
#define step 100
#define colfaces 15

//função que ignora comentarios
void ignora_comentario(FILE *obj);

//le os vertices e retorna o valor total
int leVert(FILE *obj, vert *vetor);


//le o numero de faces e os indices dos vertices
void leFaces(FILE *obj, int **faces);


//corta a string para pegar apenas a primeira parte
char *corte(char *str);

#endif
