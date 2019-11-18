/* 
Glaide de Lara Oliveira
GRR20184567
*/ 

#include "objread.h"
#include "datatypes.h"
#include <string.h>
// funções de leitura do arquivo OBJ

/*----------------LE NUMERO DE VERTICES E SEUS VALORES----------------------*/
int leVert(FILE *obj, vert *vetor)
{
    char texto[tam];
    int nvert=0;
    int nova=tam;
   
    char *str=NULL;   
    if (obj == NULL)
    {
        printf("Erro ao ler o arquivo, tente novamente...");
        exit(-1);
    }  
    //salva o conteudo do objeto num vetor de char para poder cortar
    while (fgets(texto,tam,obj) != NULL)  
    {
        //verifica se o tamanho é suficiente para continuar a leitura
        if (nvert<nova)
        {
             /*verifica o primeiro e segundo espaço do vetor, pois pode haver um 
            v junto de outras palavras, de forma que não seja o conteudo procurado*/
            if( texto[0]=='v' && texto[1]==' ' )
            {
                //recebe 'v '
                str=strtok(texto, " ");
                // corta um novo pedaço   
                str=strtok(NULL, " ");
                // salva no vetor já convertido para float
                vetor[nvert].x=atof(str);
                str=strtok(NULL, " ");
                vetor[nvert].y=atof(str);
                str=strtok(NULL, " ");
                vetor[nvert].z=atof(str);
                // fscanf("%i %i %i", &vetor[nvert].x &vetor[nvert].y &vetor[nvert].z );
                //incrementa a variavel com a quantidade de vertices
                nvert++;            
            }
            fgets(texto,tam*sizeof(char),obj);
        }
        else if (nvert == nova) 
        {
            //atualizo um novo tamanho com a soma de + 100
            nova=nova+step;
            vetor=realloc(vetor, nova*sizeof(vert*));
            //verifica se foi alocado corretamente
            if(!vetor)
            {
                printf("Erro na alocação de memória, tente novamente...\n");
                exit(-1);
            }
            fgets(texto,tam*sizeof(char),obj);
            
        }
    }
    if (fgets(texto,tam,obj)== NULL)
    nova=0;
   return nova;
}
/*----------------RECEBE UMA STRING E CORTA O PRIMEIRO PEDAÇO----------------------*/
//funcao para retornar apenas a primeira parte do valor de faces
char *corte(char *str)
{
    //ira dividir a palavra por / e retornar apenas a primeira parte
    char *aux=NULL;  
    aux=strtok(str, "/");
    return aux;
}


/*----------------LE NUMERO DE FACES E SEUS VALORES----------------------*/
void leFaces(FILE *obj, int **faces)
{
    char texto[tam];
    int nova;
    char *str=NULL;
    /*variavel usada para verificar qual é o 
    maior numero de vertices em uma face*/
    int maxfaces=0;

    while (fgets(texto,tam*sizeof(char),obj) != NULL)
    {
        //caso o tamanho alocado seja necessario
        if (tam > maxfaces)
        {
            /*verifica o primeiro e segundo espaço do vetor, pois pode haver um 
            f junto de outras palavras, de forma que não seja o conteudo procurado*/
            if ( texto[0] == 'f' && texto[1] == ' ')
            {
                str=strtok(texto, " ");
                for (int i=0; i<colfaces; i++)
                    //laço para garantir que não ira pegar nenhum valor que seja 'f '
                    if (texto[0] != 'f' && texto[1] != ' ')
                    {
                        str=strtok(NULL, " ");
                        //pega apenas o primeiro pedaço antes do /
                        str=corte(str);
                        faces[maxfaces][i]=atoi(str);
                        //incrementa a variavel com a quantidade de vertices                    
                    }
                maxfaces++;
            }
            fgets(texto,tam*sizeof(char),obj);

        }
        //caso seja necessario fazer uma nova alocaçao
        else if (tam == maxfaces)
        {
            //atualizo um novo tamanho com a soma de + 100
            nova=tam+step+nova;
            faces=realloc(faces, nova*colfaces*sizeof(int));
            //verifica se foi alocado corretamente
            if(!faces)
            {
                printf("Erro na alocação de memória, tente novamente...\n");
                exit(-1);
            }
                fgets(texto,tam*sizeof(char),obj);

        }
    }
    
}

