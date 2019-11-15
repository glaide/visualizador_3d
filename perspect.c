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
    float x_min, x_max, y_min,y_max, x_cent, y_cent, x_dif, y_dif,x_esc, y_esc, escala;   

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
    x_cent = (x_max + x_min) /2.0;
    y_cent = (y_max + y_min) /2.0;

    // seta os valores de diferença
    x_dif=x_max - x_min;
    y_dif=y_max - y_min;

    //seta os valores para escala
    x_esc= W/x_dif;
    y_esc=H/y_dif;

    //calcula o valor para a escala
    escala=menor(x_esc,y_esc);

    //faz os calculos dos valores para plotagem
    for (int i=0; i < tamV; i++)
    {
        float aux=((doisD[i].x - x_cent)*escala) + W/2;
        doisD[i].x=aux;
        aux=((doisD[i].y - y_cent)*escala) + H/2;
        doisD[i].y=aux;
    }

}
