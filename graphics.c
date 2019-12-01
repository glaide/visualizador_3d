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

    //caminha por todo o vetor de faces
    for (int j = 0; j < tamf; j++)
    {
	    //dentro de cada face, verifica todos os vertices
        for (int k = 0; k < faces[j].tamf; k++)
        {
            // liga todas as linhas  durante o for
            /*usa o mod para poder pegar tbm 0 e tamf*/
            SDL_RenderDrawLine(renderer,
                               (int)(doisD[faces[j].v[k]-1].x),
                               (int)(doisD[faces[j].v[k]-1].y),
                               (int)(doisD[faces[j].v[(k + 1) % (faces[j].tamf )]-1].x),
                               (int)(doisD[faces[j].v[(k + 1) % (faces[j].tamf )]-1].y));
        }
    }
}

//diz qual o indice
