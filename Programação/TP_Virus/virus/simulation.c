// Trabalho Pratico Programacao - LEI-CE
// DEIS-ISEC 2019-2020
// Ana Rita Santos Videira | 2015012218 | a21250074@isec.pt

#include "func.h"
#include <string.h>

psimulacao deletePerson(psimulacao s, char nome[MAX_NAME], int idLocal){
    
    psimulacao auxs = s;
    ppessoa auxp , auxAnterior=NULL;
    
    while( auxs != NULL ){
        
        printf("\nLUGAR %d", auxs->l.id);
        
        auxp = auxs->listaP;
        auxAnterior = NULL; 
        while (auxp != NULL) {
           

          //  printf("\nANTERIOR> %s [%d]____", auxAnterior->identificador, auxAnterior->idade);
          //  printf("\nATUAL> %s [%d]____", auxp->identificador, auxp->idade);

            if (strcmp(auxp->identificador, nome) == 0 && auxp->local == idLocal) {
                //printf("\n\n ENTROUUUUU [%d]> %s [%d]____", auxp->local, auxp->identificador, auxp->idade);
                

                if (auxAnterior == NULL) {
                    auxs->listaP = auxp->prox;
                    
                    printf(" BAZINGA 1");
                    //printf("\nANTERIOR> %s [%d]____", auxAnterior->identificador, auxAnterior->idade);
                   // printf("\nATUAL> %s [%d]____", auxp->identificador, auxp->idade);
                } else {
                    auxAnterior->prox = auxp->prox;
                   // printf("\nANTERIOR> %s [%d]____", auxAnterior->identificador, auxAnterior->idade);
                   // printf("\nATUAL> %s [%d]____", auxp->identificador, auxp->idade);
                    printf(" BAZINGA 2");
                }
                

                //free(auxp);
                auxs->nPessoas--;
                return s;

            }

            auxAnterior = auxp;
            auxp = auxp->prox;
                    
        }
        auxs = auxs->prox; 
    }
    
   

    printf("---> Deu asneira a eliminar pessoa da lista!");
    return s;
}



int verifyLink(psimulacao s, int id) {
    psimulacao auxs = s;

    while (auxs != NULL) {
        
        for (int i = 0; i < 3; i++) {
            
            if (auxs->l.liga[i] == id) {
                printf(" --> Ligacao valida!");
                return 1;
            }
        }
        auxs = auxs->prox;
    }
    printf(" --> Sem ligacao entre salas!");
    return 0;
}


ppessoa findPerson(psimulacao s, char nome[MAX_NAME]){
    psimulacao auxs = s;
    ppessoa auxp;
    
    while( auxs != NULL ){
        
        auxp = auxs->listaP;
        while( auxp != NULL ){
           
            //printf("\nPessoa Selecionada: %s", auxp->identificador);
            if( strcmp(auxp->identificador,nome) == 0 ){
               return auxp;
            }
            
            auxp=auxp->prox;
        }
        auxs=auxs->prox;
    }
    
    
    return NULL;
}



psimulacao transferPerson(psimulacao s){
    
    char nome[MAX_NAME];
    psimulacao auxs = s;
    ppessoa nova, pess, new;
    int id;
    

    //Encontra pessoa
    do{
        printf("\n\nIndique o identificador da pessoa: ");
        scanf("%s", nome);
        pess = findPerson(s,nome);  // pess pessoa a transferir
    }while(pess==NULL);
    
   
    do{
        printf("\nIndique o id da sala para a tranferencia: ");
        scanf("%d", &id);
    }while(verifyLink(s,id) == 0);
    
    printf("\n\n> Pessoa Selecionada: %s  -> da sala %d", pess->identificador, pess->local);
    printf("\n> Sala Selecionada para Transferencia: %d", id);
   
    
     // adicionar pessoa na sala selecionada
    int x = 0;
    while (auxs != NULL && x == 0) {

        if (auxs->l.id == id) {
            x = addPessoa(auxs,pess,id);
            printf("\nADICIONOU: %s", auxs->listaP->identificador);
            auxs->nPessoas++;
            
        }

        auxs = auxs->prox;
    }
    
    
    // eliminar pessoa na lista em que estava, com id diferente da outra que adicionamos 
    s = deletePerson(s, nome,pess->local);
     
    showInfo(s);

    return s;

}



int verifyID( psimulacao s , int id){
    psimulacao aux = s;
    
        while(aux != NULL){
            if( aux->l.id == id)
                return 1;
        
        aux = aux->prox;
    }
    
        return 0;
}



void addInfected(psimulacao s){
    
    pessoa aux;
    ppessoa pAux;
    int id, idade, dias;
    char ident[MAX_NAME];
   

    do {
       
        printf("\nIndique o id da Sala: ");   
        scanf("%d", &id);
        fflush(stdin);
    } while ( verifyID(s, id) != 1);
    
    aux.estado = DOENTE; 
    
    printf("\n-->Dados da Pessoa: ");

    do {
        printf("\nInsira o identificador: ");
        scanf("%s", ident);
        fflush(stdin);
        strcpy(aux.identificador, ident);
    } while (findPerson(s, ident) != NULL);

    do {
        printf("\nInsira a idade: ");
        scanf("%d", &idade);
        fflush(stdin);
        aux.idade = idade;
    } while (idade <= 0 || idade > 100);

    do {
        printf("Insira dias de infecao: ");
        scanf("%d", &dias);
        fflush(stdin);
        aux.dias = dias;
    } while (dias <= 0);
    
    pAux = &aux;
    
  
    // encontrar e adicionar no inicio
        
    while(s != NULL){
        if(s->l.id == id){
            addPessoa(s,pAux,id);
            s->nPessoas++;
        }
        s = s->prox; 
    }
}



int countDays(psimulacao s) {
    psimulacao auxs = s;
    ppessoa auxp;
    int count = 0;

    while (auxs != NULL) {

        auxp = auxs->listaP;
        while (auxp != NULL) {

            if (auxp->estado == DOENTE)
                count += auxp->dias;
            
            auxp = auxp->prox;
        }
        auxs = auxs->prox;
    }
    
    //printf("\nDIAS: %d", count);
    return count; 
}



int countPersons (psimulacao s, char c) {
    psimulacao auxs = s;
    ppessoa auxp;
    int count=0;
    

    while (auxs != NULL) {
        
        auxp = auxs->listaP;
        while (auxp != NULL) {             

            if (auxp->estado == c){
                count++;
                //printf("\n%s - %c", auxp->identificador, auxp->estado);
            }
            auxp = auxp->prox;
        }

        auxs = auxs->prox;
    }
      
    return count; 
}


int countAllPeople( psimulacao s){
    psimulacao aux = s;
    int t=0;
    
        while(aux != NULL){
        t += aux->nPessoas;
        aux = aux->prox;
    }
    //printf("numero total de pessoas: %d", t);
    
        return t;
}



void showStatistics(psimulacao s){
    float tMortalidade=0, tRecuperacao=0, tInfetados=0, tImunidade=0, diasDoente=0;
    
    int totalp=0;
    psimulacao auxs = s;
            
    totalp = countAllPeople(s);
    
    printf("\n------- Estatisticas Gerais-------");
    printf("\nNumero total de Pessoas: %d", totalp);
    
    //Taxa de Mortalidade
    tMortalidade = (float)countPersons(s,MORTO)/ totalp ;
    printf("\nTaxa de Mortalidade: %f ", tMortalidade);    
    
    //Taxa de Recuperação 
    tRecuperacao = (float)countPersons(s,RECUPERADO) / totalp;
    printf("\nTaxa de Recuperacao: %f ", tRecuperacao );
    
    //Taxa de Imunidade 
    tImunidade = (float)countPersons(s,IMUNE) / totalp;
     printf("\nTaxa de Recuperacao: %f ", tImunidade );
    
    //Taxa de Infetados
    tInfetados = (float)countPersons(s,DOENTE) / totalp;
    printf("\nTaxa de Infetados: %f ", tInfetados);
    
    //Media de dias doente
    diasDoente =  (float)countDays(s) / countPersons(s,DOENTE);
    printf("\nMedia de dias de infecao: %f dias", diasDoente);
    
    printf("\n");
}



ppessoa infectPeople(ppessoa p, int n) {
    
   //printf("\ninfect! %d", n);

    for (int i = 0; p != NULL || i < n; i++) {
        //printf("\ninfect2!");
        
        if (p->estado == SAUDAVEL || p->estado == RECUPERADO) {

            p->estado == DOENTE;
            p->dias = (5 + (1 / p->idade));
        }
        p = p->prox;
        

    }

    return p;
}



void immunity(ppessoa p) {
// printf("\nimmunity!");
    if ( p->estado == RECUPERADO) {
       
        
        if (probEvento(0.20) == 1 )
            p->estado == IMUNE;
        else
            p->estado == SAUDAVEL;  
        
    }
}



void recovery (ppessoa p) {
       //printf("\recovery!");
     if ( p->estado == DOENTE) {
        if (probEvento(1 / p->idade) == 1)
            p->estado = RECUPERADO;
     }
}



ppessoa infectionTime(ppessoa p) {
    //printf("\ninfection Time!"); 
    if (p->estado == DOENTE) {

        if (p->dias >= 5 + (1 / p->idade)) { //se atinge a duração maxima da infecao
            p->estado = RECUPERADO;
            
        } else if (p->dias == 2 * (5 + (1 / p->idade))) 
            // ACRESCENTADO se atinge o dobro do limite maximo da infeção 
            p->estado = MORTO;

        else
            p->dias++; // + um dia com a infecao


    }
     return p;
}



int dissemination(int total){ 
    return (total * 0.05);
}



psimulacao simulationGO(psimulacao s, psimulacao b) {
    
    Iteracao++;
    printf("\n-> Iteracao %d", Iteracao);

    int count = 0, c = 0;
    psimulacao auxs = s;
    ppessoa  auxp = auxs->listaP;
   
    
    while (auxs != NULL) {  // dá a volta aos locais    
        
        auxp = auxs->listaP;
        while (auxp != NULL) { //1ªvolta nas pessoas
            
           // printf("\nBAZINGA");
            if (auxp->estado == DOENTE) {
                count = count + dissemination(auxs->nPessoas); 
                auxp = infectionTime(auxp);
                recovery(auxp); 
            }else if (auxp->estado == RECUPERADO) {   
                immunity(auxp);  
      
            }
                
            
            auxp = auxp->prox;  
        }
        auxp = infectPeople(auxp, count); //2ªvolta nas pessoas
                
        auxs = auxs->prox;       
    }
    
   // Não Funcional
   // b = loadBackup(s,b);
    
    
    printf("\n-> Iteracao %d completa!", Iteracao);
    return s;
}



void freeList(psimulacao s) {
    psimulacao aux;
    while (s != NULL) {
        aux = s;
        s = s->prox;
        free(aux);
    }
}



void saveData( psimulacao s ){
    
    FILE *f;
    char st[10];
     psimulacao auxs = s;
    ppessoa aux;
   
    
    showInfo(s);
    
    printf("\n\nNome do ficheiro para gravacao de dados:  ");
    scanf("%s", &st);
    fflush(stdin);
    
    strcat(st,".txt");
    //printf("%s",st);

    f = fopen(st, "w");
    
    if (f == NULL) {
        printf("---> Erro ao abrir o ficheiro!");
        return;
    }

        fprintf(f,"\nSIMULACAO");

        while (auxs != NULL) {
            fprintf(f, "\n--> Sala ID:%d  Capacidade:%d", s->l.id, s->l.capaciadade);

            aux = auxs->listaP;
            while (aux != NULL) {

                fprintf(f, "\n>%s[%d] _________ %c", aux->identificador, aux->idade, aux->estado);
                if (aux->estado == DOENTE)
                    fprintf(f, "(%d)", aux->dias);

                aux = aux->prox;
            }

            auxs = auxs->prox;
        }

        

    fprintf(f,"\n\n------- Estatisticas Gerais-------");
    fprintf(f,"\nNumero total de Pessoas: %d", countAllPeople(s));
    
    //Taxa de Mortalidade
    float tMortalidade = (float)countPersons(s,MORTO)/ countAllPeople(s);
    fprintf(f,"\nTaxa de Mortalidade: %f ", tMortalidade);    
    
    //Taxa de Recuperação 
    float tRecuperacao = (float)countPersons(s,RECUPERADO) / countAllPeople(s);
    fprintf(f,"\nTaxa de Recuperacao: %f ", tRecuperacao );

    //Taxa de Imunidade 
    float tImunidade = (float) countPersons(s, IMUNE) /  countAllPeople(s);
    fprintf(f,"\nTaxa de Recuperacao: %f ", tImunidade);
    
    //Taxa de Infetados
    float tInfetados = (float)countPersons(s,DOENTE) / countAllPeople(s);
    fprintf(f,"\nTaxa de Infetados: %f ", tInfetados);
    
    //Media de dias doente
    float diasDoente =  (float)countDays(s) / countAllPeople(s);
    fprintf(f,"\nMedia de dias doente: %f dias", diasDoente);
       
    fclose(f);
    

}
    



void simulationEXIT(psimulacao s){

    printf("\n\nSIMULACAO TERMINADA");
    
    //mostra info 
    showInfo(s);
    
    //guarda info em txt
    saveData(s);
    
    // liberta si 
    freeList(s);
    if(s==NULL)
        printf("--> Memoria libertada com sucesso!");
    
}
