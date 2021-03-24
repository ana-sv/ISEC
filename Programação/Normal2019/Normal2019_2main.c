// Exame Normal 2019 - Exercicio 2
// Ana Videira - junho 2020

#include <stdio.h>
#include <stdlib.h>

//Arvore binária ordenada de forma crescente 
// Quer-se mostrar a arvore na forma decrescente

// REVER


typedef struct valor no, *pno;

struct valor{
    int num;
    pno dir, esq;
};


pno insere_no(pno p, pno novo){
    if(p==NULL)
        p = novo;
    else if(p->num > novo->num)    // ALTERANDO AQUI ALTERA A ORDEM
        p->esq = insere_no(p->esq, novo);
    else 
        p->dir = insere_no(p->dir,novo);
    return p;
}

pno adiciona_no(pno p, int val) {
    pno novo;
    novo = malloc(sizeof (no));
    if (novo == NULL)
        return p;
    novo->num = val;
    novo->dir = novo->esq = NULL;

    return insere_no(p, novo);


}

void mostra(pno tree) {
    if (tree == NULL)
        return;
    else {
        mostra(tree->esq);
        printf("%d\t", tree->num);
        mostra(tree->dir);
    }

}




int main(int argc, char** argv) {
    pno tree = NULL; //arvore binária vazia;

    tree = adiciona_no(tree, 0);
    tree = adiciona_no(tree, 1);
    tree = adiciona_no(tree, 2);
    tree = adiciona_no(tree, 3);
    tree = adiciona_no(tree, 4);
    tree = adiciona_no(tree, 5);
    mostra(tree);
    printf("\n\n");


    return (EXIT_SUCCESS);
}

