// Ana Videira - junho 2019
// Exame Normal (2/7/2018) - exercicio 2

#include <stdio.h>
#include <stdlib.h>


typedef struct posicao no, *pno;

struct posicao{
    int index;
    int joga[2];
    pno cobra, escada;
    pno prox;
};

pno preencheLista(pno lista, int nIndex) {

    printf("inicio ");
    lista = malloc(sizeof (no)*5);
    pno prevNode = NULL;

    for (int i= 1; i <= nIndex; i++) {

        if (i == 1) {
            printf("1");
            lista->index = 1;
            lista->cobra = 0
            lista->escada = 0;
            lista->joga[0] = 1;
            lista->joga[1] = 4;
            lista->joga[2] = 1;
            lista->prox=lista;
        }

        if (i == 2) {
            printf("2");
            lista->index = 2;
            lista->cobra = 0;
            lista->escada = 1;
            lista->joga[0] = 0;
            lista->joga[1] = 0;
            lista->joga[2] = 0;
            lista->prox=lista;
        }

        if (i == 3) {
            printf("3");
            lista->index = 3;
            lista->cobra = 1;
            lista->escada = 0;
            lista->joga[0] = 7;
            lista->joga[1] = 0;
            lista->joga[2] = 0;
            lista->prox=lista;
        }


        if (i == 4) {
            printf("4");
            lista->index = 4;
            lista->cobra = 1;
            lista->escada = 0;
            lista->joga[0] = 0;
            lista->joga[1] = 0;
            lista->joga[2] = 0;
            lista->prox=lista;
        }

        if (i == 5) {
            printf("5");
            lista->index = 5;
            lista->cobra = 0;
            lista->escada = 1;
            lista->joga[0] = 0;
            lista->joga[1] = 0;
            lista->joga[2] = 0;
            lista->prox = NULL;
        }

        printf(" fim");
    }

    return lista;
}

void mostraTabuleiro(pno lista , int total){
    for(int i=0;  i<total; i++){
        printf("\n\n>>>>>Index : %d", lista->index);
        printf("\n jogadores: %d %d %d", lista->joga[0], lista->joga[1],lista->joga[2]);
        printf("\n escada: %d", lista->escada);
        printf("\n cobra: %d\n", lista->cobra);
        lista = lista->prox;
    }
}




int jogada( pno lista, int totPos, int idJog, int dado ){
    
    
    
    
    
    
}


int main(int argc, char** argv) {
    
    
    
    pno lista = NULL; 
    int total=5;
    lista = preencheLista(lista,total);
    mostraTabuleiro(lista,total); 
    
    
    jogada(lista,total,1,2);

    return (EXIT_SUCCESS);
}

