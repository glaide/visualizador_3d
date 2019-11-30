// arquivo principal
#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"
#include "objread.h"
#include "perspect.h"

int main(int argc, char **argv)
{
    FILE *obj = NULL;
    int tamvert, tamfaces;
    SDL_Window *win;
    SDL_Renderer *renderer;
    SDL_Event evento;
    vert camera;
    int desenha = TRUE;
    int sai = FALSE;

    //le o arquivo e verifica se foi aberto corretamente
    // leObj(obj,argc, argv);
    if (argc == 1)
        obj = stdin;
    else
        obj = fopen(argv[1], "r");

    if (obj == NULL)
    {
        printf("Erro ao ler o arquivo, tente novamente...");
        exit(-1);
    }
    //aloca um vetor para os vertices
    vert *vertice = malloc(tam * sizeof(vert *));
    //verifica se foi alocado corretamente
    if (vertice == NULL)
    {
        printf("Erro na alocação de memória, tente novamente...\n");
        exit(-1);
    }

    //le os valores do vertice e salva no vetor
    tamvert = leVert(obj, vertice);

    //aloca um vetor que guardara os vertices de cada face
    f *faces = malloc(tam * sizeof(f));
    if (faces == NULL)
    {
        printf("Erro na alocação de memória, tente novamente...\n");
        exit(-1);
    }
    //le o numero de vertices em cada face e salva seus indices
    tamfaces = leFaces(obj, faces);
    //apos pegar todas as informacoes, fecha o arquivo
    fclose(obj);
    //aloca um novo espaço para a conversao 2d
    convert *novovert = malloc(tamvert * sizeof(convert *));
    if (novovert == NULL)
    {
        printf("Erro na alocação de memória, tente novamente...\n");
        exit(-1);
    }

    // seta os valores iniciais para a camera que futuramente srao alterados
    // maiores(camera, vertice, tamvert);
    camera.x = max;
    camera.y = max;
    camera.z = max;


    //inicio da parte da biblioteca
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Não foi possível iniciar SDL: %s", SDL_GetError());
        exit(-1);
    }
    //cria janela de renderização
    if (SDL_CreateWindowAndRenderer(W, H, 0, &win, &renderer))
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Não foi possível criar a janela: %s", SDL_GetError());
        exit(-1);
    }

    //define as cores usadas para o desenho
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    // SDL_SetRenderDrawColor(renderer, 255, 255, 0x00, 255);
    //limpa a tela de renderização
    SDL_RenderClear(renderer);

    while (!sai)
    {
        /*acha o evento na fila*/
        SDL_PollEvent(&evento);
        /*caso aperte o botao para fechar*/
        if (evento.type == SDL_QUIT)
            break;
        /*para receber as teclas pressionadas*/
        if (evento.type == SDL_KEYDOWN)
        {
            switch (evento.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                sai = FALSE;
                break;

            /*neste caso acrescenta a variavel para mexer a camera*/
            case SDLK_DOWN:
                camera.y--;
                desenha = TRUE;
                break;
            /*mesmo caso*/
            case SDLK_UP:
                camera.y++;
                desenha = TRUE;
                break;

                /*ajusta os valores para o x*/
            case SDLK_LEFT:
                camera.x++;
                desenha = TRUE;
                break;

                /*mesmo caso para o outro lado*/
            case SDLK_RIGHT:
                camera.x--;
                desenha = TRUE;
                break;

            default:
                break;
            }
        }

        /*caso as teclas sejam para fazer algo na visualização*/
        if (desenha)
        {
            SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
            SDL_RenderClear(renderer);
            /*funcao que calcula os novos pontos com a perspectiva fraca*/
            conv2d(novovert, vertice, obj, tamvert, camera);
            /*todos os calculos para converter as coordenadas*/
            conv_coord(novovert, tamvert);
            /*chama a funcao que ira imprimir o objeto*/
            imprime_objeto(renderer, novovert, faces, tamfaces, tamvert);

            SDL_RenderPresent(renderer);

            desenha = FALSE;
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);

    SDL_Quit();
	
    free(vertice);
    free(novovert);
    free(faces);
    return 0;
}
