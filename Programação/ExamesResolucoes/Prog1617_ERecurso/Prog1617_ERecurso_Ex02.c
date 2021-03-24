#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct infoTurma turma, *pturma;
typedef struct aluno al, *pal;
typedef struct disciplina no, *pno;

struct infoTurma {
    char id[20];
    pal vAlunos;
    int nAlunos;
};

struct aluno {
    char nome[100];
    char id[20];
    pno vp[3];
};

struct disciplina {
    char nome[100];
    int conta;
    pno prox;
};

void ex_2_a(turma *vetor_turmas, int tam, no * disciplinas) {
    int i, j, k;

    for (i = 0; i < tam; i++) {
        for (j = 0; j < vetor_turmas->nAlunos; j++) {
            for (k = 0; k < 3; k++) {
                if (vetor_turmas[i].vAlunos[j].vp[k] == NULL)
                    break;
                (vetor_turmas[i].vAlunos[j].vp[k].conta)++;
            }
        }
    }
}

no * ex_2_b(char *id, turma *vetor_turmas, int tam, no *disciplinas) {
    int i, j, k, l;
    pal alunos_aux;
    pno disc_aux, disc_anterior;

    for (i = 0; i < tam; i++) {
        for (j = 0; j < vetor_turmas->nAlunos; j++) {
            if (strcmp(vetor_turmas[i].vAlunos[j].id, id) == 0)
                break;
        }
    }

    for (k = 0; k < 3; k++) {
        if (vetor_turmas[i].vAlunos[j].vp[k] == NULL)
            break;
        (vetor_turmas[i].vAlunos[j].vp[k]->conta)--;

        if (vetor_turmas[i].vAlunos[j].vp[k]->conta > 0)
            continue;

        if (vetor_turmas[i].vAlunos[j].vp[k] == disciplinas) {
            disciplinas = vetor_turmas[i].vAlunos[j].vp[k];
            free(vetor_turmas[i].vAlunos[j].vp[k]);
        } else {
            disc_aux = disciplinas;
            while (disc_aux != vetor_turmas[i].vAlunos[j].vp[k]) {
                disc_anterior = disc_aux;
                disc_aux = disc_aux->prox;
            }
            disc_anterior->prox = disc_aux->prox;
            free(disc_aux);
        }
    }

    alunos_aux = malloc(sizeof (al) * (vetor_turmas[i].nAlunos - 1));

    if (alunos_aux == NULL) {
        printf("Erro a alocar memoria\n");
        return disciplinas;
    }

    for (k = 0, l = 0; k < vetor_turmas[i].nAlunos; k++) {
        if (k == j)
            continue;
        
        alunos_aux[l] = vetor_turmas[i].vAlunos[k];
        l++;
    }
    
    free(vetor_turmas[i].vAlunos);
    vetor_turmas[i].vAlunos = alunos_aux;
    
    return disciplinas;
}

int main(int argc, char** argv) {

    return (EXIT_SUCCESS);
}

