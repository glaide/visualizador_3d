/* 
Glaide de Lara Oliveira
GRR20184567
*/ 

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

//le o numero de vertices
int tamvert(FILE *obj)
{
    char conteudo;
    //variavel usada para contar o numero de vertices
    int tam=0;
    conteudo=fgetc(obj);
    //verifica se é uma linha de vertices
    while (conteudo != EOF)
    {
        //verifica se é um vertice, caso sim, acrescenta +1
        if (conteudo == 'v') 
        {
        tam++;
        //vai até o fim da linha
        while (conteudo != '\n')
            conteudo=fgetc(obj);
        //le novamente para testar se é outra vertice
        conteudo=fgetc(obj);
        }
    }
    //volta para o inicio do arquivo
    rewind(obj);
    return tam;
}

void leVert(FILE *obj, vertice *vetor)
{
    
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

