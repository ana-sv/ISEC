// Ana Videira - a21250074
// 2018-2019
// exemplos dos ppt das aulas

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define MAX 100

// Estrutura dados

struct dados {
    char nome[100];
    char nconta[15];
    int montante;
};

//typedef struct dados cliente;
typedef struct dados cliente;

struct data {
    int dia, mes, ano;
};

//Função que escreve a informação de um cliente passado como argumento
// A estrutura é passada por valor
void escreve_info(cliente a) {

    printf("\nNome: %s\nNº conta: %s\tSaldo: %d\n",
            a.nome, a.nconta, a.montante);
}


//Função que inicializa uma estrutura do tipo cliente e devolve-a já preenchida
cliente obtem_info() {
    cliente t;
    printf("Nome: ");
    scanf(" %99[^\n]", t.nome);
    printf("Nº conta: ");
    scanf(" %14s", t.nconta);
    printf("Saldo: ");
    scanf("%d", &(t.montante));
    return t;
}

// Transfere um determinado montante entre 2 clientes
int transfere(cliente *or, cliente *dest, int valor) {
    if (or->montante < valor)
        return 0;
    else {
        or->montante -= valor;
        dest->montante += valor;
        return 1;
    }
}


// Mostar informação completa sobre todos os clientes
void escreve_todos(cliente tab[], int n) {
    int i;
    for (i = 0; i < n; i++)
        escreve_info(tab[i]);
}

// Procurar e mostrar informação do cliente com o saldo mais elevado
void procura_mais_rico(cliente tab[], int n) {
    int i, index = 0;
    if (n == 0) {
        printf("Sem Clientes\n");
        return;
    }
    for (i = 1; i < n; i++)
        if (tab[i].montante > tab[index].montante)
            index = i;
    printf("Cliente com saldo mais elevado:\n");
    escreve_info(tab[index]);
}


// Adicionar um cliente (inserção efetuada no final)
void adiciona_cliente(cliente tab[], int* n) {
    if (*n >= MAX)
        printf("Tabela completa\n");
    else {
        tab[*n] = obtem_info();
        (*n)++;
    }
}

// Eliminar um cliente (identificação feita pelo nº de conta)
void elimina_cliente(cliente tab[], int *n) {
    char st[15];
    int i;
    printf("\nNº de conta do cliente a eliminar: ");
    scanf(" %14s", st);
    for (i = 0; i<*n && strcmp(st, tab[i].nconta) != 0; i++)
        ;
    if (i == *n)
        printf("Cliente não existe\n");
    else {
        tab[i] = tab[*n - 1];
        (*n)--;
    }
}

// MENU

int menu() {
    int i;
    puts("\n\n");
    puts("1 - Adiciona Cliente");
    puts("2 - Elimina Cliente");
    puts("3 - Lista Clientes");
    puts("4 - Mostra Mais Rico");
    puts("5 - Terminar");
    puts("Escolha uma opcao: ");
    do {
        scanf(" %d", &i);
    } while (i < 1 || i > 5);
    return i;
}

int main(int argc, char** argv) {

    //Inicialização na Declaração
    struct dados m = {"Ana Silva", "N1234", 500000};
    struct dados n = {"AA", "X10"};
    struct dados q = {.montante = 25, .nome = "AA"};

    struct dados a;
    cliente b;




    cliente banco[MAX]; // Array de estruturas
    int i, total = 0;
    do {
        i = menu();
        switch (i) {
            case 1: adiciona_cliente(banco, &total);
                break;
            case 2: elimina_cliente(banco, &total);
                break;
            case 3: escreve_todos(banco, total);
                break;
            case 4: procura_mais_rico(banco, total);
                break;
        }
    } while (i != 5);


    return (EXIT_SUCCESS);
}

