  //Study Sessions - Test 1
// 13/4/2018

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//1///////////////////////////////////////////////////////////
/* Função que troca completamente os elementos de uma matriz*/
void troca (int *p1, int *p2){
    int aux = *p1;
    *p1 = *p2;
    *p2 = aux;
    return;
}
void prot(int *m, int nLin, int nCol){
    int *p1, *p2;
    p1 = m;
    p2 = m + nLin * nCol - 1;

    while (p1 < p2)
        troca( p1++ , p2-- );
    return;
}
