// Exame Normal 2020 - Pergunta 4
// Ana Videira - julho 2020

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * A função recursiva consecutivosIguais( ) recebe um vetor de inteiros
 *  já completamente preenchido e verifica se existem 2 valores 
 * consecutivos que sejam iguais. A função tem 2 parâmetros: 
 * o endereço do início do vetor e o número de elementos que ele contém.
 * Devolve 1 se existirem 2 valores consecutivos iguais, ou 0, caso 
 * contrário. Complete o código, arrastando as caixas para os espaços 
 * vazios assinalados. Tenha em consideração que as cores devem 
 * corresponder.
 */

int consecutivosIguais(int *tab, int tam){
    if(tam <= [1])
        return 0;
    else if(*tab == [tab[1]]) 
        return [1];
    else
        [return] consecutivosIguais([&tab[1]], [tam‑1]);
}

