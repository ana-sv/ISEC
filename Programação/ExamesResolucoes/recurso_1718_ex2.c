#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa no, *pno;

struct pessoa {
    char nome[100];
    int num;
    pno dir, esq;
};

pno insere_no(pno aluno, pno novo) {
    if (aluno == NULL) {
        aluno = novo;
    } else if (strcmp(novo->nome, aluno->nome) > 0) {
        aluno->dir = insere_no(aluno->dir, novo);
    } else {
        aluno->esq = insere_no(aluno->esq, novo);
    }

    return aluno;
}

pno adiciona_no(pno aluno, char *n, int val) {
    pno novo;

    novo = malloc(sizeof (no));
    if (novo == NULL) {
        printf("Erro na alocacao de memoria\n");
        return aluno;
    }

    strcpy(novo->nome, n);
    novo->num = val;
    novo->dir = novo->esq = NULL;

    return insere_no(aluno, novo);
}

/* travessia in-order */
void mostra_ordem(pno raiz) {
    if (raiz == NULL) {
        return;
    } else {
        mostra_ordem(raiz->esq);
        printf("%s\t", raiz->nome);
        mostra_ordem(raiz->dir);
    }
}

/* Ex. 2

Uma arvore binaria e constituida por nos do tipo no.

A arvore binaria esta ordenada alfabeticamente pelo nome dos alunos. Pode assumir que os
nomes sao unicos. Escreva uma funcao recursiva em C que receba um ponteiro para a raiz e o
nome de um aluno e devolva o seu numero. Caso o aluno nao exista deve devolver -1. */

int encontraNum(pno raiz, char* nome) {
    if (raiz == NULL) {
        return -1;
    }

    if (strcmp(raiz->nome, nome) == 0) {
        return raiz->num;
    }

    if (strcmp(raiz->nome, nome) > 0) {
        return encontraNum(raiz->esq, nome);
    } else {
        return encontraNum(raiz->dir, nome);
    }

    return -1;
}

int main(int argc, char** argv) {
    pno aluno = NULL;
    int num;
    char n[100];

    aluno = adiciona_no(aluno, "Pedro", 5);
    adiciona_no(aluno, "Joao", 2);
    adiciona_no(aluno, "Patricia", 6);
    adiciona_no(aluno, "Joana", 4);
    adiciona_no(aluno, "Ricardo", 9);

    printf("Introduza o nome a pesquisar: ");
    scanf(" %s", n);

    //mostra_ordem(aluno);

    num = encontraNum(aluno, n);

    if (num == -1) {
        printf("\nO aluno nao existe\n");
    } else {
        printf("\nO numero do aluno e: %d\n", num);
    }

    return (EXIT_SUCCESS);
}
