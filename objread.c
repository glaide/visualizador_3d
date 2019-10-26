// Glaide de Lara Oliveira
// GRR20184567

#include "objread.h"
#include "datatypes.h"
#include <string.h>
// funções de leitura do arquivo OBJ
//funcao que abbre o objeto e verifica se foi aberto corretamente
void leObj(FILE *obj, int argc, char**argv)
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
//funcao que le um vertice
void leVert(FILE *obj)
{
    char conteudo;
    conteudo=fgetc(obj);
    //verifica se é uma linha de vertices
    if (conteudo == 'v' && fgetc(obj)== ' ') 

}
//funcao que cria uma lista de faces
struct lista* cria_lista(struct lista* aux)
{
    vertice *aux->v=NULL;
    struct lista *aux->prox=NULL;

    return aux;
}

void ignora_comentario(FILE *obj)
{
    char lixo;
    lixo=fgetc(obj); //pega um caracter do arquivo
    do
    {
        if (lixo== '#') //verifica se é um comentario
            while (lixo != '\n')
                lixo=fgetc(obj); //enquanto n chegar no fim da linha, continua lendp
        else
            ungetc(lixo,obj); //devolve o caracter pro arquivo
        lixo=fgetc(obj); //le o proximo caracter
    }   while (lixo=='#');
    ungetc(lixo,obj);
}

