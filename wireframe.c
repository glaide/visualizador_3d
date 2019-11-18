// arquivo principal
#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"
#include "objread.h"
#include "perspect.h"


int main(int argc, char** argv)
{
    FILE *obj=NULL;
    int tamvert;
    SDL_Window *win;
    SDL_Renderer *renderer;
    // SDL_Event evento;


    //le o arquivo e verifica se foi aberto corretamente
    // leObj(obj,argc, argv);

    if (argc == 1)
        obj=stdin;
    else
        obj=fopen(argv[1],"r");
    
    if (obj == NULL)
    {
        printf("Erro ao ler o arquivo, tente novamente...");
        exit(-1);
    } 
    
    //aloca um vetor para os vertices
    vert *vertice=malloc(tam * sizeof(vert*));
    //verifica se foi alocado corretamente
    if (vertice == NULL)
    {
        printf("Erro na alocação de memória, tente novamente...\n");
        exit(-1);
    }
    
    //le os valores do vertice e salva no vetor
    tamvert=leVert(obj,vertice);
 
    //aloca um vetor que guardara os vertices de cada face
    int **faces=malloc(tam * sizeof(int*));
    for (int i=0; i<tam; i++)
        faces[i]=malloc(colfaces*sizeof(int));
    if (faces == NULL)
    {
        printf("Erro na alocação de memória, tente novamente...\n");
        exit(-1);
    }
    //le o numero de vertices em cada face e salva seus indices 
    leFaces(obj,faces);

    //aloca um novo espaço para a conversao 2d
    convert *novovert=malloc(tam * sizeof(convert*));
    if (novovert == NULL)
    {
        printf("Erro na alocação de memória, tente novamente...\n");
        exit(-1);
    }

    // funcao que calcula os novos pontos com a perspectiva fraca
    conv2d(novovert, vertice,obj,tamvert);

    for (int i=0; i<tamvert; i++)
    {
        printf("%f %f %f", novovert[i].x, novovert[i].y);
    }

    //inicio da parte da biblioteca
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Não foi possível iniciar SDL: %s", SDL_GetError());
        exit(-1);
    }
    //cria janela de renderização
    if (SDL_CreateWindowAndRenderer(W,H, 0, win,renderer)) 
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Não foi possível criar a janela: %s", SDL_GetError());
        exit(-1);
    }

    //define as cores usadas para o desenho
   	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
	//limpa a tela de renderização
    SDL_RenderClear(renderer);
   
  

}
