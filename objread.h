/* 
Glaide de Lara Oliveira
GRR20184567
*/

#ifndef objread
#define objread
// funções de leitura do arquivo OBJ
#include <stdio.h>
#include <stdlib.h>
//funcao para leitura do objeto
void leObj(FILE *obj, int argc, char**argv);
//função que ignora comentarios
void ignora_comentario(FILE *obj);
//le o numero de vertices
int tamvert(FILE *obj)



#endif
