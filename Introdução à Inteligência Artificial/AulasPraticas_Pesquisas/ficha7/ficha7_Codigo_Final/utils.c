#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

// Leitura do ficheiro de input
// Par�metros de entrada: Nome do ficheiro, nome, N�mero de v�rtices, n, N�mero de itera��es, iter
// Par�metros de sa�da: Matriz de adjac�ncias, p
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
	// L� o n�mero de iteracoes
	fscanf(f, " %d", iter);
	// L� o n�mero de v�rtices
	fscanf(f, " %d", n);
	// Aloca espa�o em mem�ria para guardar a matriz de adjac�ncias
	p = malloc(sizeof(int)*(*n)*(*n));
	if (!p)
	{
	    printf("Erro na alocacao de memoria\n");
	    exit(1);
	}
	q = p;
	// Preenchimento da matriz de adjac�ncias
	for (i = 0; i < *n; i++)
        for (j=0; j < *n; j++)
            fscanf(f, " %d", q++);
	fclose(f);
	// Devolve a matriz de adjac�ncias
	return p;
}

// Gera a solu��o inicial
// Par�metros de entrada: Solu��o, sol, N�mero de vertices, v
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

// Escreve solu��o no ecr�
// Par�metros de entrada: Solu��o, sol, N�mero de vertices, vert
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
// Par�metros de entrada: Solu��o que ser� substitu�da, a, Solu��o que ir� substituir, b, N�mero de vertices, n
void substitui(int a[], int b[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        a[i] = b[i];
}

// Inicializa o gerador de n�meros aleat�rios
void init_rand()
{
	srand((unsigned)time(NULL));
}

// Gera um valor inteiro aleat�rio entre min e max
// Par�metros de entrada: Valor inferior do intervalo, min, Valor superior do intervalo, max
// Par�metros de sa�da: Valor aleat�rio entre min e max
int random_l_h(int min, int max)
{
	return min + rand() % (max - min + 1);
}

// Gera um valor inteiro aleat�rio entre 0 e 1
// Par�metros de sa�da: Valor aleat�rio entre 0 e 1
float rand_01()
{
	return ((float)rand()) / RAND_MAX;
}
