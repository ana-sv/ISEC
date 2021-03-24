#include "utils.h"
#include "localSearch.h"

int main(int argc, char *argv[])
{
    char    nome_fich[100];
    int     vert, arest, num_iter, k, runs, custo, best_custo, txt=0, alg=0, viz=0;
    int     *grafo, *sol, *best;
    float   mbf = 0.0;

    txt = txtOptions();
    switch (txt)
    {
    case 1:
        strcpy(nome_fich,"inst_teste.txt");
        break;
    case 2:
        strcpy(nome_fich,"bcspwr01.txt");
        break;
    case 3:
        strcpy(nome_fich,"bcspwr02.txt");
        break;
    case 4:
        strcpy(nome_fich,"bcspwr03.txt");
        break;
    case 5:
        strcpy(nome_fich,"will199.txt");
        break;
    case 6:
        strcpy(nome_fich,"dwt234.txt");
        break;
    }

    alg=algOptions();

    if(alg==1 || alg==2){
        printf("\nVizinhanca?");
        scanf("%d", &viz);
    }

    /*
    printf("Runs? ");
    scanf("%d", &runs);
    if(runs <= 0)
        runs=DEFAULT_RUNS;*/
    runs=DEFAULT_RUNS;


    printf("Iteracoes? ");
    scanf("%d", &num_iter);
    if(num_iter <= 0)
        num_iter=DEFAULT_INTER;

    init_rand();

    // Preenche matriz de adjacencias
    grafo = init_dados(nome_fich, &vert, &arest);

    sol = malloc(sizeof(int)*vert);
    best = malloc(sizeof(int)*vert);
    if(sol == NULL || best == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }


    for(k=0; k<runs; k++)
    {

        // Gerar solucao inicial
        gera_sol_inicial(sol, vert);
        escreve_sol(sol, vert);
        printf("\n");


        switch (alg)
        {
        case 1:
            custo = trepa_colinas(sol, grafo, vert, arest, num_iter, viz);
            break;
        case 2:
            custo = recristalizacao_simulada(sol, grafo, vert, arest, num_iter, viz);
            break;
        }


            // Escreve resultados da repeticao k
            printf("\n\nRepeticao %d:", k);
            escreve_sol(sol, vert);
            printf("\nCusto final: %2d\n", custo);
            mbf += custo;
            if(k==0 || best_custo > custo)
            {
            best_custo = custo;
            substitui(best, sol, vert);
        }
    }
    // Escreve resultados globais

    printf("\n\nMBF: %f\n", mbf/k);
    printf("\nMelhor solucao encontrada");
    escreve_sol(best, vert);
    printf("\nCusto final: %2d\n", best_custo);

    free(grafo);
    free(sol);
    free(best);
    return 0;

}
