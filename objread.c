/* 
Glaide de Lara Oliveira
GRR20184567
*/ 

#include "objread.h"
#include "datatypes.h"
#include <string.h>
// funções de leitura do arquivo OBJ
//funcao que abre o objeto e verifica se foi aberto corretamente
void leObj(FILE *obj, int argc, char** argv)
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
/*----------------LE NUMERO DE VERTICES E SEUS VALORES----------------------*/
int leVert(FILE *obj, float *vetor)
{
    char texto[tam];
    int nvert=0;
    char *str=NULL;    
    //salva o conteudo do objeto num vetor de char para poder cortar
    while (fgets(texto,tam*sizeof(char),obj) != NULL)
    {
        /*verifica o primeiro e segundo espaço do vetor, pois pode haver um 
        v junto de outras palavras, de forma que não seja o conteudo procurado*/
        if( texto[0]=='v' && texto[1]==' ' )
        {
            //recebe 'v '
            //verificar melhor delimitante
            str=strtok(texto, " ");
            for (int i=0; i< colvert; i++)
            {
                //corta um novo pedaço
                str=strtok(NULL, " ");
                //salva no vetor já convertido para float
                vetor[(nvert*colvert) + i]=atof(str);
            }
            //incrementa a variavel com a quantidade de vertices
            nvert++;            
        }
    }
    /*retorna  a quantidade de vertices para caso 
    seja necessario uma nova alocação de memória*/
    return nvert;
}
/*----------------RECEBE UMA STRING E CORTA O PRIMEIRO PEDAÇO----------------------*/
//funcao para retornar apenas a primeira parte do valor de faces
char *corte(char *str)
{
    //ira dividir a palavra por / e retornar apenas a primeira parte
    char *aux=NULL  
    aux=strtok(str, "/");
    return aux;
}

/*----------------IGNORA OS COMENTARIOS DO ARQUIVO----------------------*/
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
/*----------------LE NUMERO DE FACES E SEUS VALORES----------------------*/
int leFaces(FILE *obj, int *faces)
{
    char texto[tam];
    char *str=NULL;
    /*variavel usada para verificar qual é o 
    maior numero de vertices em uma face*/
    int maxvert=0;
    int maxfaces=0;

    while (fgets(texto,tam*sizeof(char),obj) != NULL)
    {
        /*verifica o primeiro e segundo espaço do vetor, pois pode haver um 
        f junto de outras palavras, de forma que não seja o conteudo procurado*/
        if ( texto[0] == 'f' && texto[1] == ' ')
        {
            str=strtok(texto, " ");
            for (int i=0; i<colfaces; i++)
            {
                //laço para garantir que não ira pegar nenhum valor que seja 'f '
                if (texto[0] != 'f' && texto[1] != ' ')
                {
                    str=strtok(NULL, " ");
                    //pega apenas o primeiro pedaço antes do /
                    str=corte(str);
                    faces[(maxvert*maxfaces) + i]=atoi(str);
                    //incrementa a variavel com a quantidade de vertices                    
                    maxvert++;
                }
            }
            maxfaces++;
        }
    }
    if (maxvert < colfaces && maxfaces < tam )
        faces=realloc(faces, maxfaces*maxvert(sizeof(int)));
    else ( maxfaces < tam)
        faces=realloc(faces, maxfaces*colvert(sizeof(int)));
}