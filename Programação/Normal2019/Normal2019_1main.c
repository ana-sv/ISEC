// Exame Normal 2019 - Exercicio 1 
// Ana Videira - junho 2020

// REVER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct atleta Atleta, *pAtleta;

struct atleta {
    char nome[100];
    int tAcumulado[10];
    int kmRapido;
};





int alinea_a(char *nome_ficheiro, int km) {

    FILE *f;
    char aux[20];
    int naux, tempo, nAtletas, primeiro, ultimo;

    f = fopen(nome_ficheiro, "rt");
    if (f == NULL) {
        printf("--> Erro ao abrir o ficheiro!");
        return -1;
    }

    fscanf(f, "Atletas: %d\n", &nAtletas);
    printf("---> ATLETAS %d \n", nAtletas);
 
}

pAtleta alinea_b( char *nome_ficheiro, int *tamVetor){
    FILE *f;
    pAtleta v;
    int nAtletas, km;
    int posicao, tempo, tempoMaior;
    char nome[20];
   
    f = fopen(nome_ficheiro,"rt");
    if ( f == NULL ){
        printf(" --> Erro ao abrir ficheiro!");
        return NULL;
    }
    
    fscanf(f, "Atletas: %d", &nAtletas);
    printf("---> ATLETAS %d \n", nAtletas);
    
    v = malloc(sizeof(Atleta)*nAtletas);
    *tamVetor= nAtletas;

    while (fscanf(f, "\nKm %d", &km) == 1) {

        printf("km : %d \n", km);

        while (fscanf(f, "\n%d. %s: %d", &posicao, nome, &tempo) == 3) {
            printf("NOME: %s ", nome);
            for (int i = 0; i < nAtletas; i++) {
                printf("posicao: %d ", posicao);

                if (strcmp(nome, v->nome[i]) == 1) {
                    v->tAcumulado[km - 1] = tempo;
                } else {
                    strcpy(v->nome[i], nome);
                }

            }

        }

    }
    //  for(i=0; i<nAtletas; i++){

    return v;

}



int main(int argc, char** argv) {
    
    //alinea_a("Corrida_10KM.txt", 10);
    
    int tam = 4;
    pAtleta v = NULL;
    
    v = alinea_b("Corrida_10KM.txt",&tam);
    
    

    return (EXIT_SUCCESS);
}

