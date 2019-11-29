// Glaide de Lara Oliveira
// GRR20184567
#include "graphics.h"

void imprime_objeto(SDL_Renderer *renderer, convert *doisD, f *faces, int tamf, int tamv)
{
    //seta as cores para fazer os desenhos
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    //imprime os vertices
    for (int i = 0; i < tamv; i++)
        SDL_RenderDrawPoint(renderer, round(doisD[i].x), round(doisD[i].y));

    //desenha os pontos na tela
    //vericar como apagar as linhas repetidas

    for (int j = 0; j < tamf; j++)
    {
        for (int k = 0; k < faces[j].tamf; k++)
        {
            // para todos os outros casos, faz a linha entre eles
            SDL_RenderDrawLine(renderer,
                               (int)(doisD[faces[j].v[k]-1].x),
                               (int)(doisD[faces[j].v[k]-1].y),
                               (int)(doisD[faces[j].v[(k + 1) % (faces[j].tamf )]-1].x),
                               (int)(doisD[faces[j].v[(k + 1) % (faces[j].tamf )]-1].y));
            printf("%i %i %i %i\n",
                   faces[j].v[k]-1 ,
                   faces[j].v[k]-1 ,
                   faces[j].v[(k + 1) % (faces[j].tamf )]-1 ,
                   faces[j].v[(k + 1) % (faces[j].tamf )]-1 );
        }
    }
}

//diz qual o indice
