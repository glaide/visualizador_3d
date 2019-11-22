// Glaide de Lara Oliveira
// GRR20184567

// tipos de dados usados no programa

#ifndef __DATATYPES__
#define __DATATYPES__
#define colfaces 15
typedef struct convert
{
    float x,y;
}convert;

typedef struct vert
{
    float x,y,z;
}vert;

typedef struct f
{
    int v[colfaces];
    int tamf;
}f;

#endif
