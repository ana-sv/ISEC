#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 50
#define TAM_GRUPO 5
typedef struct grupo grupo;
typedef struct atleta atleta;

struct atleta {
    char nome[TAM], clube[TAM];
};

struct grupo {

    struct {
        int h, m;
    } hora;
    char estilo[TAM];
    atleta a[TAM_GRUPO];
};

void ex_2(char *nomefich, char *clube) {
    FILE *f = fopen(nomefich, "rb");
    grupo *vetor_grupos;
    long tamanho_fich;
    int num_grupos;
    int i, j;

    if (!f) {
        fprintf(stderr, "Erro na abertura do ficheiro: %s", nomefich);
        return;
    }

    fseek(f, 0, SEEK_END);
    tamanho_fich = ftell(f);
    fseek(f, 0, SEEK_SET);

    num_grupos = (int) tamanho_fich / sizeof (grupo);

    vetor_grupos = malloc(sizeof (grupo) * num_grupos);
    fread(vetor_grupos, sizeof (grupo), num_grupos, f);

    printf("Atletas do %s:\n", clube);

    for (i = 0; i < num_grupos; i++) {
        for (j = 0; j < TAM_GRUPO; j++) {
            if (strcmp(vetor_grupos[i].a[j].clube, clube) == 0) {
                printf("%02d:%2d, %s %s pista %d\n",
                        vetor_grupos[i].hora.h,
                        vetor_grupos[i].hora.m,
                        vetor_grupos[i].estilo,
                        vetor_grupos[i].a[j].nome,
                        j + 1);
            }
        }
    }
    free(vetor_grupos);
    fclose(f);
}


