// Glaide de Lara Oliveira
// GRR20184567
#include "perspect.h"
#include "datatypes.h"
#include <stdlib.h>
#include <stdio.h>

// funções de cálculo de perspectiva

void persp(convert *doisD, vert *vet, FILE *obj, int tamV)
{
    /*
    xp = xc + zc × ( (xv - xc) ÷ (zv + zc) )
    yp = yc + zc × ( (yv - yc) ÷ (zv + zc) )
    */

//    vai ate o tamanho do vetor de vertices
        
    //verificar esses valores
    float xc=0;
    float yc=0;
    float zc=100;

    for (int i=0; i < tamV; i++)
    {
        doisD[i].x= xc + zc *( (vet[i].x - xc) / (vet[i].z + zc) );
        doisD[i].y= yc + zc *( (vet[i].y - yc) / (vet[i].z + zc) )
    }
   
   
}