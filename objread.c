// Glaide de Lara Oliveira
// GRR20184567

#include "objread.h"
#include "datatypes.h"
// funções de leitura do arquivo OBJ

void leObj(FILE **obj, int argc, char**argv)
{
    //verifica qual tipo de abertura do arquivo será feita
    if (argc == 1)
        obj=stdin;
    else
        obj=fopen(argv[1],"r");
    
    if (!obj)
    {
        printf("Erro ao ler o arquivo, tente novamente...");
        exit(-1);
    }
}