// arquivo principal
#include "datatypes.h"
#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"
#include "objread.h"
#include "perspect.h"


int main(int argc, char** argv)
{
    FILE *obj;
    int nvert,nfaces;
    // returns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)  
        printf("error initializing SDL: %s\n", SDL_GetError()); 
    SDL_Window* win = SDL_CreateWindow("Visualizador 3D",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 800, 600, 0); 
    while (1); 
  

    //le o arquivo e verifica se foi aberto corretamente
    leObj(obj,argc, argv);
    
    //aloca um vetor para os vertices
    //float *vertice=malloc(colvert * tam * sizeof(float));
    float **vertice=malloc(tam * sizeof(float*));
    for (int i=0; i<tam; i++)
        vertice[i]=malloc(colvert*sizeof(float));

    if (!vertice)
    {
        printf("Erro na alocação de memória, tente novamente...\n");
        exit(-1);
    }
    
    //le os valores do vertice e salva no vetor
    nvert=leVert(obj,vertice);

    /*verifica a quantidade de vertices para saber 
    se é necessario uma nova alocação de memória*/
    if (tam > nvert)
    {
        vertice=realloc(vertice, colvert*nvert*sizeof(float));
        if(!vertice)
        {
            printf("Erro na alocação de memória, tente novamente...\n");
            exit(-1);
        }
    }

    //aloca um vetor que guardara os vertices de cada face
    //int *faces=malloc(tam * colfaces * sizeof(int));
    int **faces=malloc(tam * sizeof(int*));
    for (int i=0; i<tam; i++)
        faces[i]=malloc(colfaces*sizeof(int));
    if (!faces)
    {
        printf("Erro na alocação de memória, tente novamente...\n");
        exit(-1);
    }
    //le o numero de vertices em cada face e salva seus indices 
    nfaces=leFaces(obj,faces);

        //verifica se é necessário realocar memoria
    if ( nfaces < tam)
        faces=realloc(faces, nfaces*colvert*sizeof(int));

    return 0; 
}
