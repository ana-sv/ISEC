#include <stdio.h>
#include <stdlib.h>

#define N 5

/* Ex. 2

Escreva uma função recursiva em C que verifique se um determinado valor se encontra num
vetor ordenado de inteiros.

Recebe como parâmetros o vetor, a sua dimensão e o valor a pesquisar. Devolve 1 se o valor
existir, ou 0, caso contrário. */

int procuraOrd(int *tab, int tam, int valor) {
    if (tam == 0) {
        return 0;
    }

    if (tab[tam - 1] == valor) {
        return 1;
    } else {
        procuraOrd(tab, tam - 1, valor);
    }
}

int main(int argc, char** argv) {
    int vec[N] = {2, 7, 9, 13, 20};
    int val;

    printf("Valor a pesquisar: ");
    scanf(" %d", &val);

    if (procuraOrd(vec, N, val) == 1) {
        printf("\nO valor existe no vector\n");
    } else {
        printf("\nO valor nao existe no vector\n");
    }

    return (EXIT_SUCCESS);
}

