// arquivo principal
#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"
#include "objread.h"
#include "perspect.h"


int main(int argc, char** argv)
{
    FILE *obj;

    //le o arquivo e verifica se foi aberto corretamente
    leObj(obj,argc, argv);
    
    //aloca um vetor para os vertices
    vert *vertice=malloc(tam * sizeof(vert*));
    //verifica se foi alocado corretamente
    if (!vertice)
    {
        printf("Erro na alocação de memória, tente novamente...\n");
        exit(-1);
    }
    
    //le os valores do vertice e salva no vetor
    leVert(obj,vertice);

 
    //aloca um vetor que guardara os vertices de cada face
    int **faces=malloc(tam * sizeof(int*));
    for (int i=0; i<tam; i++)
        faces[i]=malloc(colfaces*sizeof(int));
    if (!faces)
    {
        printf("Erro na alocação de memória, tente novamente...\n");
        exit(-1);
    }
    //le o numero de vertices em cada face e salva seus indices 
    leFaces(obj,faces);

    // returns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)  
        printf("error initializing SDL: %s\n", SDL_GetError()); 
    SDL_Window* win = SDL_CreateWindow("Visualizador 3D",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 800, 600, 0); 
    while (1); 

    SDL_Delay(36);
 
    SDL_DestroyWindow(win);
    SDL_Quit();

}
