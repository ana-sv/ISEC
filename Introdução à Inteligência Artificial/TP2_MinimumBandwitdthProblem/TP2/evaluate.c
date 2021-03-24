#include "evaluate.h"

// Calcula a qualidade de uma solução
// Recebe:  A solução, a, a matriz de adjacências, mat, e o número de vértices, vert
// Devolve: O custo que é o número de ligações que existem na solução
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
