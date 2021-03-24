//Study Sessions - Test 2
// 18/5/2018

// Matéria a avaliar:
// *Estruturas
// *Vetores de estruturas
// *Manipulação simples de ficheiros de texto ou binários (abertura, leitura/escrita, fecho) 


//By Carol

// exercicio
// imprimir um intervalo de valores armazenados numa estrutura 
// dada uma função que recebia o nome do ficheiro e o preço max e minimo 

// 3 escolhas multiplas
// como aceder a uma estrutura  
// escrever num ficheiro binário toda a informação de cada pessoa

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
//G02ex04

// (a) estrutura auxiliar para armazenar o tempo
struct tempo{
    int h;
    int m;
};

// (b) estrutura para armazenar a info sobre voos
#define TAM 50
struct voo{
    int numero;
    char companhia[TAM];
    char destino[TAM];
    struct tempo in;
};

// (c) mostrar conteudo da estrutura voo
void conteudo(struct voo v)
{
    printf("Nr de voo: %d\n", v.numero);
    printf("Companhia: %s\n", v.companhia);
    printf("Destino: %s\n", v.destino);
    printf("Hora de partida: %d:%d\n", v.in.h, v.in.m);
}

//testar a alinea c 
/*int main (int argc, char *argv[])
{
    struct voo teste = {111, "TAP", "Caraibas", {15,45}};

    conteudo(teste);
}*/

/*
// (d) inserir info de um novo voo ??
void novainformacao(struct voo* p)
{
    printf("\nNr de voo: ");
    scanf("%d", &(p->numero));

    getchar(); //faz com que a funçao gets a seguir nao conte o enter que fazemos depois do Numero como resposta para Companhia
    printf("Companhia: ");
    gets(p->v.companhia);

    printf("Destino: ");
    gets(p->destino);

    printf("Hora de partida (hh:mm): ");
    scanf("%d:%d", &(p->in.h), &(p->in.m));
}

// testar a alinea (d)
/*int main (int argc, char *argv[])
{
    struct voo teste = {111, "TAP", "Londres", {15,45}};

    novainformacao(&teste);
    conteudo(teste);
}*/

/*
//G03ex02
// função que mostre o conteudo de um ficheiro. 
// O nome do ficheiro é passado como argumento
 
void mostrac(char *nomeFicheiro){
    FILE *f;
    int c; 
    
    f=fopen(nomeFicheiro,"rt");
    
    if(f==NULL){
        printf("\nErro no ficheiro de texto %s\n", nomeFicheiro );
        return;
    }
    
    // conteudo do ficehiro txt aparece letra a letra
    c=fgetc(f); // fgetc: função que obtem o proximo caracter
    
    while(c!=EOF){
        putchar(c);
        c=fgetc(f);
    }
    fclose(f);
    
}

// testar função G03ex02
int main (int argc, char *argv[])
{
    mostrac("Aula1.txt");
    return 0;
}*/

//G03ex09
//criar um novo ficheiro

#define MAX_PROVAS 6

void addnota(char nomeFicheiro){
    FILE *f, *fnovo;
    char *novoFicheiro= "notaFinal.txt";
    int nalunos, nprovas, peso[MAX_PROVAS];
    int i, somaPesos, num, nota, j;
    float somaNotas;
    
    f=fopen(nomeFicheiro, "rt");
    
    if(f==NULL){
        printf("Erro ao aobrir o ficheiro %s", nomeFicheiro);
        return;
    }
    
    

}


// Testar G03ex09
int main(int argc, char *argv[])
{
    addnota("notas.txt");
    return 0;
}

