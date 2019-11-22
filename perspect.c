// Glaide de Lara Oliveira
// GRR20184567
#include "perspect.h"

// funções de cálculo de perspectiva

void conv2d(convert *doisD, vert *vet, FILE *obj, int tamV, vert cam)
{
    
    for (int i=0; i < tamV; i++)
    {
        // calcula a conversao para x e y em 2d
        doisD[i].x= cam.x + cam.z *( (vet[i].x - cam.x) / (vet[i].z + cam.z) );
        doisD[i].y= cam.y + cam.z *( (vet[i].y - cam.y) / (vet[i].z + cam.z) );
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

void maiores(vert camera, vert *tresd, int tamv)
{
    camera.x=0;
    camera.y=0;
    camera.z=0;

//verifica quais sao os maiores valores em 3d para setar a camera
    for (int i=0; i < tamv; i++)
    {
        if (tresd[i].x > camera.x) camera.x = tresd[i].x;
        if (tresd[i].y > camera.y) camera.y = tresd[i].y;
        if (tresd[i].z > camera.z) camera.z = tresd[i].z;
    }

}
