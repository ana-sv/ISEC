// Exame Normal 2020 - Pergunta 1 - NAO TESTADA
// Ana Videira - julho 2020

/*
 * Escreva a função pobjeto troca(pobjeto p);
 * 
 * Esta função recebe o endereço do primeiro elemento de uma lista ligada simples, 
 * constituída por nós do tipo objeto. Se a lista tiver menos de três elementos
 * ou se o id armazenado no primeiro nó for superior a 50, a função não faz 
 * nenhuma alteração. Caso contrário, troca o segundo com o terceiro elemento: 
 * o segundo passa a ser o terceiro e o terceiro passa a ser o segundo. Devolve
 * o endereço do primeiro elemento da lista depois da alteração.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct p objeto, *pobjeto;

struct p{
   char nome[100];
   int id;
   pobjeto prox; 
};


troca(pobjeto p){
    
    pobjeto aux = p; 
    pobjeto anterior, atual, seguinte;
    int count=0; 
    
    
    while(aux!= NULL){
        count++;
        
        if(count==1 && aux->id>50)
            return p;
       
        aux=aux->prox;
    }
    
    
    if(count>3){
        return p;
    }
    
    
    anterior = NULL;    
    while(aux!=NULL){ 
        count++;
        atual = aux;
        seguinte = aux->prox;
        
        if (count == 2 ){
            atual->prox = seguinte->prox;
            seguinte->prox = atual;
            anterior->prox = seguinte;
            return p;
        }
            

        anterior = aux;
        aux=aux->prox;
    }
    
    

}

