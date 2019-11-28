// Glaide de Lara Oliveira
// GRR20184567
#include "graphics.h"

void imprime_objeto(SDL_Renderer *renderer, convert *doisD, f *faces, int tamf, int tamv)
{
    //seta as cores para fazer os desenhos
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);	
    
    //imprime os vertices
    for (int i=0; i<tamv; i++)
        SDL_RenderDrawPoint(renderer, (int)doisD[i].x, (int)doisD[i].y);
    //desenha os pontos na tela
    //vericar como apagar as linhas repetidas

    for (int j=0; j>tamf; j++)
    {
        for (int k=0; k< faces[j].tamf; k++)
        {

            if(faces[j].v[k] == tamf)
            {
            // caso seja o ultimo vertice
                SDL_RenderDrawLine(renderer,
                (int)doisD[faces[j].v[k]].x, 
                (int)doisD[faces[j].v[k]].y, 
                (int)doisD[faces[j].v[0]].x, 
                (int)doisD[faces[j].v[0]].y);
            }
            else
            {
                SDL_RenderDrawLine(renderer,
                (int)doisD[faces[j].v[k]].x, 
                (int)doisD[faces[j].v[k]].y,
                (int)doisD[faces[j].v[k]+1].x,
                (int)doisD[faces[j].v[k]+1].y);
            }
            
        }
    }
}



//diz qual o indice 
