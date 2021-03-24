#include "evaluate.h"

// Calcula a qualidade de uma solu��o
// Recebe:  A solu��o, a, a matriz de adjac�ncias, mat, e o n�mero de v�rtices, vert
// Devolve: O custo que � o n�mero de liga��es que existem na solu��o
int calcula_fit(int a[], int *mat, int vert, int arest)
{
    int i, diferenca=0, diferencaMax=0;
    int v1=0, v2=0;

    for(i=0; i<arest; i++)
    {
        v1=(*(mat+(arest)*i+0))-1;
        v2=(*(mat+(arest)*i+1))-1;

        diferenca = abs(a[v1]-a[v2]);
        //printf("\n %d %d",a[v1],a[v2]);
       // printf(" diferenca = %d\n", diferenca);

        if(diferenca>diferencaMax)
            diferencaMax=diferenca;

    }

   // printf("\n\n diferencaMax / Custo: %d", diferencaMax);
    return diferencaMax;
}
