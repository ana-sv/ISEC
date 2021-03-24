#include <stdio.h>
#include <stdlib.h>
#include "algoritmo.h"
#include "funcao.h"
#include "utils.h"


// Gera um vizinho à distância 1 (troca um vértice de cada grupo)
// Parâmetros de entrada: Solução actual, a, Solução vizinha, b, Número de vértices, n
void gera_vizinho(int a[], int b[], int n)
{
    int i, p1;

    // Copia a solução atual para a solução vizinha
    for(i = 0; i < n; i++)
        b[i] = a[i];

    p1 = random_l_h(0, n-1); //devolve um numero aleatório entre 0 e n-1
    b[p1] = !b[p1];

}

// Gera um vizinho à distância 2 (troca dois vértices de cada grupo)
// Parâmetros de entrada: Solução actual, a, Solução vizinha, b, Número de vértices, n
void gera_vizinho2(int a[], int b[], int n)
{
    int i, p1, p2;

    // Copia a solução atual para a solução vizinha
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
// Parâmetros de entrada: Solucao, sol, Matriz de adjacencias, mat, Número de vértices, vert, Número de iterações, num_iter
// Parâmetros de saída: Custo da melhor solução encontrada
int trepa_colinas(int sol[], int *mat, int vert)
{
    int *nova_sol, custo, custo_viz, i;

	// Aloca espaço em memória para guardar a nova solução
	nova_sol = malloc(sizeof(int)*vert);

	// Caso não consiga fazer a alocação, envia aviso e termina o programa
    if (nova_sol == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }

	// Avalia solução inicial
    custo = calcula_fit(sol, mat, vert);
    for(i = 0; i < num_iter; i++)
    {

		// Gera solução vizinha
		//gera_vizinho(sol, nova_sol, vert);
		gera_vizinho2(sol, nova_sol, vert);

		// Avalia solução vizinha
		custo_viz = calcula_fit(nova_sol, mat, vert);


        // Fica com a solução vizinha se o custo aumentar (problema de maximização)
        // e também aceita com o mesmo custo

        if (custo_viz >= custo)
        {
			substitui(sol, nova_sol, vert);
			custo = custo_viz;

        }
    }
	// Liberta a memória usada para guardar a nova solução
    free(nova_sol);

	// Devolve o custo da melhor solução encontrada
    return custo;
}
