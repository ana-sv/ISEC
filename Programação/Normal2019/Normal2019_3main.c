// Exame Normal 2019 - Exercicio 3
// Ana Videira - junho 2020

// NÃO CORRIGIDO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
typedef struct divisao di, *pdiv;
typedef struct porta no, *pno;

typedef struct pessoa pes ,*ppes;

struct divisao {
    int id;
    char nome[100];
    int n_pessoas;
    pno lista;
};

struct porta {
    int id;
    pno prox;
};

struct pessoa {
    char nome[100];

    struct {
        int d, m, a;
    } nasc;
    pdiv local;
};






int alinea_a (pdiv v, int tamv , ppes pessoas, int tampess ){
    
    int contador, contaPessoas;
    
    for(int i=0; i<tamv; i++){
        
        for( int j=0; j<tampess; j++){
            
            contaPessoas=0;
            if(v[i].id == pessoas[j].local->id)
                contaPessoas++;

        }
        if (contaPessoas != v[i].n_pessoas){
            contador++;
            v[i].n_pessoas = contaPessoas;      
        }
    
    
    }


    return contador;
}


pdiv elimina(pdiv d, int *totD, int id, struct pessoa* hab, int totP){
    
    
    
    
    


}

int main(int argc, char** argv) {
    
    pdiv v;
    ppes pessoas;
    
    
    alinea_a(v,4,pessoas,5);
    
  
    
    

    return (EXIT_SUCCESS);
}*/



typedef struct p objeto, *pobjeto;

struct p{
   char nome[100];
   int id;
   pobjeto prox; 
};

pobjeto troca(pobjeto p) {

    pobjeto auxc = p;
    pobjeto aux = p;
    objeto copia;
    pobjeto  anterior = NULL;
    int count;

    count=0; 
    while (aux != NULL) {     
        count++;
        
        anterior = aux;
        aux = aux->prox;
    }
    
    if(count > 3 && p.id > 50){
        return;
    }
    else{
        anterior = aux; 
        aux = aux->prox; // está no segundo elemento
        
        
        copia.id=aux->id;
        strcpy(copia.nome,aux->nome);
        copia.prox = aux->prox;
        
        
    }

}


int main(int argc, char** argv) {
    

  
    
    

    return (EXIT_SUCCESS);
}

/*  Pergunta 4
int consecutivosIguais(int *tab, int tam) {
    if (tam <= 1)
        return 0;
    else if (*tab == )
        return 0;
    else
        return consecutivosIguais( ,  );
}*/

/*

typedef struct trajeto dados;
struct trajeto{
    char origem[200];      // Origem (1 palavra apenas)
    char destino[200];    // Destino (1 palavra apenas)
    int minutos;         // Número de minutos que demora a fazer a ligação
};

// considerei nomeB como nome do ficheiro binário

dados* criaVetor(char* nomeB, char* nomeF, int *total) {
    FILE *f, *ftxt;
    dados *d, *aux;
    char local[20];
    int i = 0;

    f = fopen(nomeB, "rb");
    if (f == NULL) {
        return NULL;
    }
    ftxt = fopen(nomeF, "rt");
    if (ftxt == NULL) {
        return NULL;
    }


    while (fread(&aux, sizeof (dados), 1, f) == 1) {

        while(fscanf("%s\n", local) == 1) {
            
            if (strcmp(local, aux->origem) != 1)

                if (i == 0) {
                    d = malloc(sizeof (dados));
                } else {
                    aux = realloc(d, sizeof (dados)*(i + 1));
                    d = aux;
                }
            d[i] = aux;
            i++;
        }

    }


    *total = i;
    
    fclose(ftxt);
    fclose(f);
    
    if (d = NULL) {
        return NULL;
    }


    return d;

} */