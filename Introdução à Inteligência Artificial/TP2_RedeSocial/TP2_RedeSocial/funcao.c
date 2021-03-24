#include "funcao.h"

// Calcula a qualidade de uma solução
// Recebe:  A solução, a, a matriz de adjacências, mat, e o número de vértices, vert
// Devolve: O número de ligações que existem numa solução valida
int calcula_fit(int a[], int *mat, int vert)
{
	int total=0, count=0;
	int i, j;

	for(i=0; i<vert; i++){
		if(a[i]== 1)
		{
			for(j=0; j<vert;j++)
				if(a[j]== 1 && *(mat+i*vert+j)== 1)
                    total++;  // --> total de ligaçoes/arestas comuns
		}

	}


	if (total == 0 ) // solucao valida , ou seja nao existem arestas comuns, são os conjuntos que queremos
        {
            for(j=0; j<vert; j++)
            {
                if(a[j]== 1)
                    count++;
                return count;
            }
        }
    else
        return -total; //-> penalização informada

}
