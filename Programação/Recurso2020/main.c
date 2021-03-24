//Recurso Normal 2020
// Ana Videira - julho 2020

#include <stdio.h>
#include <stdlib.h>




typedef struct exame recurso, *precurso;

struct exame{
   char nome[100];
   int numero;
   int nota;
   precurso prox;
};

MoveMaiorNota(precurso p){
    precurso aux=p;
    precurso anterior=NULL , maior=NULL;
    int count=0; 
    int maiorNota=0; 
    
    while(aux->prox !=NULL){
        count++;
        
        if( aux->nota > maiorNota)
            maiorNota = aux->nota;
        
        anterior=aux; 
        aux=aux->prox;
    }

    if (anterior->nota > maiorNota)
        return p;
    else if (count < 2)
        return p;

    
    anterior = NULL;
    while (aux != NULL) {
        
        if (aux->nota == maiorNota){
            maior = aux;
            anterior = aux->prox;  
        }
        
        anterior=aux;
        aux=aux->prox;
    }
    aux->prox=maior;
    maior->prox=NULL;

}








typedef struct { int h,m; } Hora;
typedef struct {
    long nr_aluno;
    Hora hini,hfim; // hora de inicio e fim da sessao
    char ip[16];    // endereço IP do computador usado
} Sessao;

void processa(char *f_moodle, char *f_zoom, char *f_result) {

    FILE *fbin, *ftxt, *fresult;
    Sessao aux;
    int nAluno,hi,mi,hf,mf,ip;

    fbin = fopen(f_zoom, "rb");
    ftxt = fopen(f_moodle, "rt");
    fresult = fopen(f_result, "w");
    if (fbin == NULL || ftxt == NULL || fresult == NULL)
        return NULL;
    
    fprintf(fresult, "Informacao Alunos\n");

    while (fread(&aux, sizeof (Sessao), 1, fbin) == 1) {
        
        while(fscanf(ftxt,"%d,%d:%d,%d:%d,%d",nAluno,hi,mi,hf,mf,ip ) !=EOF){
            
            if(aux.ip = ip ){
                
                if(aux.hfim.h < hf && aux.hfim.m < mf ){
                    fprintf("\n %d - %d", ip, nAluno);
                
                }
                    
            
            }
        
        }


    }


    fclose(ftxt);
    fclose(fbin);
    fclose(fresult);

}


int ordenado(int  &a, int tam){
    if(tam <=  )
        return 1;
    else if(  > a[1])
        return  0 ;
    else
        return ordenado( Em branco ,  Em branco );
}
