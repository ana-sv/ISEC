// Ana Videira - junho 2019
// Exame Normal (2/7/2018) - exercicio 1 


/*
 a) Desenvolva uma função em C que apresente na consola a informação completa das tarefas cujo
identificador esteja compreendido entre 2 limites. Deve devolver o número total de tarefas
armazenadas no ficheiro e o preço da tarefa de menor custo que foi apresentada na consola. A
função recebe como parâmetros o nome do ficheiro binário onde estão armazenadas as tarefas e
os limites a considerar para o identificador.
 
 */


#include <stdio.h>
#include <stdlib.h>


typedef struct tarefa{
    int id;
    char designacao[100];
    float preco;
} Tarefa;

// a ///////////////////////////////////////////////////////////////////////////
float infoTarefa(char *nomeFich, int limS, int limI, int *total){

    Tarefa aux;
    float preco = 1000;

    printf("\n\n1\n\n");
    FILE *f;
    f = fopen(nomeFich, "rb");

    if (f == NULL) {
        printf("\nErro ao abrir o ficheiro %s !\n", nomeFich);
        return 0;
    }

    printf("\n\n2\n\n");

    while ( fread(&aux, sizeof (Tarefa), 1, f) == 1) {

        if (aux.id < limS && aux.id > limI) {
            
            printf("\n\n3\n\n");
            printf("id: %d", aux.id);

            if (aux.preco < preco)
                preco = aux.preco;

        }
        (*total)++;

    }

    
    fclose(f); 
    return preco;   

}












int main(int argc, char** argv) {
    

    int total=0;
    float p;
    
     p = infoTarefa("tarefas.dat", 20, 2, &total);
     
    printf("\nTotal structs Tarefa: %d\n", total );
    printf("\nMenor Preco: %.0f\n\n", p );
     

    
    
    
    
    return (EXIT_SUCCESS);
}

