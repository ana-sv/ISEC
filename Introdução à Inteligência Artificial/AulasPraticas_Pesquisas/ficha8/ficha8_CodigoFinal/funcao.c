#define _CRT_SECURE_NO_WARNINGS 1
#include "algoritmo.h"
#include "funcao.h"

// Calcula a qualidade de uma solu��o
// Par�metros de entrada: solu��o (sol), capacidade da mochila (d), matriz com dados do problema (mat) e numero de objectos (v)
// Par�metros de sa�da: qualidade da solu��o (se a capacidade for excedida devolve 0)
float eval_individual(int sol[], struct info d, int mat[][2], int *v)
{
	int     i;
	float   sum_weight, sum_profit;

	sum_weight = sum_profit = 0;
	// Percorre todos os objectos
	for (i=0; i < d.numGenes; i++)
	{
        // Verifica se o objecto i esta na mochila
		if (sol[i] == 1)
		{
            // Actualiza o peso totals
			sum_weight += mat[i][0];
            // Actualiza o lucro total
			sum_profit += mat[i][1];
		}
	}
	if (sum_weight > d.capacity)
	{
        // Solucao inv�lida
		*v = 0;
		return 0;
	}
	else
	{
        // Solucao v�lida
		*v = 1;
		return sum_profit;
	}
}
/*
//Tornar as solu��es inv�lidas em v�lidas -> repara��o 1
void reparacao1(int sol[], struct info d, int mat [][2]){
    float sun_pesos = 0;
    int p1,i;

    for(i=0; i<d.numGenes; i++)
        if(sol[i]==1)
            sun_pesos=sun_pesos+mat[i][0];

    while(sun_pesos > d.capacity){
        do{
            p1=random_l_h(0,d.numGenes-1);
        }while(sol[p1]!=1);

        sol[p1]=0;
        sun_pesos=sun_pesos-mat[p1][0];
    }

}*/



//Tornar as solu��es inv�lidas em v�lidas -> Repara��o2
void reparacao1(int sol[], struct info d, int mat [][2]){
    float sun_pesos = 0;
    int p1,i, menor;

    for(i=0; i<d.numGenes; i++)
        if(sol[i]==1)
            sun_pesos=sun_pesos+mat[i][0];

    while(sun_pesos > d.capacity){
        menor=1000000;
        for(i=0; i<d.numGenes; i++){
            if (sol[i] == i && mat[i][1] < menor)
            {
                menor = mat [i][1];
                p1=i;
            }
        }
        sol[p1]=0;
        sun_pesos=sun_pesos-mat[p1][0];
    }
}

// Avaliacao da popula��o
// Par�metros de entrada: populacao (pop), estrutura com parametros (d) e matriz com dados do problema (mat)
// Par�metros de sa�da: Preenche pop com os valores de fitness e de validade para cada solu��o
void evaluate(pchrom pop, struct info d, int mat[][2])
{
	int i;

	for (i=0; i<d.popsize; i++){
        reparacao1(pop[i].p , d, mat);
        pop[i].fitness = eval_individual(pop[i].p, d, mat, &pop[i].valido);
	}
}






float eval_individual2(int sol[], struct info d, int mat[][2], int *v)
{
	int     i;
	float   sum_weight, sum_profit, ro, penalizacao;

	sum_weight = sum_profit = 0;
	d.ro = -1;

	// Percorre todos os objectos
	for (i!=0; i < d.numGenes; i++)
	{
        // Verifica se o objecto i esta na mochila
		if (sol[i] == 1)
		{
            // Actualiza o peso totals
			sum_weight += mat[i][0];
            // Actualiza o lucro total
			sum_profit += mat[i][1];
			//Calcular o ro
			ro= mat[i][1]/mat[i][0];
			if (ro > d.ro)
                d.ro = ro;
		}
	}
	penalizacao = d.ro *(sum_weight-d.capacity);
	if (sum_weight > d.capacity)
	{
        // Solucao inv�lida
		*v = 0;
		return sum_profit-penalizacao;
	}
	else
	{
        // Solucao v�lida
		*v = 1;
		return sum_profit;
	}
}
