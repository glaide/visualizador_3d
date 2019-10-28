/* 
Glaide de Lara Oliveira
GRR20184567
*/ 

#include "objread.h"
#include "datatypes.h"
#include <string.h>
// funções de leitura do arquivo OBJ
//funcao que abre o objeto e verifica se foi aberto corretamente
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

//le os vertices e retorna o valor total
int leVert(FILE *obj, float *vetor)
{
    char texto[tam];
    int nvert=0;
    char *str=NULL;    
    //salva o conteudo do objeto num vetor de char para poder cortar
    while (fgets(texto,sizeof(tam),obj) != NULL)
    {
        /*verifica o primeiro e segundo espaço do vetor, pois pode haver um 
        v junto de outras palavras, de forma que não seja o conteudo procurado*/
        if( texto[0]=='v' && texto[1]==' ' )
        {
            //recebe 'v '
            str=strtok(texto, "\t\n ");
            for (int i=0; i< colvert; i++)
            {
                //corta um novo pedaço
                str=strtok(NULL, "\t\n ");
                //salva no vetor já convertido para float
                vetor[(nvert*colvert) + i]=atof(str);
                //incrementa a variavel com a quantidade de vertices
            }
            nvert++;            
        }
    }
    /*retorna  a quantidade de vertices para caso 
    seja necessario uma nova alocação de memória*/
    return nvert;
}

//funcao que cria uma lista de faces
//struct lista* cria_lista(struct lista* aux)
//{
//    vertice *aux->v=NULL;
//    struct lista *aux->prox=NULL;
//
//    return aux;
//}

//funcao que pula os comentarios
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

