// Glaide de Lara Oliveira
// GRR20184567

#ifndef __DATATYPES__
#define __DATATYPES__
// tipos de dados usados no programa

typedef struct vertice
{
    float x,y,z;
}vertice;

typedef struct lista
{
    vertice *conteudo;
    struct lista *prox;
}lista;

#endif
