#include <stdio.h>
#include <stdlib.h>
#include "algoritmo.h"
#include "funcao.h"
#include "utils.h"


// Gera um vizinho � dist�ncia 1 (troca um v�rtice de cada grupo)
// Par�metros de entrada: Solu��o actual, a, Solu��o vizinha, b, N�mero de v�rtices, n
void gera_vizinho(int a[], int b[], int n)
{
    int i, p1;

    // Copia a solu��o atual para a solu��o vizinha
    for(i = 0; i < n; i++)
        b[i] = a[i];

    p1 = random_l_h(0, n-1); //devolve um numero aleat�rio entre 0 e n-1
    b[p1] = !b[p1];

}

// Gera um vizinho � dist�ncia 2 (troca dois v�rtices de cada grupo)
// Par�metros de entrada: Solu��o actual, a, Solu��o vizinha, b, N�mero de v�rtices, n
void gera_vizinho2(int a[], int b[], int n)
{
    int i, p1, p2;

    // Copia a solu��o atual para a solu��o vizinha
    for(i = 0; i < n; i++)
        b[i] = a[i];

    p1 = random_l_h(0, n-1);
    do{
      p2 = random_l_h(0, n-1);
    }
    while(p1 == p2);
    b[p1] = !b[p1];
    b[p2] = !b[p2];
}


// Trepa colinas first-choice
// Par�metros de entrada: Solucao, sol, Matriz de adjacencias, mat, N�mero de v�rtices, vert, N�mero de itera��es, num_iter
// Par�metros de sa�da: Custo da melhor solu��o encontrada
int trepa_colinas(int sol[], int *mat, int vert)
{
    int *nova_sol, custo, custo_viz, i;

	// Aloca espa�o em mem�ria para guardar a nova solu��o
	nova_sol = malloc(sizeof(int)*vert);

	// Caso n�o consiga fazer a aloca��o, envia aviso e termina o programa
    if (nova_sol == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }

	// Avalia solu��o inicial
    custo = calcula_fit(sol, mat, vert);
    for(i = 0; i < num_iter; i++)
    {

		// Gera solu��o vizinha
		//gera_vizinho(sol, nova_sol, vert);
		gera_vizinho2(sol, nova_sol, vert);

		// Avalia solu��o vizinha
		custo_viz = calcula_fit(nova_sol, mat, vert);


        // Fica com a solu��o vizinha se o custo aumentar (problema de maximiza��o)
        // e tamb�m aceita com o mesmo custo

        if (custo_viz >= custo)
        {
			substitui(sol, nova_sol, vert);
			custo = custo_viz;

        }
    }
	// Liberta a mem�ria usada para guardar a nova solu��o
    free(nova_sol);

	// Devolve o custo da melhor solu��o encontrada
    return custo;
}
