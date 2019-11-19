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
    SDL_Event evento;
    vert camera;


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

    // seta os valores iniciais para a camera que futuramente srao alterados
    maiores(camera, vertice, tamvert);

    // funcao que calcula os novos pontos com a perspectiva fraca
    conv2d(novovert, vertice,obj,tamvert, camera);


    //inicio da parte da biblioteca
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Não foi possível iniciar SDL: %s", SDL_GetError());
        exit(-1);
    }
    //cria janela de renderização
    if (SDL_CreateWindowAndRenderer(W,H, 0, &win,&renderer)) 
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Não foi possível criar a janela: %s", SDL_GetError());
        exit(-1);
    }

    //define as cores usadas para o desenho
   	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
	//limpa a tela de renderização
    SDL_RenderClear(renderer);

    while (1) 
    {
        while (SDL_PollEvent(&evento)) 
        {
            // fecha a janela
            if (evento.type == SDL_QUIT) break;

            // caos alguma tecla seja apertada
            if(evento.type == SDL_KEYDOWN)
            {
                switch (evento.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    
                    break;
                
                case SDLK_UP:
                    break;

                case SDLK_DOWN:
                    break;

                case SDLK_LEFT:
                    break;
                
                case SDLK_RIGHT:
                    break;
                
                default:
                    break;
                }
            }
        }
    }
    /* do some other stuff here -- draw your app, etc. */
}
   
}
