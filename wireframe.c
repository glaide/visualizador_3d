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
    int tamV, **matriz;

    // returns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)  
        printf("error initializing SDL: %s\n", SDL_GetError()); 
     
    SDL_Window* win = SDL_CreateWindow("GAME",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 1000, 1000, 0); 
    while (1); 
  

    //le o arquivo e verifica se foi aberto corretamente
    leObj(obj,argc, argv);

    //recebe a quantidade de vertices 
    tamV=tamvert(obj);
    




    return 0; 
}
