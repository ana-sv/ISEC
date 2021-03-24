#include "funcao.h"

// Calcula a qualidade de uma solu��o
// Recebe:  A solu��o, a, a matriz de adjac�ncias, mat, e o n�mero de v�rtices, vert
// Devolve: O n�mero de liga��es que existem numa solu��o valida
int calcula_fit(int a[], int *mat, int vert)
{
	int total=0, count=0;
	int i, j;

	for(i=0; i<vert; i++){
		if(a[i]== 1)
		{
			for(j=0; j<vert;j++)
				if(a[j]== 1 && *(mat+i*vert+j)== 1)
                    total++;  // --> total de liga�oes/arestas comuns
		}

	}


	if (total == 0 ) // solucao valida , ou seja nao existem arestas comuns, s�o os conjuntos que queremos
        {
            for(j=0; j<vert; j++)
            {
                if(a[j]== 1)
                    count++;
                return count;
            }
        }
    else
        return -total; //-> penaliza��o informada

}
