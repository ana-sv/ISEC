#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 50

void ex_1(char *nomefich, char *sigla) {
    FILE *f_orig;
    FILE *f_final;
    char linha[TAM];
    char sigla_lida[TAM];
    char nomefich_final[TAM];

    f_orig = fopen(nomefich, "rt");

    if (!f_orig) {
        fprintf(f_orig, "Erro na abertura do ficheiro: %s", nomefich);
        return;
    }

    strcpy(nomefich_final, sigla);
    strcat(nomefich_final, ".txt");

    f_final = fopen(nomefich_final, "wt");

    if (!f_final) {
        fclose(f_orig);
        fprintf(f_orig, "Erro na abertura do ficheiro: %s", nomefich_final);
        return;
    }

    while (fgets(linha, TAM, f_orig) != NULL) {
        sscanf(linha, " %*d %s", sigla_lida);

        if (strcmp(sigla, sigla_lida) == 0)
            fputs(linha, f_final);
    }
    
    fclose(f_orig);
    fclose(f_final);
}

int main(int argc, char** argv) {
    char nome[TAM];
    char *nomefich="ginastas.txt";
    
    printf(":: ");
    scanf("%s", nome);
    
    ex_1(nomefich, nome);
    return (EXIT_SUCCESS);
}

