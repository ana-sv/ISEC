// Trabalho Pratico Programacao - LEI-CE
// DEIS-ISEC 2019-2020
// Ana Rita Santos Videira | 2015012218 | a21250074@isec.pt 

#include "func.h"


void showInfo(psimulacao s) {
    ppessoa auxp;
    psimulacao auxs = s;

    printf("\n\n--------> Informacao: Salas & Pessoas > Iteracao %d", Iteracao);

    while (auxs != NULL) {
        printf("\n\n--> Sala: ID:%d  Capacidade:%d", auxs->l.id, auxs->l.capaciadade);

        auxp = auxs->listaP;
        while (auxp != NULL) {

            printf("\n[%d]> %s [%d]_________ %c", auxp->local, auxp->identificador, auxp->idade, auxp->estado);
            if (auxp->estado == DOENTE)
                printf("(%d)", auxp->dias);
            
            auxp = auxp->prox;
        }
        
        printf("\n [  %d  ] Pessoas ", auxs->nPessoas);
        auxs = auxs->prox;
    }
    
   
}



psimulacao addLocal(psimulacao s, local l) {

    psimulacao novo;
    
    novo = malloc(sizeof(simulacao));
    if (novo == NULL) return novo;

    novo->l.id = l.id;
    novo->l.capaciadade = l.capaciadade;
    novo->l.liga[0] = l.liga[0];
    novo->l.liga[1] = l.liga[1];
    novo->l.liga[2] = l.liga[2];
    novo->listaP = NULL;
    novo->nPessoas = 0;


    novo->prox = s; // adiciona no inicio
    s = novo;


    
    return s;
}


int addPessoa(psimulacao s, ppessoa p, int l) {
    ppessoa nova;

    if (p != NULL) {
        
        
        nova = malloc(sizeof (pessoa));
        if (nova == NULL) return 0;

        strcpy(nova->identificador, p->identificador);
        nova->idade = p->idade;
        nova->estado = p->estado;
        nova->dias = p->dias;
        nova->local = l;


        if (s->listaP == NULL) {
            s->listaP = nova;
            nova->prox = NULL;

        } else {

            nova->prox = s->listaP;
            s->listaP = nova;
          //  p = p->prox;
        }

        
    }
    return 1;

}


psimulacao simulatioSettings(psimulacao s, ppessoa p, plocal l, int *tam) {
    psimulacao aux = s;
    int c = 0;

    for (int i = 0; i<*tam; i++) {

        aux = addLocal(aux, l[i]);
        //printf("\n\nLOCAL %d cap: %d", s->l.id, s->l.capaciadade);

        c = 0;
        while (p != NULL && aux->l.capaciadade > aux->nPessoas) {

            if (addPessoa(aux, p, aux->l.id) == 1) {
                aux->nPessoas++;
                
                p = p->prox;

            }
        }
    }

    s = aux;   // porque adiciono sempre no inico

    showInfo(s);
    Config = 1;

    return s;
}



void showPessoas(ppessoa p){
    ppessoa aux = p;
    
    printf("\n-----> Pessoas: ");
    printf("\t\tIdentificador[idade] __ estado[dias se doente]");
    
    while(aux !=NULL){
        printf("\n-> %s[%d]_________ %c", aux->identificador, aux->idade, aux->estado);
        if(aux->estado==DOENTE)
            printf("(%d)",aux->dias);
         aux=aux->prox;
         
    }
    printf("\n\n");
}


ppessoa loadList( ppessoa p ) {
    FILE *f;
    ppessoa new;
    char ident[MAX_NAME], est;
    int id, d;

    //printf("\nLoad Vector..................");
    
    f = fopen(FILE_PESSOAS, "rt");
    if (f == NULL) { return NULL;   }
    
    while( fscanf(f,"%s %d %c ", ident, &id, &est)== 3 ){
        
        //valida id 
        if(id < 0){
            printf("-----> id invalido!");
            return NULL;
        }
          
        
        new = malloc(sizeof(pessoa));
        if(new==NULL){
            printf("--> Erro na alocacao de memoria");
            return NULL;
        }
         
        strcpy(new->identificador,ident);
        new->idade=id;
        new->estado=est;
        
        if(est==DOENTE && fscanf(f,"%d",&d )==1 )
            new->dias=d;
        else
            new->dias=0;
        
        new->local=SEM_LOCAL;
        
        new->prox=p;
        p=new;
        
        fscanf(f,"\n");
    }
    

    if( p != NULL )
        printf("\nVector successfully loaded!");
    
    return p;
}


void showLocais(local *v, int *tam) {

    printf("\n--> Locais: ");
    for (int i = 0; i<*tam; i++) {
        printf("\nId:%d ", v[i].id);
        printf(" Capacidade:%d", v[i].capaciadade);
        printf("\tLigacoes: %d %d %d", v[i].liga[0], v[i].liga[1], v[i].liga[2]);
    }
    printf("\n\n");
}


local * loadVetor(int *n) {

    FILE *f;
    local *v, *auxp, aux;
    int i = 0;

    //printf("\nLoading list................");
    
    f = fopen(FILE_LOCAIS, "rb");
    if (f == NULL) {
        return NULL;
    }
    

    while (fread(&aux, sizeof (local), 1, f) == 1) {


        if (i == 0) {
            v = malloc(sizeof (local));
        } else {
            auxp = realloc(v, sizeof (local)*(i + 1));
            v = auxp;
        }
        v[i] = aux;
        i++;
    }



    *n = i;
    fclose(f);

    if (v != NULL)
        printf("\nLinked list successfully loaded!");

    return v;

}


