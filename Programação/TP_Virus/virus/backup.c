// Trabalho Pratico Programacao - LEI-CE
// DEIS-ISEC 2019-2020
// Ana Rita Santos Videira | 2015012218 | a21250074@isec.pt

#include "func.h"


psimulacao goBack(psimulacao s, psimulacao b) {
   //printf("\n>>>> ENTROU EM GOBACK\n");


    int op=0;
    psimulacao aux;

    /*    
   do{
        printf("Quantas iteracoes pretende reverter?");
        scanf("%d",&op);    
        fflush(stdin);
        
    }while(op>=MAX_BACK && op<0);
    
    
    int i=0;
    while( aux != NULL && i<op ){
        aux = aux->prox;
        i++;
    }
            */
    

    //  s = aux;
    
     // Iteracao = Iteracao - op;
    
     
             
    return s;

}



psimulacao  loadBackup( psimulacao s, psimulacao b ){
   
    psimulacao novo = b , auxs = s;
    ppessoa auxn, auxp;

    while (auxs != NULL) {
        
        printf("\n>>>> 1\n");
        
        novo = malloc(sizeof (psimulacao));
        if (novo == NULL) return 0;

    }

    showInfo(b);
    return b;
}






/*
pbackup  loadBackup( psimulacao s, pbackup b ){
    
   pbackup novo = b;
   
     
   psimulacao auxs = s;
   ppessoa auxp = s->listaP;

  
   
    for (int i = 0; i < MAX_BACK; i++) {
        printf(">> BAZINGA1");
        
        novo = malloc(sizeof (pbackup));
        if (novo == NULL) return 0;
        
        printf(">> BAZINGA2");
        
        addLocal(novo->back,auxs->l);

        
              printf(">> BAZINGA3");
       
        auxp = s->listaP;
       
        while( auxp != NULL ){
            
            
            printf("> BAZINGA4 PESSOAS");
 
            addPessoa(novo->back,auxp,novo->back->l.id);
                    
      
                 
        }
        printf(">> BAZINGA7");
        novo->iter = Iteracao;
        
   
        printf(">> BAZINGA8");
        auxs = auxs->prox;

          
    }

    printf("\n---> iteracao guardada com sucesso! ");

   return b;



}*/