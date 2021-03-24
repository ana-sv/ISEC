/* 
 * File:   jogoGaloMain.c
 * Author: Ana Rita
 *
 * Created on 2 de março de 2020, 20:59
 */

#include <stdio.h>
#include <stdlib.h>
#define N 3 //dimensao do tabuleiro

void escreve_resultado(int ganhou)
{
	if(ganhou == 0)
		printf("\nEmpate\n\n");
	else
		printf("\nGanhou o jogador %d\n\n", ganhou);
}

int diag(char t[][N]) {

    int i, j;

    // diagonal direita
    if (t[0][0] != '_') {
        for (i = 0, j = 0; i < N - 1 && j < N - 1 && t[i][j] == t[i + 1][j + 1]; i++, j++);
        if (i == N - 1 && j == N - 1)
            return 1;
    }

    // diagonal esquerda 
    if (t[0][N-1] != '_') {
        for (i = 0, j = N - 1; i < N - 1 && j>0 && t[i][j] == t[i + 1][j - 1]; i++, j--);
        if (i == N - 1 && j==0)
            return 1;
    }

    return 0;
}


int coluna(char t[][N])
{
        int i, j;

    for (j = 0; j < N; j++)
        if (t[0][j] != '_') {
            for (i = 0; i < N - 1 && t[i][j] == t[i+1][j]; i++);
            if (i == N - 1)
                return 1; // se fez coluna
        }
    return 0;
}


int linha(char t[][N]) {
    int i, j;

    for (i = 0; i < N; i++)
        if (t[i][0] != '_') {
            for (j = 0; j < N - 1 && t[i][j] == t[i][j + 1]; j++);
            if (j == N - 1)
                return 1; // se fez linha
        }
    return 0;
}


void escolhe_jogada(char t[][N], int jogador) {
    int pos;

    printf("\nE' a vez do jogador %d\n", jogador);
    do {
        printf("Posicao: ");
        scanf(" %d", &pos);
    } while (pos < 1 || pos > N * N || t[(pos - 1) / N][(pos - 1) % N] != '_');

    if (jogador == 1)
        t[(pos - 1) / N][(pos - 1) % N] = 'X';
    else
        t[(pos - 1) / N][(pos - 1) % N] = 'O';
}


void escreve_tab(char t[][N])
{
	int i, j;

	printf("\n\n");
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
			printf(" %c ", t[i][j]);
		putchar('\n');
	}
}

void inicializa_tab(char t[][N]){
    int i ,j;
    
    for(i=0; i<N; i++)
        for(j=0; j<N; j++)   
            t[i][j]= '_';

}


int main(int argc, char** argv) {

    char tab[N][N];
    int joga, n_jogadas, ganhou;

    joga = 1;
    n_jogadas = 0;
    ganhou = 0;

    inicializa_tab(tab);
    do {
        escreve_tab(tab);
        escolhe_jogada(tab, joga);
        n_jogadas++;

        if (linha(tab) == 1 || coluna(tab) == 1 || diag(tab) == 1)
            ganhou = joga;
        else
            joga = joga % 2 + 1;
    } while (ganhou == 0 && n_jogadas < N * N);

    escreve_tab(tab);
    escreve_resultado(ganhou);


    return (EXIT_SUCCESS);
}

