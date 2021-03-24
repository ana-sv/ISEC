// Ana Videira - junho 2019
// Exame Normal (2/7/2018) - exercicio 2

#include <stdio.h>
#include <stdlib.h>

int procuraOrd(int *tab, int tam, int valor) {

    do {

        if (tab[tam] == valor)
            return 1;
        
        procuraOrd(tab, tam - 1, valor);
        
    } while (tam != 0);

    return 0;
}

int main(int argc, char** argv) {

    int tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int tam = 10, valor = 7;
    if (procuraOrd(tab, tam, valor) == 1)
        printf("\nO valor %d encontra-se no vetor!\n", valor);
    else
        printf("\n0 valor %d nao se encontra no vetor!\n", valor);


    return (EXIT_SUCCESS);
}

