#include <stdio.h>
#include <stdlib.h>

typedef struct info no, *pno;

struct info {
    int num;
    pno dir, esq;
};

pno insere_no(pno tree, pno novo) {
    if (tree == NULL) {
        tree = novo;
    } else if (tree->num > novo->num) {
        tree->esq = insere_no(tree->esq, novo);
    } else {
        tree->dir = insere_no(tree->dir, novo);
    }

    return tree;
}

pno adiciona_no(pno tree, int val) {
    pno novo;

    novo = malloc(sizeof (no));
    if (novo == NULL) {
        printf("Erro na alocacao de memoria\n");
        return tree;
    }

    novo->num = val;
    novo->dir = novo->esq = NULL;

    return insere_no(tree, novo);
}

/* travessia in-order */
void mostra_ordem(pno tree) {
    if (tree == NULL) {
        return;
    } else {
        mostra_ordem(tree->esq);
        printf("%d\t", tree->num);
        mostra_ordem(tree->dir);
    }
}

/* Ex. 2

Uma arvore binaria e constituida por nos do tipo no.

Escreva uma funcao recursiva em C que receba um ponteiro para a raiz da arvore e devolva o
numero de folhas que ela tem. */

int conta_folhas(pno tree) {
    if (tree == NULL) {
        return 0;
    } else if (tree->esq == NULL && tree->dir == NULL) {
        return 1;
    } else {
        return conta_folhas(tree->esq) + conta_folhas(tree->dir);
    }
}

int main(int argc, char** argv) {
    pno tree = NULL;
    int conta = 0;

    tree = adiciona_no(tree, 9);
    adiciona_no(tree, 4);
    adiciona_no(tree, 15);
    adiciona_no(tree, 6);
    adiciona_no(tree, 12);
    adiciona_no(tree, 17);
    adiciona_no(tree, 2);

    //mostra_ordem(tree);

    conta = conta_folhas(tree);

    printf("Numero de folhas da arvore: %d\n", conta);

    return (EXIT_SUCCESS);
}
