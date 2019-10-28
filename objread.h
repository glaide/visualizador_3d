/* 
Glaide de Lara Oliveira
GRR20184567
*/

#ifndef objread
#define objread
// funções de leitura do arquivo OBJ
#include <stdio.h>
#include <stdlib.h>
#define tam 1000
#define colvert 3
//funcao para leitura do objeto
void leObj(FILE *obj, int argc, char**argv);
//função que ignora comentarios
void ignora_comentario(FILE *obj);
//le os vertices e retorna o valor total
int leVert(FILE *obj, float *vetor);




#endif
