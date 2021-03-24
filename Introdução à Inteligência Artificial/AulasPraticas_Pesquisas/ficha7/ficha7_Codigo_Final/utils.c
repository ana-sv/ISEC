#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

// Leitura do ficheiro de input
// Parâmetros de entrada: Nome do ficheiro, nome, Número de vértices, n, Número de iterações, iter
// Parâmetros de saída: Matriz de adjacências, p
int* init_dados(char *nome, int *n, int *iter)
{
	FILE    *f;
	int     *p, *q;
	int     i, j;

	f=fopen(nome, "r");
	if (!f)
	{
		printf("Erro no acesso ao ficheiro dos dados\n");
		exit(1);
	}
	// Lê o número de iteracoes
	fscanf(f, " %d", iter);
	// Lê o número de vértices
	fscanf(f, " %d", n);
	// Aloca espaço em memória para guardar a matriz de adjacências
	p = malloc(sizeof(int)*(*n)*(*n));
	if (!p)
	{
	    printf("Erro na alocacao de memoria\n");
	    exit(1);
	}
	q = p;
	// Preenchimento da matriz de adjacências
	for (i = 0; i < *n; i++)
        for (j=0; j < *n; j++)
            fscanf(f, " %d", q++);
	fclose(f);
	// Devolve a matriz de adjacências
	return p;
}

// Gera a solução inicial
// Parâmetros de entrada: Solução, sol, Número de vertices, v
void gera_sol_inicial(int *sol, int v)
{
	int i, x;

	for (i = 0; i < v; i++)
        sol[i] = 0;
	for (i = 0; i < v/2; i++)
    {
        do
			x = random_l_h(0, v-1);
        while (sol[x] != 0);
        sol[x] = 1;
    }
}

// Escreve solução no ecrã
// Parâmetros de entrada: Solução, sol, Número de vertices, vert
void escreve_sol(int *sol, int vert)
{
	int i;

	printf("\nConjunto A: ");
	for (i = 0; i < vert; i++)
		if(sol[i] == 0)
			printf("%2d  ", i);
	printf("\nConjunto B: ");
	for (i = 0; i < vert; i++)
		if (sol[i] == 1)
			printf("%2d  ", i);
	printf("\n");
}

// copia vector b para a (tamanho n)
// Parâmetros de entrada: Solução que será substituída, a, Solução que irá substituir, b, Número de vertices, n
void substitui(int a[], int b[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        a[i] = b[i];
}

// Inicializa o gerador de números aleatórios
void init_rand()
{
	srand((unsigned)time(NULL));
}

// Gera um valor inteiro aleatório entre min e max
// Parâmetros de entrada: Valor inferior do intervalo, min, Valor superior do intervalo, max
// Parâmetros de saída: Valor aleatório entre min e max
int random_l_h(int min, int max)
{
	return min + rand() % (max - min + 1);
}

// Gera um valor inteiro aleatório entre 0 e 1
// Parâmetros de saída: Valor aleatório entre 0 e 1
float rand_01()
{
	return ((float)rand()) / RAND_MAX;
}
