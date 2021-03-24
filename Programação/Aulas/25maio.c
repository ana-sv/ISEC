
#include <stdio.h>
#include <stdlib.h>

typedef struct info no, *pno;

struct info{
    char letra;
    pno prox;
};


pno cria_lista(char st[], int n){
    int i;
    pno p=NULL, novo;
	
    for(i=n-1; i>=0; i--){
        novo = malloc(sizeof(no));
        if(!novo) return p;
        novo->letra = st[i];
        novo->prox = p;
        p = novo;
    }
    return p;
}


void mostra_lista(pno p){
    while(p!=NULL){
        printf("%c\t", p->letra);
        p = p->prox;
    }
    printf("\n\n");
}


pno insere(pno lista, pno novo){
    pno aux=lista;
    
    if(lista == NULL)
        lista=novo;
    else{
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
    return lista;
  
}

int eVogal(char c){
    return c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
}

void divideListas(pno *lista, pno *a, pno *b){
    
    pno original=*lista, p1=NULL, p2=NULL, aux;
    
    while(original != NULL){
        aux = original;
        original = original->prox;
        aux->prox = NULL;
        if(eVogal(aux->letra) == 1)
            p1 = insere(p1, aux);
        else
            p2 = insere(p2, aux);       
    }
    
    *lista = NULL;
    *a = p1;
    *b = p2;
}


int main(){
    pno l1 = cria_lista("ABCDEFGHIUKL", 12), p1=NULL, p2=NULL;
    printf("Lista Original: \n");
    mostra_lista(l1);
    
    divideListas(&l1, &p1, &p2);

    printf("Vogais:\n");
    mostra_lista(p1);

    printf("Outros: \n");
    mostra_lista(p2);
    
    // Falta libertar listas
    return 0;
}



void transfere(pno *p1, pno *p2){
    pno aux;


    aux = *p1;
    *p1 = (*p1)->prox;
    aux->prox = *p2;
    *p2 = aux;
}

int mainPtr(){
    pno lista1, lista2;
	
    lista1 = cria_lista("ABC", 3);
    lista2 = cria_lista("DE", 2);
	
    printf("\nAntes:\nLista 1: \n");
    mostra_lista(lista1);
    printf("Lista 2: \n");
    mostra_lista(lista2);

    transfere(&lista1, &lista2);
	
    printf("Depois\nLista 1: \n");
    mostra_lista(lista1);
    printf("Lista 2: \n");
    mostra_lista(lista2);
    
    // Falta libertar listas
    return 0;
}