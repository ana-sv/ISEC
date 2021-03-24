// Exame Normal 2020 - Pergunta 3 - NAO TESTADA
// Ana Videira - julho 2020

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Uma empresa de transportes armazena num ficheiro binário informação sobre os 
 * vários trajetos que efetua. Os dados de cada trajeto são guardados em estruturas
 *  do tipo dados, indicando o local de origem, o local de destino e o tempo em
 *  minutos que demora a efetuar este trajeto. Pode assumir que os locais de origem
 *  e de destino são constituídos apenas por uma palavra. Além disso, um ficheiro 
 * de texto tem armazenados vários locais (um local em cada linha). Escreva uma
 *  função que crie um vetor dinâmico de estruturas do tipo dados, para onde
 *  devem ser copiadas todas as estruturas do ficheiro que não têm como origem
 *  um local que surja no ficheiro de texto. A função tem o seguinte protótipo:
 *      dados* criaVetor(char* nomeB, char* nomeF, int *total);
 * 
 * Recebe como parâmetros os nomes dos ficheiros e o endereço de uma variável
 *  inteira onde deve colocar o tamanho do vetor criado. Devolve o endereço inicial
 *  do vetor dinâmico. Se ocorrer algum erro, deve devolver NULL.
 * 
 * Ao responder a esta questão, não deve assumir que a ordem pela qual a 
 * informação surge nos 2 ficheiros é igual. Além disso, podem surgir locais no
 *  ficheiro de texto que não se encontram nas estruturas do ficheiro binário.
 */


typedef struct trajeto dados;
struct trajeto{
    char origem[200];      // Origem (1 palavra apenas)
    char destino[200];    // Destino (1 palavra apenas)
    int minutos;         // Número de minutos que demora a fazer a ligação
};

// Notas:
// criar vetor dinamicoo do tipo dados
// ficheiro binario com " dados"
// ficheiro txt com 1 local por linha
// se o local em dados nao estiver no ficheiro txt, adicionar-lo no txt


dados* criaVetor(char* nomeB, char* nomeF, int *total){
   
    int t=0;
    dados aux, *auxv;
    char word[200];

    // declara vetor dinamico
    dados *vector = NULL;

    // abre os ficheiros 
    FILE *fbin, *ftxt;
    fbin = fopen(nomeB, "rb");
    ftxt = fopen(nomeF, "rwt");
    if (fbin == NULL || ftxt == NULL)
        return NULL;

    // abre ciclo enquanto há dados para ler bin
    while (fread(&aux, sizeof (dados), 1, fbin) == 1) {


        // procurar  local no txt
        while (fscanf(ftxt, "%s", word) != EOF) {
            
            if (strcmp(word, aux.destino) == 0)
                printf("Found\n");
            
            else {               

                // aloca memoria 
                if (t == 0) {
                    vector = malloc(sizeof (dados));
                } else {
                    auxv = realloc(vector, sizeof (dados)*(t + 1))
                            vector = auxv;
                }
                // copia estrutura lida para memoria dinamica    
                vector[t] = aux;
                t++;
                
                
                // adiciona local no final do txt - FALTA
                
                

            }
        }


    }


    // fecha ficheiros 
    fclose(fbin);
    fclose(ftxt);

    *total = t;
     return vector;

}