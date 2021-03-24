// Exame Normal 2020 - Pergunta 2
// Ana Videira - julho 2020

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct tipoA cliente, *pCliente;
typedef struct tipoB acesso, *pAcesso;
typedef struct {int h, m;} hora;

struct tipoA{
  int id;                 // Identificador único  
  int contador;           // Número de utilizações nesse dia 
  pAcesso lista;          // Ponteiro para a lista de acessos
  pCliente prox;          // Ponteiro para o próximo cliente
}; 

struct tipoB{
  hora in, out;   // Horas de entrada e saída
  pAcesso prox;
};

/*
 * Assumindo que a função é chamada com a seguinte linha, em que lista é um 
 * ponteiro para o início da estrutura dinâmica ilustrada em cima:  
 * f1(lista, 29, -1);
 * Que alteração é feita na estrutura dinâmica? */

void f1(pCliente p, int x, int y){
    pAcesso aux;
    
    while (p != NULL && p->id < x) { 
        p = p->prox;   // avança até encontrar o cliente com id < x 
                        // vai encontrar o cliente com id 29, o ultimom pela lista apresentada 
        
        if (p == NULL || p->contador == 0)
            return;
        
        aux = p->lista->prox;    //  aux representa o acesso seguinto na lista de acessos daquele cliente
        
        if (p->lista->in.h > y) {   // se a hora de entrada for > -1
            
            free(p->lista);    // elimina esse acesso 
            p->lista = aux;     // o segudo acesso anteriormente é agora o segundo 
            p->contador--;      // menos um acesso na lista de acessos do cliente 
            
        }

    }
    

}

// Assim , esta função elimina o primeiro acesso na lista de acessos do cliente com id = 29 