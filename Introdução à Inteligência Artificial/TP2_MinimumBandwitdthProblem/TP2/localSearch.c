#include "localSearch.h"


// Gera um vizinho � dist�ncia 1 (troca um v�rtice de cada grupo)
// Par�metros de entrada: Solu��o actual, a, Solu��o vizinha, b, N�mero de v�rtices, n
void gera_vizinho(int a[], int b[], int n)
{
    int i, pos=0, posi=0;

    // Copia a solu��o atual para a solu��o vizinha
    for(i = 0; i < n; i++)
        b[i] = a[i];

    pos=random_l_h(0,n-1);
    posi=random_l_h(0,n-1);
    while(pos==posi){
        posi=random_l_h(1,n-1);
    }

    b[pos]=a[posi];
    b[posi]=a[pos];

    /*
    printf("\n\nSolucao:     ");
    for(i = 0; i < n; i++)
        printf(" %d", a[i]);

    printf("\nNova Solucao:");
    for(i = 0; i < n; i++)
        printf(" %d", b[i]);
    */
}

// Gera um vizinho � dist�ncia 2 (troca dois v�rtices de cada grupo)
// Par�metros de entrada: Solu��o actual, a, Solu��o vizinha, b, N�mero de v�rtices, n
void gera_vizinho2(int a[], int b[], int n)
{
    int i, p1, p2, p3, p4;

    // Copia a solu��o atual para a solu��o vizinha
    for(i = 0; i < n; i++)
        b[i] = a[i];

    p1=random_l_h(0,n-1);
    p2=random_l_h(0,n-1);
    p3=random_l_h(0,n-1);
    p4=random_l_h(0,n-1);

    while(p1==p2 || p1==p3 || p1==p4 || p2==p3 || p2==p4 || p3==p4){
            p2=random_l_h(1,n-1);
            p3=random_l_h(1,n-1);
            p4=random_l_h(1,n-1);

    }

    b[p1]=a[p2];
    b[p2]=a[p1];

    b[p3]=a[p4];
    b[p4]=a[p3];

    /*
    printf("\n\nSolucao:     ");
    for(i = 0; i < n; i++)
        printf(" %d", a[i]);

    printf("\nNova Solucao:");
    for(i = 0; i < n; i++)
        printf(" %d", b[i]);
    */



}


// Trepa colinas
// Parametros: solucao, matriz de adjacencias, numero de vertices e numero de iteracoes
// Devolve o custo da melhor solucao encontrada
int trepa_colinas(int sol[], int *mat, int vert, int arest, int num_iter, int viz)
{

    int *nova_sol, custo, custo_viz, i;

	nova_sol = malloc(sizeof(int)*vert);
    if(nova_sol == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }

	// Avalia solucao inicial
    custo = calcula_fit(sol, mat, vert,arest);

    for(i=0; i<num_iter; i++)
    {
		// Gera vizinho
		if(viz==1)
            gera_vizinho(sol, nova_sol, vert);
        if(viz==2)
            gera_vizinho2(sol, nova_sol, vert);


		// Avalia vizinho
		custo_viz = calcula_fit(nova_sol, mat, vert, arest);
		escreve_sol(sol, vert);
		printf("\nCusto: %d", custo_viz);

		// Aceita vizinho se o custo diminuir (problema de minimizacao)
		if(custo_viz <= custo)
       // if(custo_viz < custo)
        {
			substitui(sol, nova_sol, vert);
			custo = custo_viz;
        }
    }
    free(nova_sol);
    return custo;
}






int recristalizacao_simulada(int sol[], int *mat, int vert,int arest, int num_iter, int viz)
{
    int     *nova_sol, custo, custo_viz, i, best_custo, *best_sol;
    float   t = TMAX, decrementoT;

    // Calculo da decrementa��o de T para ir de TMAX a TMIN en num_iter
    decrementoT = (TMAX - TMIN) / num_iter;
	// Aloca espa�o em mem�ria para guardar a nova solu��o e a melhor solu��o
	nova_sol = malloc(sizeof(int)*vert);
	best_sol = malloc(sizeof(int)*vert);
	// Caso n�o consiga fazer a aloca��o, envia aviso e termina o programa
    if(nova_sol == NULL || best_sol == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }
	// Avalia solucao inicial
    custo = calcula_fit(sol, mat, vert, arest);
    // Guarda essa solu��o inicial como a melhor
    best_custo = custo;
    substitui(best_sol, sol, vert);
    for(i=0; i < num_iter; i++)
    {

		// Gera vizinho
		if(viz==1)
            gera_vizinho(sol, nova_sol, vert);
        if(viz==2)
            gera_vizinho2(sol, nova_sol, vert);


		// Avalia solu��o vizinha
		custo_viz = calcula_fit(nova_sol, mat, vert, arest);
		// Se a solu��o vizinha for melhor que a solu��o atual, guarda-a como a melhor solu��o
		if(custo_viz < best_custo)
        {
            best_custo = custo_viz;
            substitui(best_sol, nova_sol, vert);
        }
		// Fica com a solu��o vizinha se o custo n�o aumentar (problema de minimiza��o) em rela��o � solu��o atual
        if(custo_viz <= custo)
       // if(custo_viz < custo)
        {
			substitui(sol, nova_sol, vert);
			custo = custo_viz;
        }
        else
        {
            // Fica com a solu��o vizinha, apesar de pior, se o valor aleat�rio gerado for abaixo da probabilidade que se vai ajustando
            if (rand_01() < exp((custo - custo_viz) / t))
            {
                substitui(sol, nova_sol, vert);
                custo = custo_viz;
            }
        }
        t = t - decrementoT;
    }
    // Retorna a melhor solu��o encontrada
    substitui(sol, best_sol, vert);
	// Liberta a mem�ria usada para guardar a nova solu��o e a melhor solu��o
    free(nova_sol);
    free(best_sol);
	// Devolve o custo da melhor solu��o encontrada
    return best_custo;
}
