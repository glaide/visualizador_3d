/* 
Glaide de Lara Oliveira
GRR20184567
*/

// funções de leitura do arquivo OBJ

#ifndef objread
#define objread
#include <stdio.h>
#include <stdlib.h>
#define tam 20000
#define colvert 3
#define colfaces 20

//funcao para leitura do objeto
void leObj(FILE *obj, int argc, char**argv);

//função que ignora comentarios
void ignora_comentario(FILE *obj);

//le os vertices e retorna o valor total
int leVert(FILE *obj, float *vetor);


#endif
