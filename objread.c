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
    int nvert = 0;
    int nova = tam;

    char *str = NULL;
    if (obj == NULL)
    {
        printf("Erro ao ler o arquivo, tente novamente...");
        exit(-1);
    }
    //salva o conteudo do objeto num vetor de char para poder cortar
    while (fgets(texto, tam, obj) != NULL)
    {
	//caso acabem os v's e comece f, volta para reler e nao perder
        if (texto[0] == 'f')
        {
            fseek(obj, -strlen(texto), SEEK_CUR);
            break;
        }

        //verifica se o tamanho é suficiente para continuar a leitura
        if (nvert < nova)
        {
            /*verifica o primeiro e segundo espaço do vetor, pois pode haver um 
            v junto de outras palavras, de forma que não seja o conteudo procurado*/
            if (texto[0] == 'v' && texto[1] == ' ')
            {
                //recebe 'v '
                str = strtok(texto, " ");
                // corta um novo pedaço
                str = strtok(NULL, " ");
                // salva no vetor já convertido para float
                vetor[nvert].x = atof(str);
                str = strtok(NULL, " ");
                vetor[nvert].y = atof(str);
                str = strtok(NULL, " ");
                vetor[nvert].z = atof(str);
               
                //incrementa a variavel com a quantidade de vertices
                nvert++;
            }
        }
        /*caso foi ate o max ja alocado*/
        else if (nvert == nova)
        {
            //atualizo um novo tamanho com a soma de + 100
            nova = nvert + step;
            /*faz uma nova alocacao de espaco*/
            vetor = realloc(vetor, nova * sizeof(vert) );
            //verifica se foi alocado corretamente
            if (!vetor)
            {
                printf("Erro na alocação de memória, tente novamente...\n");
                exit(-1);
            }
        }
    }

    return nvert;
}

/*----------------LE NUMERO DE FACES E SEUS VALORES----------------------*/
int leFaces(FILE *obj, f *faces)
{
    char texto[tam];
    int nova = tam;
    char *str = NULL;
    /*variavel usada para verificar qual é o 
    maior numero de vertices em uma face*/
    int maxfaces = 0;
    while (fgets(texto, tam, obj) != NULL)
    {
        //caso o tamanho alocado seja necessario
        if (nova > maxfaces)
        {
            /*verifica o primeiro e segundo espaço do vetor, pois pode haver um 
            f junto de outras palavras, de forma que não seja o conteudo procurado*/
            if (texto[0] == 'f' && texto[1] == ' ')
            {
                str = strtok(texto, " ");
                faces[maxfaces].tamf = 0;
                int i=0;
                // verifica se tem uma string em str
                while( (str = strtok(NULL, "/ ")) != NULL)
                {
                    int tams=strlen(str);
                    faces[maxfaces].v[i] = atoi(str);
                    faces[maxfaces].tamf++;
                    //verifica se era um valor com /
                    if (str[tams-1] == '/') str = strtok(NULL, " ");
                    //incrementa a variavel com a quantidade de vertices
                    i++;
                }
                /*incrementa a variavel com a quantidade de faces*/
                maxfaces++;
            }
        }
        //caso seja necessario fazer uma nova alocaçao
        else if (nova == maxfaces)
        {
            //atualizo um novo tamanho com a soma de + 100
            nova = step + maxfaces;
            //faz uma nova alocação
            faces = (f *) realloc(faces, nova * sizeof(f));
            //verifica se foi alocado corretamente
            if (!faces)
            {
                printf("Erro na alocação de memória, tente novamente...\n");
                exit(-1);
            }
        }
    }
    /*retorna o valor total de faces*/
    return maxfaces;
}
