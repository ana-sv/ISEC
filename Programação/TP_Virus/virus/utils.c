// Trabalho Pratico Programacao - LEI-CE
// DEIS-ISEC 2019-2020
// Ana Rita Santos Videira | 2015012218 | a21250074@isec.pt 



#include "func.h"



void exitProgram(ppessoa p, local *l ){

    //libertar memoria l 
    free(l);
    
    //libertar memoria de p
    ppessoa aux;
    while( p != NULL){
        aux=p;
        p=p->prox;
        free(aux);
    }
     
    printf("\n\n\n\n\nAPLICACAO ENCERRADA\n\n\n");
}


int printSimulationMenu(){
    int o=0;
    printf( "\n---------------------- Simulacao ----------------------\n"
            "\n(1) Avanca 1 iteracao / 1 dia"
            "\n(2) Retroceder iteracao"
            "\n(3) Mostra Salas e Pessoas"
            "\n(4) Mostra Estatisticas"
            "\n(5) Adiciona Doente "
            "\n(6) Tranfere Pessoa"
            "\n(7) Termina&Guarda Simulacao"
            "\n--------------------------------------------------------\n");
    scanf("%d" ,&o);
    return o;
    
}


int printMenu(){
    int o=0;
    printf("\n\n---------- Simulacao da Propagacao do Virus  ----------\n"
            "\n(1) Mostra Locais"
            "\n(2) Mostra Pessoas"
            "\n(3) Configuracao da Populacao Inicial"
            "\n(4) Iniciar Simulacao"
            "\n--------------------------------------------------------\n");
    scanf("%d" ,&o);
    return o;
    
}


void initRandom(){
    srand(time(NULL));
}

int intUniformRnd(int a, int b){
    return a + rand()%(b-a+1);
}

int probEvento(float prob){
    return prob > ((float)rand()/RAND_MAX);
}


