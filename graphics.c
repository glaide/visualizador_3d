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

            if(faces[j].v[k] == (tamf-1))
            {
            // caso seja o ultimo vertice
                SDL_RenderDrawLine(renderer,
                round(doisD[faces[j].v[k]].x), 
                round(doisD[faces[j].v[k]].y), 
                round(doisD[faces[j].v[0]].x), 
                round(doisD[faces[j].v[0]].y));
		        printf("%i %i %i %i",doisD[faces[j].v[k]].x,
                doisD[faces[j].v[k]].y,
                doisD[faces[j].v[0]].x,
                doisD[faces[j].v[0]].y);
            }
            else
            {
                // para todos os outros casos, faz a linha entre eles

		        SDL_RenderDrawLine(renderer,
		        round(doisD[faces[j].v[k]].x),
                round(doisD[faces[j].v[k]].y),
                round(doisD[faces[j].v[k]+1].x),
                round(doisD[faces[j].v[k]+1].y));

            }
            
        }
    }
}



//diz qual o indice 
