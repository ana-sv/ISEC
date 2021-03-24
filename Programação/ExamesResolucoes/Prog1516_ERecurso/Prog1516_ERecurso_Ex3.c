#include <stdio.h>
#include <stdlib.h>

typedef struct res no, *pno;
typedef struct pessoa jog, *pjog;

struct data {
    int dia, mes, ano;
};

struct res {
    int id_eq[2], golos[2], *m;
    struct data d;
    pno prox;
};

struct pessoa {
    char nome[50];
    int id;
    int idade;
};

typedef struct jogador_golos jogador_golos;

struct jogador_golos {
    int id_jogador;
    int n_golos_total;
    jog * p_jog;
};

void ex_3_a(no * lista, jog * vetor_jogadores, int num_jogadores) {
    int i, j;
    jogador_golos *vetor_golos;
    int num_marcadores;
    int flag = 1;
    jogador_golos melhor_jogador;

    vetor_golos = calloc(num_jogadores, sizeof (jogador_golos));

    num_marcadores = 0;
    while (lista != NULL) {
        for (i = 0; i < lista->golos[0] + lista->golos[1]; i++) {
            flag = 1;
            for (j = 0; j < num_marcadores; j++) {
                if (lista->m[i] == vetor_golos[j].id_jogador) {
                    (vetor_golos[j].n_golos_total)++;
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                vetor_golos[num_marcadores].id_jogador = lista->m[i];
                (vetor_golos[j].n_golos_total)++;
                num_marcadores++;
            }
        }
        lista = lista->prox;
    }

    for (i = 0; i < num_marcadores; j++) {
        for (j = 0; j < num_jogadores; j++) {
            if (vetor_golos[i].id_jogador == vetor_jogadores[j].id) {
                vetor_golos[i].p_jog = &vetor_jogadores[j];
            }
        }
    }

    melhor_jogador.n_golos_total = 0;
    for (i = 0; i < num_marcadores; i++) {
        if (vetor_golos[i].n_golos_total == melhor_jogador.n_golos_total) {
            melhor_jogador = vetor_golos[i];
            continue;
        }

        if (vetor_golos[i].n_golos_total > melhor_jogador.n_golos_total) {
            melhor_jogador = vetor_golos[i];
        }
    }

    printf("ID: %d\nNome: %s\n", melhor_jogador.id_jogador, melhor_jogador.p_jog->nome);
}




