#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define DEFAULT_RUNS 10
#define DEFAULT_INTER 10

//para recristalização simulada
#define TMAX 100
#define TMIN 5


int* init_dados(char *nome, int *v, int *are);
void gera_sol_inicial(int *sol, int v);

void escreve_sol(int *sol, int vert);
void substitui(int a[], int b[], int n);
void init_rand();
int random_l_h(int min, int max);
float rand_01();

int txtOptions();
int algOptions();
