#include "funcao.h"

// Calcula a qualidade de uma solução
// Parâmetros de entrada: Solução actual, a, Matriz de adjacências, mat, Número de vértices, vert
// Parâmetros de saída: Custo, total - Neste caso, é o número de ligações que existem entre os vértices dos dois grupos
int calcula_fit(int a[], int *mat, int vert)
{
	int total = 0;
	int i, j;

	for (i = 0; i < vert; i++)
		if (a[i] == 0)
		{
			for (j = 0; j < vert; j++)
				if (a[j] == 1 && *(mat+i*vert+j) == 1)
				    total++;
		}
	return total;
}
