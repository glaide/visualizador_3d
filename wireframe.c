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
    //arrumar o tamanho da tela
    SDL_Window* win = SDL_CreateWindow("Visualizador 3D",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 800, 600, 0); 
    while (1); 
  

    //le o arquivo e verifica se foi aberto corretamente
    leObj(obj,argc, argv);
    
    //aloca um vetor para os vertices
    float *vertice=malloc(colvert * tam * sizeof(float));
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
    int *faces=malloc(tam * colfaces * sizeof(int));
    if (!faces)
    {
        printf("Erro na alocação de memória, tente novamente...\n");
        exit(-1);
    }
    //le o numero de vertices em cada face e salva seus indices 
    leFaces(obj,faces);

    return 0; 
}
