#include <stdio.h>
#include <stdlib.h>

typedef struct valor no, *pno;

struct valor {
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

Uma arvore binaria constituida por nos do tipo no esta ordenada de forma crescente
pelos valores do campo num. Pode assumir que nao existem valores repetidos na arvore.

Escreva uma funcao recursiva em C que escreva na consola todos os valores armazenados em
folhas da arvore. Os valroes devem ser escritos por ordem decrescente. */

void mostra_folhas_dec(pno tree) {
    if (tree == NULL) {
        return;
    }
    if (tree->esq == NULL && tree->dir == NULL) {
        printf("%d\t", tree->num);
    } else {
        mostra_folhas_dec(tree->dir);
        mostra_folhas_dec(tree->esq);
    }
}

int main(int argc, char** argv) {
    pno tree = NULL;

    tree = adiciona_no(tree, 9);
    adiciona_no(tree, 4);
    adiciona_no(tree, 15);
    adiciona_no(tree, 6);
    adiciona_no(tree, 12);
    adiciona_no(tree, 17);
    adiciona_no(tree, 2);

    //mostra_ordem(tree);

    mostra_folhas_dec(tree);

    return (EXIT_SUCCESS);
}
