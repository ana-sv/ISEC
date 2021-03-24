#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam 1024

typedef struct duracaoDados {
    int horas, minutos;
} duracao;

typedef struct musicaDados {
    char nome[200], autor[200];
    duracao d;
    int ano;
} musica;

void elimina_musica(char *nomefich) {
    FILE *f = fopen(nomefich, "rt");
    FILE *g;
    char linha[tam];
    char nome_lido[tam];
    int flag = 1;
    char *musica = "By The Way";

    if (!f) {
        fprintf(stderr, "Erro na abertura do ficheiro: %s", nomefich);
        return;
    }

    g = fopen("newfile", "wt");

    if (!g) {
        fclose(f);
        fprintf(stderr, "Erro na criacao do ficheiro");
        return;
    }

    while (fgets(linha, tam, f) != NULL) {
        sscanf(linha, "%[^;]", nome_lido);
        if (strcmp(nome_lido, musica) != 0) {
            flag = 0;
            fputs(linha, g);
            continue;
        }
    }

    fclose(f);
    fclose(g);

    if (flag == 0) {
        remove(nomefich);
        rename("newfile", nomefich);
    } else {
        remove("newfile");
    }
}

musica* funcB(char* fichTXT, char* fichBIN, int* total) {
    FILE *f_txt = fopen(fichTXT, "rt");
    FILE *f_bin;
    musica *p_aux, *vetor_full, *vetor_return;
    musica m_aux;
    char linha[tam];
    int total_musicas = 0;

    *total = 0;

    if (!f_txt) {
        fprintf(stderr, "Erro na abertura do ficheiro: %s", fichTXT);
        return NULL;
    }

    f_bin = fopen(fichBIN, "wb");

    if (f_bin == NULL) {
        fclose(f_txt);
        fprintf(stderr, "Erro na abertura do ficheiro: %s", fichBIN);
        return NULL;
    }

    while (fgets(linha, tam, f_txt) != NULL) {

        if (sscanf(linha, " %199[^;]; %199[^;]; %d:%d; %d",
                m_aux.nome,
                m_aux.autor,
                &m_aux.d.horas,
                &m_aux.d.minutos,
                &m_aux.ano) != 5) {

            fclose(f_txt);
            free(vetor_full);
            free(vetor_return);
            return NULL;
        }

        p_aux = realloc(vetor_full, sizeof (musica)*(total_musicas + 1));
        if (p_aux == NULL) {
            fclose(f_txt);
            free(vetor_full);
            free(vetor_return);
            return NULL;
        }
        vetor_full[total_musicas] = m_aux;
        total_musicas++;

        if (m_aux.ano > 2000) {
            continue;
        }

        p_aux = realloc(vetor_return, sizeof (musica) * (*total + 1));
        if (p_aux == NULL) {
            fclose(f_txt);
            free(vetor_full);
            free(vetor_return);
            return NULL;
        }
        vetor_return[*total] = m_aux;
        (*total)++;
    }

    fclose(f_txt);

    f_bin = fopen(fichBIN, "wb");

    if (f_bin == NULL) {
        fclose(f_txt);
        fprintf(stderr, "Erro na abertura do ficheiro: %s", fichBIN);
        return NULL;
    }

    if (fwide(vetor_full, sizeof (musica), total_musicas, f_bin) != total_musicas) {
        free(vetor_full);
        free(vetor_return);
        return NULL;
    }

    fclose(f_bin);
    free(vetor_full);

    return vetor_return;
}

void mostra(char *nomefich) {
    FILE *f_bin = fopen(nomefich, "rb");
    int flag = 1;
    int i, j, n_musicas;
    musica * vetor_musicas;
    long file_size;

    if (f_bin == NULL) {
        fprintf(stderr, "Erro na abertura do ficheiro: %s", nomefich);
        return NULL;
    }

    fseek(f_bin, 0, SEEK_END);
    file_size = ftell(f_bin);
    fseek(f_bin, 0, SEEK_SET);

    n_musicas = (int) (file_size / sizeof (musica));

    vetor_musicas = malloc(sizeof (musica) * n_musicas);
    fread(vetor_musicas, sizeof (musica), n_musicas, f_bin);

    fclose(f_bin);

    for (i = 0; i < n_musicas; i++) {
        flag = 1;
        for (j = 0; j < n_musicas; j++) {
            if (i == j)
                continue;
            if (strcmp(vetor_musicas[i].autor, vetor_musicas[j].autor) == 0) {
                flag = 0;
                break;
            }
        }

        if (flag)
            puts(vetor_musicas[i].autor);
    }
}

int main() {
    char *file = "musicas.txt";
    elimina_musica(file);

    return (EXIT_SUCCESS);
}


