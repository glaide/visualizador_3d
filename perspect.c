// Glaide de Lara Oliveira
// GRR20184567
#include "perspect.h"

// funções de cálculo de perspectiva

void conv2d(convert *doisD, vert *vet, FILE *obj, int tamV)
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
        // calcula a conversao para x e y em 2d
        doisD[i].x= xc + zc *( (vet[i].x - xc) / (vet[i].z + zc) );
        doisD[i].y= yc + zc *( (vet[i].y - yc) / (vet[i].z + zc) );
    }
   
}

void conv_coord(convert *doisD, int tamV)
{
    int W=800,H=600;
    float x_min, x_max, y_min,y_max, x_cent, y_cent, x_dif, y_dif;

    // seta os primeiros valores para depois comparar
    x_min = x_max = doisD[0].x;
    y_min = y_max = doisD[0].y;


    // ira procurar os maiores e menores valores de x e y
    for (int i=1; i < tamV; i++)
    {
        if (doisD[i].x > x_max) x_max = doisD[i].x;
        if (doisD[i].x < x_min) x_min = doisD[i].x;
        if (doisD[i].y > y_max) y_max = doisD[i].y;
        if (doisD[i].y < y_min) y_min = doisD[i].y;
    }

    // seta os valores do centro
    x_cent = (x_max + x_min) /2;
    y_cent = (y_max + y_min) /2;

    // seta os valores de diferença
    x_dif=x_max-x_min;
    y_dif=y_max-y_min;

}
